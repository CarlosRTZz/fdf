/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:07:50 by carlosortiz       #+#    #+#             */
/*   Updated: 2023/03/02 12:11:40 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
    c == '\v' || c == '\f' || c == '\r');
}

float absolute(float a)
{
    if (a < 0)
        return (-a);
    return (a);
}

int MAX(int a, int b)
{
    if (a > b)
     return (a);
    return (b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
            return;
    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
    return ;
}
