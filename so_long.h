/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 13:08:51 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/09 18:59:12 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_path
{
	char	**map_copy;
	int		count_c;
	int		count_e;
	int		pos[2];
}				t_path;

typedef struct s_map
{
	char	*temp_map;
	char	**map;
	int		width;
	int		rows;
	int		player;
	int		end;
	int		collectible;
}				t_map;

typedef struct s_xpm
{
	struct xpm	*background;
	struct xpm	*wall;
	struct xpm	*collectible;
	struct xpm	*player_l;
	struct xpm	*player_r;
	struct xpm	*player_b;
	struct xpm	*player_f;
	struct xpm	*end;
}				t_xpm;

typedef struct s_img
{
	struct mlx_image	*background;
	struct mlx_image	*wall;
	struct mlx_image	*collectible;
	struct mlx_image	*player_l;
	struct mlx_image	*player_r;
	struct mlx_image	*player_b;
	struct mlx_image	*player_f;
	struct mlx_image	*end;
}				t_img;

typedef struct s_data
{
	struct s_map		map;
	struct s_path		path;
	struct mlx			*mlx;
	struct s_xpm		xpm;
	struct s_img		img;
	int					count;
	int					collect_inst; // waar kom jij vandaan?
	int					walls_inst;
	int					bckgrnd_inst;
}				t_data;

char	**map_fill(char **map, t_data *data);
char	**map_convert(t_data *data);
void	fatal(int exitcode, char *exitstr1, char *exitstr2);
void	ft_perror(int exitcode);
void	file_handle(t_data *data, char *file);
void	file_check(char *file);
void	file_copier(t_data *data, char *file);
char	*buff_copy(char *temp, char *buff);
void	wall_check(t_data *data);
int		up_botline(t_data *data, char c, int pos);
int		midlines(t_data *data, int p);
void	element_check(t_data *data, char c);
void	elements(t_data *data);
void	path_check(int row, int pos, t_data *data);
void	pos_check(int row, int pos, t_data *data);
void	set_data(t_data *data);
void	free_map(char **map);
void	so_long(char *file);
void	player(t_data *data);
void	player_front(t_data *data);
void	player_left(t_data *data);
void	player_right(t_data *data);
void	player_back(t_data *data);
void	walls(t_data *data, int width, int height);
void	collectible(t_data *data, int width, int height);
void	end(t_data *data, int width, int height);
void	background(t_data *data, int width, int height);
void	player_depth(t_data *data, int left, int right, int back);
void	free_all(t_data *data);
int		key_action(t_data *data, int num, int rows, int width);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	set_depth_instance(t_data *data);

#endif