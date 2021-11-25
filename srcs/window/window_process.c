#include "so_long.h"

// int ft_lendigit(int digit)
// {
// 	int length;

// 	length = 0;
// 	while (digit > 0)
// 	{
// 		digit = digit / 10;
// 		length++;
// 	}
// 	return (length);
// }

void ft_winfix(t_map *info)
{
	info->length = 65 * info->length;
	info->width = 65 * info->width;
}

void ft_window_manager(t_map *info)
{
	void *mlx;
	void *mlx_win;


	//ft_winfix(info);
	printf("length = %d, width = %d\n", info->length, info->width);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, info->width * 64, info->length * 64, "so_long");
	mlx_loop(mlx);
}