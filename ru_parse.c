/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ru_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 00:00:00 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 00:00:00 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	is_valid_number(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
}

void	assign_value_to_input(t_input *input, int count, int j, int value)
{
	if (count < 4)
		input->col_up[j] = value;
	else if (count < 8)
		input->col_down[j] = value;
	else if (count < 12)
		input->row_left[j] = value;
	else if (count < 16)
		input->row_right[j] = value;
}

int	process_valid_number(char c, t_input *input, int *j, int *count)
{
	assign_value_to_input(input, *count, *j, c - '0');
	(*j)++;
	if (*j == 4)
	{
		*j = 0;
		*count += 4;
	}
	return (1);
}

int	parse_input(char *str, t_input *input)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_valid_number(str[i]))
		{
			process_valid_number(str[i], input, &j, &count);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}
