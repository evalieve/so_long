/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_render.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 19:32:34 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/13 15:38:33 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	player_back(t_data *data)
{
	data->xpm.player_b = mlx_load_xpm42("./sprites/player/player_B.xpm42");
	if (!data->xpm.player_b)
		fatal(1, "Failed to load xpm file", "(backview player)");
	data->img.player_b = mlx_texture_to_image(data->mlx, \
		&data->xpm.player_b->texture);
	if (!data->img.player_b)
		fatal(1, "Failed to convert texture to image", "(mlx error)");
	if (mlx_image_to_window(data->mlx, data->img.player_b, data->path.pos[1] \
		* 64, data->path.pos[0] * 64) < 0)
		fatal(1, "Failed to put image to window", "(mlx error)");
	mlx_set_instance_depth(data->img.player_b->instances, 1);
}

void	player_right(t_data *data)
{
	data->xpm.player_r = mlx_load_xpm42("./sprites/player/player_R.xpm42");
	if (!data->xpm.player_r)
		fatal(1, "Failed to load xpm file", "(right sideview player)");
	data->img.player_r = mlx_texture_to_image(data->mlx, \
		&data->xpm.player_r->texture);
	if (!data->img.player_r)
		fatal(1, "Failed to convert texture to image", "(mlx error)");
	if (mlx_image_to_window(data->mlx, data->img.player_r, data->path.pos[1] \
		* 64, data->path.pos[0] * 64) < 0)
		fatal(1, "Failed to put image to window", "(mlx error)");
	mlx_set_instance_depth(data->img.player_r->instances, 2);
}

void	player_left(t_data *data)
{
	data->xpm.player_l = mlx_load_xpm42("./sprites/player/player_L.xpm42");
	if (!data->xpm.player_l)
		fatal(1, "Failed to load xpm file", "(left sideview player)");
	data->img.player_l = mlx_texture_to_image(data->mlx, \
		&data->xpm.player_l->texture);
	if (!data->img.player_l)
		fatal(1, "Failed to convert texture to image", "(mlx error)");
	if (mlx_image_to_window(data->mlx, data->img.player_l, data->path.pos[1] \
		* 64, data->path.pos[0] * 64) < 0)
		fatal(1, "Failed to put image to window", "(mlx error)");
	mlx_set_instance_depth(data->img.player_l->instances, 3);
}

void	player_front(t_data *data)
{
	data->xpm.player_f = mlx_load_xpm42("./sprites/player/player_F.xpm42");
	if (!data->xpm.player_f)
		fatal(1, "Failed to load xpm file", "(frontview player)");
	data->img.player_f = mlx_texture_to_image(data->mlx, \
		&data->xpm.player_f->texture);
	if (!data->img.player_f)
		fatal(1, "Failed to convert texture to image", "(mlx error)");
	if (mlx_image_to_window(data->mlx, data->img.player_f, data->path.pos[1] \
		* 64, data->path.pos[0] * 64) < 0)
		fatal(1, "Failed to put image to window", "(mlx error)");
	mlx_set_instance_depth(data->img.player_f->instances, 5);
}

void	player(t_data *data)
{
	player_front(data);
	player_left(data);
	player_right(data);
	player_back(data);
}
