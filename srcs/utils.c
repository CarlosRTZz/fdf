/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cortiz <cortiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:06:59 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/03 10:01:37 by cortiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

float	absolute(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	maxi(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
		return ;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
	return ;
}

void	free_matrix(t_map *mlx)
{
	int	i;

	i = 0;
	while (mlx->matrix[i])
	{
		free(mlx->matrix[i]);
		i++;
	}
	free(mlx->matrix);
	free(mlx);
}
