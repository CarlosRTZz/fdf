/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlosortiz <carlosortiz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 08:06:42 by cortiz            #+#    #+#             */
/*   Updated: 2023/03/04 11:03:23 by carlosortiz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_map(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_errors("Wrong file !");
	close(fd);
}

void	setvalue(t_map *mlx)
{
	mlx->zoom = 20;
	mlx->z_zoom = 20;
	mlx->sin_angle = 30;
	mlx->cos_angle = 30;
	mlx->x_shift = 400;
	mlx->y_shift = 250;
}

void	putblack(t_map *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&mlx->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

int	onkeypress(int keycode, t_map *mlx)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		free_matrix(mlx);
		exit(0);
	}
	modifyvalue(keycode, mlx);
	putblack(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*mlx;

	if (ac != 2)
		print_errors("File missing !");
	check_map(av[1]);
	mlx = malloc(sizeof(t_map));
	if (!mlx)
		return (0);
	setvalue(mlx);
	create_map(mlx, av[1]);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "My window");
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L << 1, onkeypress, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 5, deletewindow, mlx);
	mlx_loop(mlx->mlx_ptr);
}
