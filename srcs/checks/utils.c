/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 14:13:51 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/28 15:38:11 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	set_data(t_data *data)
{
	data->map.player = 0;
	data->map.end = 0;
	data->map.collectible = 0;
	data->map.rows = 0;
	data->path.count_c = 0;
	data->path.count_e = 0;
	data->count = 0;
	data->bckgrnd_inst = 0;
	data->collect_inst = 0;
	data->walls_inst = 0;
}
