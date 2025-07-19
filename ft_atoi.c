/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:00:29 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/14 21:06:06 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(char *str);
unsigned int	is_space(unsigned char c);

unsigned int	is_space(unsigned char c)
{
	if (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	unsigned int	minus_signs;
	unsigned int	result;

	minus_signs = 0;
	result = 0;
	while (is_space((unsigned char) *str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_signs++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (minus_signs % 2 == 1)
		result = -result;
	return (result);
}
