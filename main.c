/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: evan-der <evan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/28 15:54:22 by evan-der      #+#    #+#                 */
/*   Updated: 2022/12/30 13:41:13 by evan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	if (argc > 2)
		fatal(1, "Invalid amount of arguments given", "(too many)");
	else if (argc < 2)
		fatal(1, "Invalid amount of arguments given", "(missing file)");
	so_long(argv[1]);
	return (0);
}
