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

int	is_valid_number(char c)
{
	if (c >= '1' && c <= '4')
		return (1);
	return (0);
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
			if (count < 4)
				input->col_up[j] = str[i] - '0';
			else if (count < 8)
				input->col_down[j] = str[i] - '0';
			else if (count < 12)
				input->row_left[j] = str[i] - '0';
			else if (count < 16)
				input->row_right[j] = str[i] - '0';
			j++;
			if (j == 4)
			{
				j = 0;
				count += 4;
			}
			count = count;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}

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
