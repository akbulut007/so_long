/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakbul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:03:44 by muhakbul          #+#    #+#             */
/*   Updated: 2025/05/04 18:03:55 by muhakbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void	*mlx_init(void);
void	*mlx_new_window(void *mlx_ptr, int size_x,
			int size_y, char *title);
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr,
			int x, int y, int color);
void	*mlx_new_image(void *mlx_ptr, int width, int height);
char	*mlx_get_data_addr(void *img_ptr, int *bpp,
			int *size_line, int *endian);
int		mlx_put_image_to_window(void *mlx_ptr,
			void *win_ptr, void *img_ptr,
			int x, int y);
int		mlx_get_color_value(void *mlx_ptr, int color);
int		mlx_mouse_hook(void *win_ptr,
			int (*f)(), void *param);
int		mlx_key_hook(void *win_ptr,
			int (*f)(), void *param);
int		mlx_expose_hook(void *win_ptr,
			int (*f)(), void *param);
int		mlx_loop_hook(void *mlx_ptr,
			int (*f)(), void *param);
int		mlx_loop(void *mlx_ptr);
int		mlx_loop_end(void *mlx_ptr);
int		mlx_string_put(void *mlx_ptr, void *win_ptr,
			int x, int y,
			int color, char *string);
void	mlx_set_font(void *mlx_ptr,
			void *win_ptr, char *name);
void	*mlx_xpm_to_image(void *mlx_ptr,
			char **xpm_data,
			int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr,
			char *filename,
			int *width, int *height);
int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int		mlx_destroy_display(void *mlx_ptr);
int		mlx_hook(void *win_ptr, int x_event,
			int x_mask,
			int (*f)(), void *param);
int		mlx_do_key_autorepeatoff(void *mlx_ptr);
int		mlx_do_key_autorepeaton(void *mlx_ptr);
int		mlx_do_sync(void *mlx_ptr);
int		mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr,
			int *x, int *y);
int		mlx_mouse_move(void *mlx_ptr,
			void *win_ptr, int x, int y);
int		mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int		mlx_mouse_show(void *mlx_ptr, void *win_ptr);
int		mlx_get_screen_size(void *mlx_ptr,
			int *sizex, int *sizey);

#endif
