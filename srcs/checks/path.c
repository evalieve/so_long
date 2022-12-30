/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 14:14:19 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/28 14:14:50 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	pos_check(int row, int pos, t_data *data)
{
	if (data->path.map_copy[row][pos] == '0' || \
		data->path.map_copy[row][pos] == 'C')
	{
		if (data->path.map_copy[row][pos] == 'C')
			data->path.count_c += 1;
		path_check(row, pos, data);
	}
	else if (data->path.map_copy[row][pos] == 'E')
	{
		data->path.count_e += 1;
		data->path.map_copy[row][pos] = 'v';
	}
}

void	path_check(int row, int pos, t_data *data)
{
	data->path.map_copy[row][pos] = 'v';
	pos_check(row - 1, pos, data);
	pos_check(row + 1, pos, data);
	pos_check(row, pos - 1, data);
	pos_check(row, pos + 1, data);
}
