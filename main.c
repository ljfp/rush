/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:50:24 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 18:43:29 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>


void	ft_putstr(char *str);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	char	**views;
	int		*numbers;
	int		count;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
    views = ft_split(argv[1], " ");
    if (!views)
    {
        ft_putstr("Error\n");
        return (1);
    }
    while (views[count])
        count++;
    if (count != 16)
    {
        ft_putstr("Error\n");
        for (int i = 0; i < count; i++)
            free(views[i]);
        free(views);
        return (1);
    }
	numbers = (void*)0;
    for (int i = 0; i < 16; i++)
    {
        numbers[i] = ft_atoi(views[i]);
        if (numbers[i] < 1 || numbers[i] > 4)
        {
            ft_putstr("Error\n");
            for (int j = 0; j < 16; j++)
                free(views[j]);
            free(views);
            return (1);
        }
    }
    for (int i = 0; i < 16; i++)
        free(views[i]);
    free(views);
    return (0);
}
