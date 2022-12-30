/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 15:03:12 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/28 15:03:13 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_perror(int exitcode)
{
	perror("\e[0;31mError\n\e[0mso_long");
	exit(exitcode);
}

void	fatal(int exitcode, char *exitstr1, char *exitstr2)
{
	ft_putstr_fd("\e[0;31mError\n\e[0m", STDERR_FILENO);
	ft_putstr_fd("so_long: ", STDERR_FILENO);
	ft_putstr_fd(exitstr1, STDERR_FILENO);
	ft_putstr_fd("\033[0;30m ", STDERR_FILENO);
	ft_putstr_fd(exitstr2, STDERR_FILENO);
	ft_putstr_fd("\e[0m\n", STDERR_FILENO);
	exit(exitcode);
}
