/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:00:23 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:00:28 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_key(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_LEFT)
		move_left(mlx);
	else if (keycode == KEY_RIGHT)
		move_right(mlx);
	else if (keycode == KEY_UP)
		move_up(mlx);
	else if (keycode == KEY_DOWN)
		move_down(mlx);
	else if (keycode == KEY_ESC)
	{
		clean_exit(mlx);
		exit(0);
	}
	display_img(mlx);
	return (0);
}

int	close_win(t_mlx *mlx, int i)
{
	i = 0;
	clean_exit(mlx);
	exit(0);
	return (i);
}

void	game(t_mlx *mlx)
{
	mlx->stars_count = 0;
	mlx->mv_num = 0;
	mlx_hook(mlx->win_ptr, 2, 1L << 0, handle_key, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_win, mlx);
}
