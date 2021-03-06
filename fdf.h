/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rburri <rburri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:22:59 by rburri            #+#    #+#             */
/*   Updated: 2022/02/09 17:19:37 by rburri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define TITLE "fdf"
# define ESC_CODE 53

//ERROR MESSAGES
# define FDF_INIT_ERR "Fdf initialization error"
# define MAP_INIT_ERR "Map initialization error"
# define OPEN_ERR "Open map_file error"
# define CLOSE_ERR "Close map_file error"
# define MAP_ERR "Map parsing error"
# define USR_ERR "Usage: ./fdf map_file"
# define IMG_INT_ERR "img initialization error"
# define CONVERT_ARRAY_ERR "Error at converting stack to array"
# define ERR_CAMERA_INIT "Error at camera init"

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}			t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		*coords_arr;
	int		z_min;
	int		z_max;
	int		z_range;
}					t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

t_point	*pop_pts(t_point **pts_stack);
t_point	project(t_point p, t_map *map);
void	fdf_init(t_mlx *data);
void	map_init(t_map *map);
int		key_hook(int keycode, t_mlx *data);
int		read_map(int fd, t_point **pts_stack, t_map *map);
void	draw_line(t_mlx *fdf, t_point s, t_point f);
void	my_pixel_put(t_mlx *fdf, int x, int y, int color);
void	send_err(char *s);
void	push_pts(t_point **pts_stack, t_point *new_pts);
void	ft_print_stack(t_point *stack);
void	stack_to_coords_array(t_point **pts_stack, t_map *map);
void	draw(t_mlx *data, t_map *map);
int		close_win(t_mlx *data);

#endif