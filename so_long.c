/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:01:02 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 17:01:05 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	so_long(int argc, char *argv[])
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		ft_printf("mlx is NULL");
	}
	mlx->mlx_ptr = mlx_init();
	read_map(mlx, argc, argv);
	game(mlx);
	mlx_loop(mlx->mlx_ptr);
	clean_exit(mlx);
	ft_printf("TEST.\n");
}

int	main(int argc, char *argv[])
{
	so_long(argc, argv);
	ft_printf("TEST.\n");
	return (0);
}
