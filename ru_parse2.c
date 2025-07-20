/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:09:30 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 15:10:58 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_valid_number(char c, int max_height)
{
	if (c >= '1' && c <= ('0' + max_height))
		return (1);
	return (0);
}

void	assign_value_to_input(t_input *input, int count, int j, int value)
{
	int	size;

	size = input->size;
	if (count < size)
		input->col_up[j] = value;
	else if (count < size * 2)
		input->col_down[j] = value;
	else if (count < size * 3)
		input->row_left[j] = value;
	else if (count < size * 4)
		input->row_right[j] = value;
}
