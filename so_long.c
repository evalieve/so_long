#include "so_long.h"

int main(void)
{
	char *map; // to save map in after copy and checks

	t_map info; // making a structure called info to save the values of the counted valid characters and length/width of map
	map = ft_mapcopier(&info); // start of copying and checking for valid map
	printf("\n%s\n\n", map); // prints map, check to see if it is correctly copied
	ft_window_manager(&info);
	return (0);
}