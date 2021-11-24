#include "so_long.h"

int ft_strlen(char *str) // counting amount of characters in the string
{
	int i;

	i = 0;
	while (str != NULL && str[i]) // if string is NULL (only in the beginning of the mapcopier function) there should not be any iteration
		i++;
	return (i); // returning number of characters counted in the string
}

void ft_error(int error_code, char *hold) // if something went wrong, this function will give an error and exits the program
{
	write(1, "\n        >>> Failed to run program <<<\n", 39); // error message printed to stdout
	if (error_code == 0)
		write(1, "an error occurred while trying to open map.ber\n\n", 48);
	if (error_code == 1)
		write(1, "please, make sure the map is surrounded by walls\n\n", 50);
	else if (error_code == 2)
		write(1, "please, make sure the elements given are valid according the rules of the map\n\n", 79);
	else if (error_code == 3)
		write(1, "please, make sure the map is rectangular\n\n", 42);
	else if (error_code == 4)
	{
		if (ft_strlen(hold)) // check if hold has memory allocated
			free(hold); // if so, hold is freed
		write(1, "an error occured while allocating memory\n\n", 42);
	}
	exit(0); // exits program
}

void	ft_chrchecker(char c, t_map *info) // checks to see if the character is valid or not
{ 
	if (c == 'E' || c == 'P' || c == 'C' || c == '1' || c == '0' || c == '\n') // check to see if there is not an invalid character found
	{
		if (c == 'E') // check to see if it is a limited character or if its just a 0 or 1 element
			info->e += 1; // if so, its set to 1 more to keep track of the amount of "special" elements in the map
		else if (c == 'P')
			info->p += 1;
		else if (c == 'C')
			info->c += 1;
	}
	else
		ft_error(2, NULL); // if there is any character which is invalid, the program exits
}

int ft_upbotcheck(char *map, int arg, t_map *info, int i)
{
	if (arg == 1) // upper wall
	{
		while (map[i] != '\n') // as long as the end of the line is not reached (no new line character)
		{
			if (map[i] != '1') // checks if the whole upper line is filled with ones
				ft_error(1, NULL); // if not, goes to error function
			i++; // to the next char to check
		}
	}
	else // lower wall and check for too many/less chars
	{
		i--;
		while (map[i] != '\n') // stops when beginning of the bottom line is reached
		{
			if (map[i] != '1') // checks if the bottom line is only made of ones	
				ft_error(1, NULL); // if not, program ends
			i--;
		}
		if (info->e != 1 || info->p != 1 || info->c < 1) // check if the chars given is valid, not too many or too less of each (min/max 1x E, min/max 1x P, min 1x C)
			ft_error(2, NULL); // if not, program ends
	}
	return (i); // returns i, only used for case 1 so it can iterate from where it lasted
}

void ft_mapchecker(char *map, t_map *info) // checks to see if the given map is valid or not
{
	int i; // iterator
	int length; // to hold the value of the length of the first line
	int l_check; // to check if the next lines are the same length as the first one

	i = ft_upbotcheck(map, 1, info, 0); // function which checks if the first line one exits from ones (1), terurns the location of the first new line
	length = i; // gets the value of the amount of bytes of the first line
	l_check = i; // gets the value of the amount of bytes of the first line because this is already checked and has no difference
	while (map[i]) // as long as map doesn't reaches the end of the string
	{
		ft_chrchecker(map[i], info); // checks if the char is a valid character
		if (map[i] == '\n') // if the char is a new line
		{
			if (map[i - 1] != '1' || map[i + 1] != '1') // checks if the outer bytes are 1s
				ft_error(1, NULL); // if not, exits program
			if (l_check != length) // checks if the lenght of the line read is the same as the fist line
				ft_error(3, NULL); // if not, exits program
			l_check = -1; // resets the length check so the next line can be checked on its length, -1 to skip the new line during the counting
		}
		l_check++; // iterates throughout the line its length
		i++; // iterates through the whole string till end is reached
	}
	if (l_check != length) // bottom line check for good length,  is skipped in loop beceause last char is \0 instead op \n
		ft_error(1, NULL); // if not, exits program
	ft_upbotcheck(map, 2, info, i); // last check for the bottom line walls and amount of valid chars
}

char *ft_filler(char *hold, char *buff) // fucntion to fill the string with the buff read from map.ber
{
	char *result; // this will get the whole string at the end
	int i; // iterator

	i = 0; // start from the first address in the string 
	result = (char *)malloc(ft_strlen(hold) + 2); // allocates enough memory for the bytes in hold, buff and a null terminator
	if (!result) // if something went wrong while allocating memory
		ft_error(4, hold); // the program will exit
	while (hold != NULL && hold[i]) // as long as the string lasts
	{
		result[i] = hold[i]; // hold is copied in result
		i++; // keeps track of the bytes to copy
	}
	result[i] = buff[0]; // byte of buff will be copied at the end
	result[i + 1] = '\0'; // null terminated
	free(hold); // hold will be freed, because this memory is not needed anymore
	return (result); // result will be returned with the new line
}

void ft_init(t_map *info)
{
	info->e = 0; // setting all the values to zero, because there are no such characters found yet
	info->p = 0;
	info->c = 0;
}

char *ft_mapcopier(void)
{
	int ret; // return value to check for EOF
	char buff[2]; // buffer to save read byte in
	char *hold; // to save the map in as string, will get allocated memory

	t_map info; // making a structure called info to save the values of the counted valid characters
	ft_init(&info); // sets all structure values to 0, will set to occurence of elements later
	hold = NULL; // hold is set to NULL to skip copying with no value later on
	int fd = open("map.ber", O_RDONLY); // openening map.ber to read from, fd is the file descriptor of this file
	if (fd < 0) // check for invalid file descriptor
		ft_error(0, NULL); // error function
	ret = read(fd, buff, 1); // read one byte from the file descriptor
	if (ret < 1) // check for an empty given file, had no content but will still gets in the ft_mapchecker function because ret = 0
		ft_error(4, hold); // if file is empty, program exits
	while (ret > 0) // as long as there is something to read from it stays in the loop
	{
		buff[1] = '\0'; // null terminate the buff (so only the one byte will be read)
		hold = ft_filler(hold, buff); // in the function hold is freed en gets the new string
		ret = read(fd, buff, 1); // reads the next byte, saved in buff. ret value gives 1 for byte read, 0 for EOF, -1 for error
		if (ret == -1) // checks if read had an error
			ft_error(4, hold); // if so, programs exits
	}
	ft_mapchecker(hold, &info); // function in function in ... to check if the copied map is valid, returns to this function if so
	return (hold); // returns valid map
}

int main(void)
{
	char *map; // to save map in after copy and checks

	map = ft_mapcopier(); // start of copying and checking for valid map
	printf("\n%s\n\n", map); // prints map, check to see if it is correctly copied
	return (0);
}