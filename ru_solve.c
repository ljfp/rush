/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:47:43 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 15:18:31 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_row_complete(int **grid, int row, int size)
{
	int	col;

	col = 0;
	while (col < size)
	{
		if (grid[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	is_row_valid(int **grid, int row, t_input *input)
{
	if (!is_row_complete(grid, row, input->size))
		return (1);
	if (!check_row_left(grid, row, input->row_left[row], input->size))
		return (0);
	if (!check_row_right(grid, row, input->row_right[row], input->size))
		return (0);
	return (1);
}

int	is_col_valid(int **grid, int col, t_input *input)
{
	if (!check_col_up(grid, col, input->col_up[col], input->size))
		return (0);
	if (!check_col_down(grid, col, input->col_down[col], input->size))
		return (0);
	return (1);
}

int	solve_recursive(int **grid, t_pos pos, t_input *input)
{
	t_pos	next_pos;

	if (pos.row >= input->size)
		return (1);
	next_pos.row = pos.row;
	next_pos.col = pos.col;
	get_next_position(&next_pos, input->size);
	pos.height = 1;
	while (pos.height <= input->size)
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

int	solve(int **grid, t_input *input)
{
	t_pos	start_pos;

	start_pos.row = 0;
	start_pos.col = 0;
	start_pos.height = 0;
	return (solve_recursive(grid, start_pos, input));
}
