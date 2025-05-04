/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_helper_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:01:50 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:53 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	argc_is_not_two(t_mlx *mlx)
{
	ft_printf("Error: the map is not provided.\n");
	mlx_destroy_display(mlx->mlx_ptr);
	free_map(&mlx->data);
	free(mlx);
	exit(1);
}

void	parse_map(t_mlx *mlx, t_map *temp)
{
	if (temp->data[mlx->pos_x] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_wall, mlx->pos_x * 65, mlx->pos_y * 65);
	else if (temp->data[mlx->pos_x] == '0')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_empty, mlx->pos_x * 65, mlx->pos_y * 65);
	else if (temp->data[mlx->pos_x] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_collect, mlx->pos_x * 65, mlx->pos_y * 65);
	else if (temp->data[mlx->pos_x] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img_player, mlx->pos_x * 65, mlx->pos_y * 65);
	else if (temp->data[mlx->pos_x] == 'E')
	{
		if ((mlx->player_x == mlx->exit_x && mlx->player_y == mlx->exit_y)
			&& mlx->stars_count < mlx->collect_num)
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img_player_on_exit, mlx->pos_x * 65, mlx->pos_y * 65);
		else
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img_exit, mlx->pos_x * 65, mlx->pos_y * 65);
	}
}

size_t	count_width_of_map(char *read_line)
{
	size_t	line_len;

	line_len = ft_strlen(read_line);
	if (line_len > 0 && read_line[line_len - 1] == '\n')
		return (line_len - 1);
	return (line_len);
}

void	check_map(t_mlx *mlx, t_state state)
{
	map_is_empty(mlx);
	check_compose(mlx);
	count_maps_chars(mlx);
	check_walls(mlx);
	valid_path(mlx, state);
	map_form_check(mlx);
	init_images(mlx, state.cols, state.rows);
	find_coords(mlx, &mlx->player_x, &mlx->player_y, 'P');
	find_coords(mlx, &mlx->exit_x, &mlx->exit_y, 'E');
	count_collect(mlx);
	display_img(mlx);
}
