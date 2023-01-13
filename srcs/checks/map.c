/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 14:15:03 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/13 15:33:56 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	elements(t_data *data)
{
	if (data->map.player != 1)
	{
		if (data->map.player > 1)
			fatal(1, "Found too many player components", "(P)");
		if (data->map.player < 1)
			fatal(1, "No player component found", "(P)");
	}
	if (data->map.end != 1)
	{
		if (data->map.end > 1)
			fatal(1, "Found too many end components", "(E)");
		if (data->map.end < 1)
			fatal(1, "No end component found", "(E)");
	}
	if (data->map.collectible == 0)
		fatal(1, "No collectible component found", "(C)");
}

void	element_check(t_data *data, char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == '\n')
	{
		if (c == 'P')
			data->map.player += 1;
		if (c == 'E')
			data->map.end += 1;
		if (c == 'C')
			data->map.collectible += 1;
	}
	else
		fatal(1, "Invalid element in map", "(only 0, 1, P, C, E allowed)");
}

int	midlines(t_data *data, int p)
{
	int	count;

	count = p;
	while (data->map.temp_map[p])
	{
		element_check(data, data->map.temp_map[p]);
		if (data->map.temp_map[p] == '\n')
		{
			if (data->map.temp_map[p - 1] != '1' \
				|| data->map.temp_map[p + 1] != '1')
				fatal(1, "Map is not surrounded by walls", "(1)");
			if (count != data->map.width)
				fatal(1, "Map is not rectangular", \
					"(lines must be the same length");
			count = -1;
			data->map.rows += 1;
		}
		count++;
		p++;
	}
	if (count != data->map.width)
		fatal(1, "Map is not rectangular", "(lines must be the same length)");
	data->map.rows += 1;
	return (p);
}

int	up_botline(t_data *data, char c, int pos)
{
	while (data->map.temp_map[pos] != c)
	{
		if (data->map.temp_map[pos] != '1')
			fatal(1, "Map is not surrounded by walls", "(1)");
		pos++;
	}
	return (pos);
}

void	wall_check(t_data *data)
{
	int	p;

	data->map.width = ft_strlen_c(data->map.temp_map, '\n');
	up_botline(data, '\n', 0);
	p = midlines(data, data->map.width);
	p -= data->map.width;
	up_botline(data, '\0', p);
}
