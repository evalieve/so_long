#include "../../so_long.h"

int key_hook (int keycode, t_win *win)
{
	if (keycode)
		printf("Jaha\n");
	return(0);
}

void player_render(t_win *win, t_map *map)
{


	char *relative_path = "./../../../sprites/player/player_idle_f1.xpm";
	... = mlx_xpm_file_to_image(win->mlx, relative_path, &img_width, &img_height);
	... = mlx_get_data_addr(...img, &...bits_per_pixel, &...line_length, &...endian);
	mlx_put_image_to_window(win->mlx, win->mlx_win, ...img, loc x, loc y);

	mlx_key_hook(win->mlx_win, key_hook, &win);
	return ;
}