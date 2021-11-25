#include "so_long.h"

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
		if (ft_strlen(hold, '\0')) // check if hold has memory allocated
			free(hold); // if so, hold is freed
		write(1, "an error occured while allocating memory\n\n", 42);
	}
	exit(0); // exits program
}

int ft_strlen(char *str, char skip) // counting amount of characters in the string
{
	int length;
	int i;

	length = 0;
	i = 0;
	while (str != NULL && str[i]) // if string is NULL (only in the beginning of the mapcopier function) there should not be any iteration
	{
		if (str[i] == skip)
			length--;
		length++;
		i++;
	}
	return (length); // returning number of characters counted in the string
}

void ft_init(t_map *info)
{
	info->e = 0; // setting all the values to zero, because there are no such characters found yet
	info->p = 0;
	info->c = 0;
	info->width = 0;
}