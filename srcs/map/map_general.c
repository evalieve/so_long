#include "so_long.h"

void ft_error(char *message) // if something went wrong, this function will give an error and exits the program
{
	write(1, "\n>>> Failed to run program <<<\n", 31);
	write(1, message, ft_strlen(message, '\0')); // error message printed to stdout
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