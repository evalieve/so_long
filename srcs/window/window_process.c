#include "../../so_long.h"
void ft_imageput()
{
	// to put the imaage in place, for less lines in other functions
}


void ft_fill_background(void *mlx, void *mlx_win, t_map info, void *img)
{
	// >>>>>>>>>>>>>> background water

	int width;
	int height;

	t_data way;
	// t_data corner;
	// t_data player;

	width = info.width * 64 - 64;
	
	height = info.length * 64 - 64;
	while (width >= 0)
	{
		while (height >= 0)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, width, height);
			height -= 64;
		}
		width -= 64;
		height = info.length * 64 - 64;
	}

	// <<<<<<<<<<<<<<

	int i;
	int img_width;
	int img_height;

	i = ft_strlen(info.map, '\0') - 1;
	height = info.length * 64 - 64;
	width = info.width * 64 - 64;
	char *relative_path = "sprites/background/grass_full.xpm";
	way.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	way.addr = mlx_get_data_addr(way.img, &way.bits_per_pixel, &way.line_length, &way.endian);
	while (height >= 0)
	{
		while (width >= 0)
		{
			if (info.map[i] != '1' && info.map[i] != '\n')
					mlx_put_image_to_window(mlx, mlx_win, way.img, width, height);
			width -= 64;
			i--;
		}
		height -= 64;
		width = info.width * 64 - 64;
		i--;
	}
}
void ft_window_manager(t_map *info)
{
	// tile = 64x64, so window length/width * 64 for window size!

	t_win mlx;
	t_data background;
	int img_width;
	int img_height;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 64 * info->width, 64 * info->length, "so_long");

	char *relative_path = "sprites/background/water_full.xpm";
	background.img = mlx_xpm_file_to_image(mlx.mlx, relative_path, &img_width, &img_height);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	ft_fill_background(mlx.mlx, mlx.mlx_win, *info, background.img);

	player_render(&mlx);

	mlx_loop(mlx.mlx);
}