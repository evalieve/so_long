/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/23 19:32:14 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/13 15:31:32 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	so_long(char *file)
{
	t_data	data;

	set_data(&data);
	file_handle(&data, file);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data.mlx = mlx_init(data.map.width * 64, data.map.rows * 64, \
		"so_long", true);
	if (!data.mlx)
		fatal(1, "Failed to initialize mlx", "(mlx error)");
	background(&data, 0, 0);
	walls(&data, 0, 0);
	player(&data);
	collectible(&data, 0, 0);
	end(&data, 0, 0);
	set_depth_instance(&data);
	mlx_key_hook(data.mlx, &my_keyhook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
