/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_solve2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:18:09 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 15:21:24 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_safe(int **grid, t_pos pos, t_input *input)
{
	int	placed;

	if (!check_latin_square(grid, pos.row, pos.col, pos.height, input->size))
		return (0);
	grid[pos.row][pos.col] = pos.height;
	if (is_row_complete(grid, pos.row, input->size)
		&& !is_row_valid(grid, pos.row, input))
	{
		grid[pos.row][pos.col] = 0;
		return (0);
	}
	placed = 1;
	if (pos.row == input->size - 1)
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

int	get_next_position(t_pos *pos, int size)
{
	pos->col = (pos->col + 1) % size;
	if (pos->col == 0)
		pos->row++;
	if (pos->row >= size)
		return (0);
	return (1);
}
