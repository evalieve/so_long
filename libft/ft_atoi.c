/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 14:06:55 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/29 13:33:45 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(int exitcode, char *exitstr)
{
	ft_putstr_fd(exitstr, 2);
	exit(exitcode);
}

static long long	ft_changer(const char *str, int i)
{
	long long	changed;
	long long	result;

	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		changed = str[i] - '0';
		result = (result * 10) + changed;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			pos_neg;
	long long	result;

	i = 0;
	pos_neg = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos_neg = -1;
		i++;
	}
	if (!(str[i] && str[i] >= '0' && str[i] <= '9'))
		return (0);
	else
		result = ft_changer(str, i);
	result = result * pos_neg;
	if (result < -2147483648 || result > 2147483647)
		ft_error(1, "Error\n");
	return ((int)result);
}
