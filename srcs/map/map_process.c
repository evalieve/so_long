#include "so_long.h"

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

int ft_upbotcheck(char *map, int arg, t_map *info, int i) // checks the upper line if there are only ones, as well as the bottom line
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
	int width; // to hold the value of the width of the first line
	int w_check; // to check if the next lines are the same width as the first one

	i = ft_upbotcheck(map, 1, info, 0); // function which checks if the first line one exits from ones (1), terurns the location of the first new line
	width = i; // gets the value of the amount of bytes of the first line
	w_check = i; // gets the value of the amount of bytes of the first line because this is already checked and has no difference
	while (map[i]) // as long as map doesn't reaches the end of the string
	{
		ft_chrchecker(map[i], info); // checks if the char is a valid character
		if (map[i] == '\n') // if the char is a new line
		{
			if (map[i - 1] != '1' || map[i + 1] != '1') // checks if the outer bytes are 1s
				ft_error(1, NULL); // if not, exits program
			if (w_check != width) // checks if the lenght of the line read is the same as the fist line
				ft_error(3, NULL); // if not, exits program
			w_check = -1; // resets the width check so the next line can be checked on its width, -1 to skip the new line during the counting
		}
		w_check++; // iterates throughout the line its width
		i++; // iterates through the whole string till end is reached
	}
	if (w_check != width) // bottom line check for good width,  is skipped in loop beceause last char is \0 instead op \n
		ft_error(1, NULL); // if not, exits program
	ft_upbotcheck(map, 2, info, i); // last check for the bottom line walls and amount of valid chars
	info->width = width;
}

char *ft_filler(char *hold, char *buff) // fucntion to fill the string with the buff read from map.ber
{
	char *result; // this will get the whole string at the end
	int i; // iterator

	i = 0; // start from the first address in the string 
	result = (char *)malloc(ft_strlen(hold, '\0') + 2); // allocates enough memory for the bytes in hold, buff and a null terminator
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

char *ft_mapcopier(t_map *info)
{
	int ret; // return value to check for EOF
	char buff[2]; // buffer to save read byte in
	char *hold; // to save the map in as string, will get allocated memory

	ft_init(info); // sets all structure values to 0, will set to occurence of elements later
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
	ft_mapchecker(hold, info); // function in function in ... to check if the copied map is valid, returns to this function if so
	info->length = ft_strlen(hold, '\n') / info->width;
	printf("length = %d, width = %d\n", info->length, info->width);
	return (hold); // returns valid map
}