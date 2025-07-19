/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:50:24 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 19:35:49 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);
void	print_numbers(int *numbers, int size);

int	parse_args(char *str, int *numbers)
{
	int	i;
	int	num_index;

	i = 0;
	num_index = 0;
	while (str[i] != '\0' && num_index < 16)
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			numbers[num_index] = str[i] - '0';
			num_index++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (num_index != 16)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	views[16];
	int	valid;

	valid = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	valid = parse_args(argv[1], views);
	if (!valid)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_numbers(views, 16);
	return (0);
}
