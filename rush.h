/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauferna <ljfp@ljfp.xyz>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:51:02 by lauferna          #+#    #+#             */
/*   Updated: 2025/07/20 15:17:52 by lauferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define MAX_SIZE 9
# define MIN_SIZE 4
# define MIN_HEIGHT 1

typedef struct s_input
{
	int	size;
	int	col_up[MAX_SIZE];
	int	col_down[MAX_SIZE];
	int	row_left[MAX_SIZE];
	int	row_right[MAX_SIZE];
}	t_input;

typedef struct s_pos
{
	int	row;
	int	col;
	int	height;
}	t_pos;

/* main.c */
void	init_grid(int **grid, int size);
int		**create_grid(int size);
void	free_grid(int **grid, int size);

/* ru_parse.c */
int		process_valid_number(char c, t_input *input, int *j, int *count);
int		count_numbers_in_input(char *str);
int		determine_grid_size(char *str);
int		parse_input(char *str, t_input *input);

/* ru_parse2.c*/
int		is_valid_number(char c, int max_height);
void	assign_value_to_input(t_input *input, int count, int j, int value);

/* ru_solve.c */
int		is_row_complete(int **grid, int row, int size);
int		is_row_valid(int **grid, int row, t_input *input);
int		is_col_valid(int **grid, int col, t_input *input);
int		solve_recursive(int **grid, t_pos pos, t_input *input);
int		solve(int **grid, t_input *input);

/* ru_solve2.c*/
int		is_safe(int **grid, t_pos pos, t_input *input);
int		get_next_position(t_pos *pos, int size);

/* ru_check.c */
int		check_row_left(int **grid, int row, int expected, int size);
int		check_row_right(int **grid, int row, int expected, int size);
int		check_col_up(int **grid, int col, int expected, int size);
int		check_col_down(int **grid, int col, int expected, int size);
int		check_latin_square(int **grid, int row, int col, int height, int size);

/* ru_print.c */
void	print_grid(int **grid, int size);

#endif
