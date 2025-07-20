/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:50:24 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 20:09:26 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

void	init_grid(int grid[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_input	input;
	int		grid[SIZE][SIZE];

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	if (!parse_input(argv[1], &input))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve(grid, &input))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_grid(grid);
	return (0);
}
