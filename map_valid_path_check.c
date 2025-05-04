/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:02:46 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:02:49 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	dfs(char **grid, t_state state, int y, int x)
{
	if (x < 0 || x >= state.rows || y < 0 || y >= state.cols
		|| grid[y][x] == '1' || grid[y][x] == 'V')
	{
		return (0);
	}
	if (grid[y][x] == 'E')
		return (1);
	grid[y][x] = 'V';
	if (dfs(grid, state, y - 1, x) || dfs(grid, state, y + 1, x)
		|| dfs(grid, state, y, x - 1) || dfs(grid, state, y, x + 1))
		return (1);
	return (0);
}

char	**map_to_arr(t_mlx *mlx, t_state state)
{
	char	**grid;
	t_map	*temp;
	int		j;

	j = 0;
	grid = malloc(sizeof(char *) * state.cols + 1);
	if (!grid)
	{
		ft_printf("Grid is not allocated.\n");
		return (NULL);
	}
	temp = mlx->data;
	while (temp)
	{
		grid[j] = ft_strdup(temp->data);
		j++;
		temp = temp->next;
	}
	grid[j] = NULL;
	return (grid);
}

int	valid_path(t_mlx *mlx, t_state state)
{
	char	**grid;
	int		x;
	int		y;

	grid = map_to_arr(mlx, state);
	if (!grid)
		return (0);
	find_coords(mlx, &x, &y, 'P');
	if (!dfs(grid, state, y, x))
	{
		ft_printf("Error: the map doesn't have a valid path.\n");
		free(grid);
		free_map(&mlx->data);
		free(mlx);
		exit(1);
	}
	return (0);
}
