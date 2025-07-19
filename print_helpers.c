/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:24:10 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 19:36:31 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putnbr(int nb);

void	print_numbers(int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(numbers[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
