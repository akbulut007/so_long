/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_helper_func.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:01:40 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:43 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_exit_left_right(t_mlx *mlx, t_map *row, int idx_x)
{
	if ((idx_x == mlx->exit_x && mlx->player_y == mlx->exit_y)
		&& mlx->stars_count < mlx->collect_num)
	{
		row->data[idx_x] = 'E';
		row->data[mlx->player_x] = '0';
		mlx->player_x = idx_x;
		return (1);
	}
	else if ((idx_x == mlx->exit_x && mlx->player_y == mlx->exit_y)
		&& mlx->stars_count == mlx->collect_num)
	{
		row->data[idx_x] = 'E';
		row->data[mlx->player_x] = '0';
		mlx->player_x = idx_x;
		ft_printf("The game is over. You won!\n");
		clean_exit(mlx);
		exit(0);
		return (1);
	}
	return (0);
}

int	handle_exit_up_down(t_mlx *mlx, t_map *row, t_map *current_row, int idx_y)
{
	if ((mlx->player_x == mlx->exit_x && idx_y == mlx->exit_y)
		&& mlx->stars_count < mlx->collect_num)
	{
		row->data[mlx->player_x] = 'E';
		current_row->data[mlx->player_x] = '0';
		mlx->player_y = idx_y;
		return (1);
	}
	else if (mlx->player_x == mlx->exit_x && idx_y == mlx->exit_y
		&& mlx->stars_count == mlx->collect_num)
	{
		row->data[mlx->player_x] = 'E';
		current_row->data[mlx->player_x] = '0';
		mlx->player_y = idx_y;
		ft_printf("The game is over. You won!\n");
		clean_exit(mlx);
		exit(0);
		return (1);
	}
	return (0);
}

void	handle_move_left_right(t_mlx *mlx, t_map *row, int idx_x)
{
	if (mlx->player_x == mlx->exit_x && mlx->player_y == mlx->exit_y)
	{
		row->data[idx_x] = 'P';
		row->data[mlx->player_x] = 'E';
		mlx->player_x = idx_x;
	}
	else
	{
		row->data[idx_x] = 'P';
		row->data[mlx->player_x] = '0';
		mlx->player_x = idx_x;
	}
}

void	handle_move_up_down(t_mlx *mlx, t_map *row,
		t_map *current_row, int idx_y)
{
	if (mlx->player_x == mlx->exit_x && mlx->player_y == mlx->exit_y)
	{
		row->data[mlx->player_x] = 'P';
		current_row->data[mlx->player_x] = 'E';
		mlx->player_y = idx_y;
	}
	else
	{
		row->data[mlx->player_x] = 'P';
		current_row->data[mlx->player_x] = '0';
		mlx->player_y = idx_y;
	}
}
