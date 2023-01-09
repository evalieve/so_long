/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 15:02:57 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/09 18:54:22 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**map_fill(char **map, t_data *data)
{
	int	row;
	int	pos;
	int	i;

	row = 0;
	pos = 0;
	i = 0;
	while (map[row])
	{
		while (pos < data->map.width)
		{
			if (data->map.temp_map[i] == 'P')
			{
				data->path.pos[0] = row;
				data->path.pos[1] = pos;
			}
			map[row][pos] = data->map.temp_map[i];
			i++;
			pos++;
		}
		pos = 0;
		row++;
		i++;
	}
	return (map);
}

char	**map_convert(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc((data->map.rows + 1) * sizeof(char *));
	if (!map)
		ft_perror(1);
	map[data->map.rows] = NULL;
	while (i < data->map.rows)
	{
		map[i] = (char *)malloc((data->map.width + 1) * sizeof(char));
		if (!map[i])
			ft_perror(1);
		map[i][data->map.width] = '\0';
		i++;
	}
	map_fill(map, data);
	return (map);
}
