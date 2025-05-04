/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:00:39 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:00:43 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_left(t_mlx *mlx)
{
	t_map	*row;
	char	next_line;
	char	*mv_str;

	row = get_row(mlx, mlx->data, mlx->player_y);
	next_line = row->data[mlx->player_x - 1];
	count_stars(row, mlx, mlx->player_x - 1);
	if (next_line == '1')
		return ;
	if (!handle_exit_left_right(mlx, row, mlx->player_x - 1))
		handle_move_left_right(mlx, row, mlx->player_x - 1);
	mlx->mv_num++;
	mv_str = ft_itoa(mlx->mv_num);
	ft_printf("The number of player's movements: %s\n", mv_str);
	free(mv_str);
}

void	move_right(t_mlx *mlx)
{
	t_map	*row;
	char	next_line;
	char	*mv_str;

	row = get_row(mlx, mlx->data, mlx->player_y);
	next_line = row->data[mlx->player_x + 1];
	count_stars(row, mlx, mlx->player_x + 1);
	if (next_line == '1')
		return ;
	if (!handle_exit_left_right(mlx, row, mlx->player_x + 1))
		handle_move_left_right(mlx, row, mlx->player_x + 1);
	mlx->mv_num++;
	mv_str = ft_itoa(mlx->mv_num);
	ft_printf("The number of player's movements: %s\n", mv_str);
	free(mv_str);
}

void	move_up(t_mlx *mlx)
{
	t_map	*upper_row;
	t_map	*current_row;
	char	*mv_str;

	upper_row = get_row(mlx, mlx->data, mlx->player_y - 1);
	current_row = get_row(mlx, mlx->data, mlx->player_y);
	count_stars(upper_row, mlx, mlx->player_x);
	if (upper_row->data[mlx->player_x] == '1')
		return ;
	if (!handle_exit_up_down(mlx, upper_row, current_row, mlx->player_y - 1))
		handle_move_up_down(mlx, upper_row, current_row, mlx->player_y - 1);
	mlx->mv_num++;
	mv_str = ft_itoa(mlx->mv_num);
	ft_printf("The number of player's movements: %s\n", mv_str);
	free(mv_str);
}

void	move_down(t_mlx *mlx)
{
	t_map	*lower_row;
	t_map	*current_row;
	char	*mv_str;

	lower_row = get_row(mlx, mlx->data, mlx->player_y + 1);
	current_row = get_row(mlx, mlx->data, mlx->player_y);
	count_stars(lower_row, mlx, mlx->player_x);
	if (lower_row->data[mlx->player_x] == '1')
		return ;
	if (!handle_exit_up_down(mlx, lower_row, current_row, mlx->player_y + 1))
		handle_move_up_down(mlx, lower_row, current_row, mlx->player_y + 1);
	mlx->mv_num++;
	mv_str = ft_itoa(mlx->mv_num);
	ft_printf("The number of player's movements: %s\n", mv_str);
	free(mv_str);
}
