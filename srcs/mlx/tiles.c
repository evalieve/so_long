/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tiles.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 19:32:22 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/09 19:13:36 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	end(t_data *data, int width, int height)
{
	data->xpm.end = mlx_load_xpm42("./sprites/end/end.xpm42");
	if (!data->xpm.end)
		fatal(1, "Failure load xpm end", "(end xpm)");
	data->img.end = mlx_texture_to_image(data->mlx, \
		&data->xpm.end->texture);
	if (!data->img.end)
		fatal(1, "Failure mlx texture to image", "(mlx error)");
	while (height * 64 <= data->map.rows * 64 - 64)
	{
		while (width * 64 <= data->map.width * 64 - 64)
		{
			if (data->map.map[height][width] == 'E')
			{
				if (mlx_image_to_window(data->mlx, data->img.end, \
					width * 64, height * 64) < 0)
					fatal(1, "Failure mlx img to window", "(mlx error)");
			}
			width++;
		}
		width = 0;
		height++;
	}
	mlx_set_instance_depth(&data->img.end->instances[0], 7);
}

void	collectible(t_data *data, int width, int height)
{
	data->xpm.collectible = mlx_load_xpm42("./sprites/collect/collect.xpm42");
	if (!data->xpm.collectible)
		fatal(1, "Failure load xpm end", "(collectible xpm)");
	data->img.collectible = mlx_texture_to_image(data->mlx, \
		&data->xpm.collectible->texture);
	if (!data->img.collectible)
		fatal(1, "Failure mlx texture to image", "(mlx error)");
	while (height * 64 <= data->map.rows * 64 - 64)
	{
		while (width * 64 <= data->map.width * 64 - 64)
		{
			if (data->map.map[height][width] == 'C')
			{
				data->collect_inst++;
				if (mlx_image_to_window(data->mlx, data->img.collectible, \
					width * 64, height * 64) < 0)
					fatal(1, "Failure mlx img to window", "(mlx error)");
			}
			width++;
		}
		width = 0;
		height++;
	}
}

void	walls(t_data *data, int width, int height)
{
	data->xpm.wall = mlx_load_xpm42("./sprites/tiles/wall.xpm42");
	if (!data->xpm.wall)
		fatal(1, "Failure load xpm end", "(wall xpm)");
	data->img.wall = mlx_texture_to_image(data->mlx, &data->xpm.wall->texture);
	if (!data->img.wall)
		fatal(1, "Failure mlx texture to image", "(mlx error)");
	while (height * 64 <= data->map.rows * 64 - 64)
	{
		while (width * 64 <= data->map.width * 64 - 64)
		{
			if (data->map.map[height][width] == '1')
			{
				data->walls_inst++;
				if (mlx_image_to_window(data->mlx, data->img.wall, \
					width * 64, height * 64) < 0)
					fatal(1, "Failure mlx img to window", "(mlx error)");
			}
			width++;
		}
		width = 0;
		height++;
	}
}

void	background(t_data *data, int width, int height)
{
	data->xpm.background = mlx_load_xpm42("./sprites/tiles/bckgrnd.xpm42");
	if (!data->xpm.background)
		fatal(1, "Failure load xpm end", "(background xpm)");
	data->img.background = mlx_texture_to_image(data->mlx, \
		&data->xpm.background->texture);
	if (!data->img.background)
		fatal(1, "Failure mlx texture to image", "(mlx error)");
	while (height * 64 <= data->map.rows * 64 - 64)
	{
		while (width * 64 <= data->map.width * 64 - 64)
		{
			data->bckgrnd_inst++;
			if (mlx_image_to_window(data->mlx, data->img.background, \
			width * 64, height * 64) < 0)
				fatal(1, "Failure mlx img to window", "(mlx error)");
			width++;
		}
		width = 0;
		height++;
	}
}
