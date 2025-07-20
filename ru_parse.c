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

int	process_valid_number(char c, t_input *input, int *j, int *count)
{
	assign_value_to_input(input, *count, *j, c - '0');
	(*j)++;
	if (*j == input->size)
	{
		*j = 0;
		*count += input->size;
	}
	return (1);
}

int	count_numbers_in_input(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

int	determine_grid_size(char *str)
{
	int	total_numbers;
	int	size;

	total_numbers = count_numbers_in_input(str);
	size = MIN_SIZE;
	while (size <= MAX_SIZE)
	{
		if (total_numbers == size * 4)
			return (size);
		size++;
	}
	return (-1);
}

int	parse_input(char *str, t_input *input)
{
	int	i;
	int	j;
	int	count;

	input->size = determine_grid_size(str);
	if (input->size == -1)
		return (0);
	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_valid_number(str[i], input->size))
		{
			process_valid_number(str[i], input, &j, &count);
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == input->size * 4);
}
