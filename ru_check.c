/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:25:33 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 22:27:02 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_row_left(int **grid, int row, int expected, int size)
{
	int	col;
	int	visible;
	int	max_height;

	col = 0;
	visible = 0;
	max_height = 0;
	while (col < size)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible++;
		}
		col++;
	}
	return (visible == expected);
}

int	check_row_right(int **grid, int row, int expected, int size)
{
	int	col;
	int	visible;
	int	max_height;

	col = size - 1;
	visible = 0;
	max_height = 0;
	while (col >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible++;
		}
		col--;
	}
	return (visible == expected);
}

int	check_col_up(int **grid, int col, int expected, int size)
{
	int	row;
	int	visible;
	int	max_height;

	row = 0;
	visible = 0;
	max_height = 0;
	while (row < size)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible++;
		}
		row++;
	}
	return (visible == expected);
}

int	check_col_down(int **grid, int col, int expected, int size)
{
	int	row;
	int	visible;
	int	max_height;

	row = size - 1;
	visible = 0;
	max_height = 0;
	while (row >= 0)
	{
		if (grid[row][col] > max_height)
		{
			max_height = grid[row][col];
			visible++;
		}
		row--;
	}
	return (visible == expected);
}

int	check_latin_square(int **grid, int row, int col, int height, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[row][i] == height || grid[i][col] == height)
			return (0);
		i++;
	}
	return (1);
}
