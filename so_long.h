/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:58:04 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/01 16:58:11 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# define WALL_IMG "textures/img_xpm/asteroids_background.xpm"
# define EMPTY_SPACE_IMG "textures/img_xpm/sky.xpm"
# define EXIT_IMG "textures/img_xpm/black_hole_background.xpm"
# define COLLECTIBLE_IMG "textures/img_xpm/star_background.xpm"
# define PLAYER_IMG "textures/img_xpm/sky_background-1.png.xpm"
# define PLAYER_ON_EXIT "textures/img_xpm/player_on_exit.png.xpm"

# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_ESC 65307

typedef struct Maps
{
	char		*data;
	struct Maps	*next;
}	t_map;

typedef struct s_state
{
	char	**grid;
	int		rows;
	int		cols;
	int		x;
	int		y;
}	t_state;

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_empty;
	void	*img_collect;
	void	*img_exit;
	void	*img_player;
	void	*img_player_on_exit;
	int		img_height;
	int		img_width;
	int		pos_x;
	int		pos_y;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		exit_num;
	int		coll_num;
	int		player_num;
	t_map	*data;
	int		stars_count;
	int		collect_num;
	int		mv_num;
}	t_mlx;

void	read_map(t_mlx *mlx, int argc, char *argv[]);
void	add_to_end_node(t_map **head, char *read_line);
void	display_img(t_mlx *mlx);
void	free_map(t_map **head);
size_t	count_width_of_map(char *read_line);
void	parse_map(t_mlx *mlx, t_map *temp);
void	so_long(int argc, char *argv[]);
void	init_images(t_mlx *mlx, int height, int width);
int		find_coords(t_mlx *mlx, int *idx_x, int *idx_y, char c);
void	game(t_mlx *mlx);
void	handle_move_left_right(t_mlx *mlx, t_map *row, int idx);
void	handle_move_up_down(t_mlx *mlx, t_map *upper_row,
			t_map *current_row, int idx_y);
int		handle_exit_left_right(t_mlx *mlx, t_map *row, int idx_x);
int		handle_exit_up_down(t_mlx *mlx, t_map *row,
			t_map *current_row, int idx_y);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
t_map	*get_row(t_mlx *mlx, t_map *head, int row_index);
void	count_stars(t_map *row, t_mlx *mlx, int idx);
void	count_collect(t_mlx *mlx);
void	count_maps_chars(t_mlx *mlx);
void	check_walls(t_mlx *mlx);
int		valid_path(t_mlx *mlx, t_state state);
void	free_grid(char **grid, int height);
void	map_form_check(t_mlx *mlx);
void	map_is_empty(t_mlx *mlx);
void	check_compose(t_mlx *mlx);
void	check_map(t_mlx *mlx, t_state state);
void	argc_is_not_two(t_mlx *mlx);
void	clean_exit(t_mlx *mlx);

#endif
