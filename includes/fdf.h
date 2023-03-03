/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:59:37 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/03 09:57:22 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define ESC 53
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define FOUR 21
# define SIX 22
# define EIGHT 28
# define TWO 19
# define HEIGHT 1000
# define WIDTH 1500
# define PLUS 24
# define MINUS 27
# define J 38
# define H 4

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		height;
	int		width;
	int		zoom;
	int		z_zoom;
	double	sin_angle;
	double	cos_angle;
	int		color;
	int		y_shift;
	int		x_shift;
	int		**matrix;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	black;
	t_point	a;
	t_point	b;
}	t_map;

void		create_map(t_map *map, char *file);
int			ft_is_whitespace(char c);
float		absolute(float a);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			maxi(int a, int b);
void		draw_line(t_point a, t_point b, t_map *mlx);
void		draw_map(t_map *mlx);
void		setall(t_map *mlx);
void		zoom(t_point *a, t_point *b, t_map *mlx);
void		set_color(int z1, int z2, t_map *mlx);
void		shifting(t_point *a, t_point *b, t_map *mlx);
void		arrows(int keycode, t_map *mlx);
void		modifyvalue(int keycode, t_map *mlx);
void		free_matrix(t_map *mlx);

#endif