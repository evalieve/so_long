/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_c.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 16:15:47 by evan-der      #+#    #+#                 */
/*   Updated: 2023/01/13 16:15:48 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_c(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
