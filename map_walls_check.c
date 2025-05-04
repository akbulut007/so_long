/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:03:22 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:03:25 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_first_node(t_mlx *mlx, t_map *temp, int i)
{
	while (temp->data[i] != '\n')
	{
		if (temp->data[i] != '1')
		{
			ft_printf("Error: the map is not surrounded by walls.\n");
			mlx_destroy_display(mlx->mlx_ptr);
			free_map(&mlx->data);
			free(mlx);
			exit(1);
		}
		i++;
	}
}

void	check_middle_nodes(t_mlx *mlx, t_map *temp)
{
	int	len;

	len = 0;
	while (temp->data[len] != '\n')
		len++;
	if (temp->data[0] != '1' || temp->data[len - 1] != '1')
	{
		ft_printf("Error: the map is not surrounded by walls.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
}

void	check_last_node(t_mlx *mlx, t_map *temp, int i)
{
	i = 0;
	while (temp->data[i] != '\0')
	{
		if (temp->data[i] != '1')
		{
			ft_printf("Error: the map is not surrounded by walls.\n");
			mlx_destroy_display(mlx->mlx_ptr);
			free_map(&mlx->data);
			free(mlx);
			exit(1);
		}
		i++;
	}
}

void	check_walls(t_mlx *mlx)
{
	t_map	*temp;
	int		i;

	temp = mlx->data;
	i = 0;
	check_first_node(mlx, temp, i);
	temp = temp->next;
	while (temp->next != NULL)
	{
		check_middle_nodes(mlx, temp);
		temp = temp->next;
	}
	check_last_node(mlx, temp, i);
}
