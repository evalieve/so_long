#include <stdio.h> // for printf > delete later!

#include "./mlx/mlx.h"
#include <fcntl.h> // for open & read
#include <unistd.h> // for write
#include <stdlib.h> // for malloc

typedef struct s_map // structure for checks on valid values
{
	int p;
	int e;
	int c;
	int length;
	int width;
}				t_map;

void	ft_chrchecker(char c, t_map *info);

int ft_upbotcheck(char *map, int arg, t_map *info, int i);

void ft_mapchecker(char *map, t_map *info);

char *ft_filler(char *hold, char *buff);

char *ft_mapcopier(t_map *info);

void ft_init(t_map *info);

int ft_strlen(char *str, char skip);

void ft_error(char *message);

void ft_window_manager(t_map *info);

void ft_winfix(t_map *info);

int ft_lendigit(int digit);