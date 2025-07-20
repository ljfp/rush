/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:47:43 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 22:43:44 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_row_complete(int grid[SIZE][SIZE], int row)
{
	int	col;

	col = 0;
	while (col < SIZE)
	{
		if (grid[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	is_row_valid(int grid[SIZE][SIZE], int row, t_input *input)
{
	if (!is_row_complete(grid, row))
		return (1);
	if (!check_row_left(grid, row, input->row_left[row]))
		return (0);
	if (!check_row_right(grid, row, input->row_right[row]))
		return (0);
	return (1);
}

int	is_col_valid(int grid[SIZE][SIZE], int col, t_input *input)
{
	if (!check_col_up(grid, col, input->col_up[col]))
		return (0);
	if (!check_col_down(grid, col, input->col_down[col]))
		return (0);
	return (1);
}

int	is_safe(int grid[SIZE][SIZE], t_pos pos, t_input *input)
{
	int	placed;
	if (!check_latin_square(grid, pos.row, pos.col, pos.height))
		return (0);
	grid[pos.row][pos.col] = pos.height;
	if (is_row_complete(grid, pos.row)
		&& !is_row_valid(grid, pos.row, input))
	{
		grid[pos.row][pos.col] = 0;
		return (0);
	}
	placed = 1;
	if (pos.row == SIZE - 1)
	{
		if (!is_col_valid(grid, pos.col, input))
			placed = 0;
	}
	if (!placed)
	{
		grid[pos.row][pos.col] = 0;
		return (0);
	}
	return (1);
}

int	get_next_position(t_pos *pos)
{
	pos->col = (pos->col + 1) % SIZE;
	if (pos->col == 0)
		pos->row++;
	if (pos->row >= SIZE)
		return (0);
	return (1);
}

int	solve_recursive(int grid[SIZE][SIZE], t_pos pos, t_input *input)
{
	t_pos	next_pos;

	if (pos.row >= SIZE)
		return (1);
	next_pos.row = pos.row;
	next_pos.col = pos.col;
	get_next_position(&next_pos);
	pos.height = 1;
	while (pos.height <= SIZE)
	{
		if (is_safe(grid, pos, input))
		{
			if (solve_recursive(grid, next_pos, input))
				return (1);
			grid[pos.row][pos.col] = 0;
		}
		pos.height++;
	}
	return (0);
}

int	solve(int grid[SIZE][SIZE], t_input *input)
{
	t_pos	start_pos;

	start_pos.row = 0;
	start_pos.col = 0;
	start_pos.height = 0;
	return (solve_recursive(grid, start_pos, input));
}
