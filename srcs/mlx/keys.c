/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 19:32:39 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/09 19:10:28 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	player_instance(t_data *data, int rows, int width, int num)
{
	data->img.player_l->instances->x = width * 64;
	data->img.player_l->instances->y = rows * 64;
	data->img.player_r->instances->x = width * 64;
	data->img.player_r->instances->y = rows * 64;
	data->img.player_b->instances->x = width * 64;
	data->img.player_b->instances->y = rows * 64;
	data->img.player_f->instances->x = width * 64;
	data->img.player_f->instances->y = rows * 64;
	if (num == 3)
		player_depth(data, 1, 2, 3);
	else if (num == 2)
		player_depth(data, 5, 1, 2);
	else if (num == 1)
		player_depth(data, 1, 2, 5);
	else
		player_depth(data, 1, 5, 2);
	data->count++;
	ft_putstr_fd(ft_itoa(data->count), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

int	check_end_wall(t_data *data, int rows, int width)
{
	if (data->map.map[rows][width] == 'E' || data->map.map[rows][width] == '1')
	{
		if (data->map.map[rows][width] == 'E' && data->map.collectible == 0)
		{
			free_all(data);
			mlx_close_window(data->mlx);
		}
		return (1);
	}
	return (0);
}

int	key_action(t_data *data, int num, int rows, int width)
{
	int	i;

	i = 0;
	if (check_end_wall(data, rows, width) == 1)
		return (0);
	if (data->map.map[rows][width] == 'C')
	{
		data->map.map[rows][width] = '0';
		while (i < data->path.count_c)
		{
			if (data->img.collectible->instances[i].x == width * \
				64 && data->img.collectible->instances[i].y == rows * 64)
			{
				printf("wassup chocomel zonder k\n");
				data->map.collectible--;
				mlx_set_instance_depth(&data->img.collectible->instances[i], 0);
				break ;
			}
			i++;
		}
	}
	player_instance(data, rows, width, num);
	return (1);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		if (key_action(data, 1, data->path.pos[0] - 1, data->path.pos[1]) == 1)
			data->path.pos[0]--;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		if (key_action(data, 2, data->path.pos[0], data->path.pos[1] - 1) == 1)
			data->path.pos[1]--;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		if (key_action(data, 3, data->path.pos[0] + 1, data->path.pos[1]) == 1)
			data->path.pos[0]++;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		if (key_action(data, 4, data->path.pos[0], data->path.pos[1] + 1) == 1)
			data->path.pos[1]++;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(data->mlx);
		free_all(data);
	}
}
