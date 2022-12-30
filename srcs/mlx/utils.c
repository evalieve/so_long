/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 19:32:27 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/28 15:41:43 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	set_depth_instance(t_data *data)
{
	while (data->bckgrnd_inst >= 0)
	{
		mlx_set_instance_depth(&data->img.background->\
			instances[data->bckgrnd_inst], 4);
		data->bckgrnd_inst--;
	}
	while (data->walls_inst >= 0)
	{
		mlx_set_instance_depth(&data->img.wall->\
			instances[data->walls_inst], 8);
		data->walls_inst--;
	}
	while (data->collect_inst >= 0)
	{
		mlx_set_instance_depth(&data->img.collectible->\
			instances[data->collect_inst], 6);
		data->collect_inst--;
	}
}

void	player_depth(t_data *data, int left, int right, int back)
{
	if (back != 3 && left != 3 && right != 3)
		mlx_set_instance_depth(&data->img.player_f->instances[0], 3);
	else
		mlx_set_instance_depth(&data->img.player_f->instances[0], 5);
	mlx_set_instance_depth(&data->img.player_l->instances[0], left);
	mlx_set_instance_depth(&data->img.player_r->instances[0], right);
	mlx_set_instance_depth(&data->img.player_b->instances[0], back);
}

// deze functie nalopen of ik alles erin heb
void	free_all(t_data *data)
{
	mlx_delete_image(data->mlx, data->img.wall);
	mlx_delete_image(data->mlx, data->img.background);
	mlx_delete_image(data->mlx, data->img.collectible);
	mlx_delete_image(data->mlx, data->img.player_l);
	mlx_delete_image(data->mlx, data->img.player_f);
	mlx_delete_image(data->mlx, data->img.player_b);
	mlx_delete_image(data->mlx, data->img.player_r);
	mlx_delete_image(data->mlx, data->img.end);
	mlx_delete_xpm42(data->xpm.wall);
	mlx_delete_xpm42(data->xpm.background);
	mlx_delete_xpm42(data->xpm.collectible);
	mlx_delete_xpm42(data->xpm.player_l);
	mlx_delete_xpm42(data->xpm.player_f);
	mlx_delete_xpm42(data->xpm.player_b);
	mlx_delete_xpm42(data->xpm.player_r);
	mlx_delete_xpm42(data->xpm.end);
	free(data->map.map);
}
