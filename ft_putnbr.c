/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 18:57:29 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 18:58:48 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putnbr(int nb)
{
	int	div;
	int	mod;

	div = nb / 10;
	mod = nb % 10;
	if (div != 0)
		ft_putnbr(div);
	ft_putchar(mod + '0');
}
