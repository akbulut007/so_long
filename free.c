/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:01:28 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:31 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(t_map **head)
{
	t_map	*temp;
	t_map	*next_node;

	temp = *head;
	while (temp)
	{
		next_node = temp->next;
		free(temp->data);
		free(temp);
		temp = next_node;
	}
	*head = NULL;
}

void	clean_exit(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->mlx_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_empty);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_collect);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_exit);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_player);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_player_on_exit);
	}
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
	}
	free_map(&mlx->data);
	free(mlx);
}

void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
