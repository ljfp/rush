/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:02 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/19 22:48:24 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define SIZE 4
# define MIN_HEIGHT 1
# define MAX_HEIGHT 4

typedef struct s_input
{
	int	col_up[SIZE];
	int	col_down[SIZE];
	int	row_left[SIZE];
	int	row_right[SIZE];
}	t_input;

typedef struct s_pos
{
	int	row;
	int	col;
	int	height;
}	t_pos;

/* main.c */
int		parse_input(char *str, t_input *input);
int     is_valid_number(char c);

/* ru_solve.c */
int		solve(int grid[SIZE][SIZE], t_input *input);
int		is_safe(int grid[SIZE][SIZE], t_pos pos, t_input *input);
int     is_row_complete(int grid[SIZE][SIZE], int row);

/* ru_check.c */
int		check_row_left(int grid[SIZE][SIZE], int row, int expected);
int		check_row_right(int grid[SIZE][SIZE], int row, int expected);
int		check_col_up(int grid[SIZE][SIZE], int col, int expected);
int		check_col_down(int grid[SIZE][SIZE], int col, int expected);
int     check_latin_square(int grid[SIZE][SIZE], int row, int col, int height);

/* ru_print.c */
void	print_grid(int grid[SIZE][SIZE]);

#endif
