/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_empty_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:02:34 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:02:38 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	map_is_empty(t_mlx *mlx)
{
	if (mlx->data == NULL)
	{
		ft_printf("Error: the map is empty.\n");
		mlx_destroy_display(mlx->mlx_ptr);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
}
