/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 14:09:58 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/09 16:30:58 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*buff_copy(char *temp, char *buff)
{
	char	*combined;
	int		i;

	i = 0;
	combined = (char *)malloc((ft_strlen_c(temp, '\0') + 2) * sizeof(char));
	if (!combined)
		ft_perror(1);
	while (temp[i])
	{
		combined[i] = temp[i];
		i++;
	}
	combined[i] = buff[0];
	combined[i + 1] = '\0';
	free(temp);
	return (combined);
}

void	file_copier(t_data *data, char *file)
{
	int		fd;
	int		ret;
	char	buff[2];

	data->map.temp_map = (char *)malloc(1 * sizeof(char));
	if (!data->map.temp_map)
		ft_perror(1);
	data->map.temp_map[0] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror(1);
	ret = read(fd, buff, 1);
	if (ret == -1)
		ft_perror(1);
	if (ret == 0)
		fatal(1, "File is empty", "(no map included)");
	while (ret > 0)
	{
		buff[1] = '\0';
		data->map.temp_map = buff_copy(data->map.temp_map, buff);
		ret = read(fd, buff, 1);
		if (ret == -1)
			ft_perror(1);
	}
}

void	file_check(char *file)
{
	int	len;

	len = ft_strlen_c(file, '\0');
	if (len >= 4)
		if (ft_strncmp(&file[len - 4], ".ber", 4) == 0)
			return ;
	fatal(1, "Invalid given file", "(only .ber format allowed)");
}

void	file_handle(t_data *data, char *file)
{
	file_check(file);
	file_copier(data, file);
	wall_check(data);
	elements(data);
	data->map.map = map_convert(data);
	data->path.map_copy = map_convert(data);
	free(data->map.temp_map);
	path_check(data->path.pos[0], data->path.pos[1], data);
	if (data->path.count_c != data->map.collectible)
		fatal(1, "Invalid path", "(collectible component not reachable)");
	if (data->path.count_e != data->map.end)
		fatal(1, "Invalid path", "(end component not reachable)");
	free_map(data->path.map_copy);
}
