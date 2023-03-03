/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:06:26 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/03 08:47:19 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(t_point *p, int z, t_map *mlx)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = (prev_x - prev_y) * cos((mlx->sin_angle / 360) * 2 * M_PI);
	p->y = (prev_x + prev_y) * sin((mlx->cos_angle / 360) * 2 * M_PI) - z;
}

void	setall(t_map *mlx)
{
	int	z1;
	int	z2;

	z1 = mlx->matrix[(int)mlx->a.y][(int)mlx->a.x];
	z2 = mlx->matrix[(int)mlx->b.y][(int)mlx->b.x];
	zoom(&mlx->a, &mlx->b, mlx);
	z1 *= mlx->z_zoom;
	z2 *= mlx->z_zoom;
	set_color(z1, z2, mlx);
	iso(&mlx->a, z1, mlx);
	iso(&mlx->b, z2, mlx);
	shifting(&mlx->a, &mlx->b, mlx);
}

void	draw_line(t_point a, t_point b, t_map *mlx)
{
	float	dx;
	float	dy;
	int		max;

	mlx->a = a;
	mlx->b = b;
	setall(mlx);
	dx = mlx->b.x - mlx->a.x;
	dy = mlx->b.y - mlx->a.y;
	max = maxi(absolute(dx), absolute(dy));
	dx /= max;
	dy /= max;
	while ((int)(mlx->a.x - mlx->b.x) || (int)(mlx->a.y - mlx->b.y))
	{
		my_mlx_pixel_put(&mlx->img, (int)mlx->a.x, (int)mlx->a.y, mlx->color);
		mlx->a.x += dx;
		mlx->a.y += dy;
	}
}

void	draw_map(t_map *mlx)
{
	t_point	a;
	t_point	b;

	a.y = -1;
	while (++a.y < mlx->height)
	{
		a.x = -1;
		while (++a.x < mlx->width)
		{
			if (a.x < mlx->width - 1)
			{
				b.x = a.x + 1;
				b.y = a.y;
				draw_line(a, b, mlx);
			}
			if (a.y < mlx->height - 1)
			{
				b.x = a.x;
				b.y = a.y + 1;
				draw_line(a, b, mlx);
			}
		}
	}
}
