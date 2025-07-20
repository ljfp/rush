/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:50:24 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 13:27:02 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush.h"

int	**create_grid(int size)
{
	int	**grid;
	int	i;

	grid = (int **)malloc(size * sizeof(int *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc(size * sizeof(int));
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	free_grid(int **grid, int size)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	init_grid(int **grid, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
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
	int		**grid;

	if (argc != 2 || (!parse_input(argv[1], &input)))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	grid = create_grid(input.size);
	if (!grid)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid, input.size);
	if (!solve(grid, &input))
	{
		write(1, "Error\n", 6);
		free_grid(grid, input.size);
		return (1);
	}
	print_grid(grid, input.size);
	free_grid(grid, input.size);
	return (0);
}
