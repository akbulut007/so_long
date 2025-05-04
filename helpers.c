/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:46:03 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/02 17:46:10 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	count_stars(t_map *row, t_mlx *mlx, int idx)
{
	if (row->data[idx] == 'C')
	{
		mlx->stars_count++;
		row->data[idx] = '0';
	}
}

t_map	*get_row(t_mlx *mlx, t_map *head, int row_index)
{
	int	i;

	i = 0;
	if (head)
	{
		while (head != NULL && i < row_index)
		{
			head = head->next;
			i++;
		}
	}
	else
	{
		clean_exit(mlx);
		return (NULL);
	}
	return (head);
}

void	count_collect(t_mlx *mlx)
{
	t_map	*temp;
	int		count;

	temp = mlx->data;
	mlx->collect_num = 0;
	while (temp != NULL)
	{
		count = 0;
		while (temp->data[count] != '\0')
		{
			if (temp->data[count] == 'C')
			{
				mlx->collect_num++;
			}
			count++;
		}
		temp = temp->next;
	}
}

int	find_coords(t_mlx *mlx, int *idx_x, int *idx_y, char c)
{
	t_map	*temp;
	int		y;
	int		x;

	temp = mlx->data;
	y = 0;
	while (temp != NULL)
	{
		x = 0;
		while (temp->data[x])
		{
			if (temp->data[x] == c)
			{
				*idx_y = y;
				*idx_x = x;
				return (1);
			}
			x++;
		}
		y++;
		temp = temp->next;
	}
	return (0);
}

void	init_images(t_mlx *mlx, int height, int width)
{
	mlx->img_height = 1;
	mlx->img_width = 1;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			65 * width, 65 * height, "so_long");
	mlx->img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr,
			WALL_IMG, &mlx->img_width, &mlx->img_height);
	mlx->img_empty = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EMPTY_SPACE_IMG, &mlx->img_width, &mlx->img_height);
	mlx->img_collect = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECTIBLE_IMG, &mlx->img_width, &mlx->img_height);
	mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx_ptr,
			EXIT_IMG, &mlx->img_width, &mlx->img_height);
	mlx->img_player = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_IMG, &mlx->img_width, &mlx->img_height);
	mlx->img_player_on_exit = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_ON_EXIT, &mlx->img_width, &mlx->img_height);
}
