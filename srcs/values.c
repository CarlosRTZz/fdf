#include "fdf.h"

void    zoom(t_point *a, t_point *b, t_map *mlx)
{
    a->x *= mlx->zoom;
    a->y *= mlx->zoom;
    b->x *= mlx->zoom;
    b->y *= mlx->zoom;
}

void    set_color(int z1, int z2, t_map *mlx)
{
    if (z1 || z2)
        mlx->color = 0xe80c0c;
    else
        mlx->color = 0xFFFFFF;
}

void    shifting(t_point *a, t_point *b, t_map *mlx)
{
    a->x += mlx->x_shift;
    a->y += mlx->y_shift;
    b->x += mlx->x_shift;
    b->y += mlx->y_shift;
}

void    arrows(int keycode, t_map *mlx)
{
    if (keycode == UP)
        mlx->y_shift -= 5;
    if (keycode == DOWN)
        mlx->y_shift += 5;
    if (keycode == LEFT)
        mlx->x_shift -= 5;
    if (keycode == RIGHT)
        mlx->x_shift += 5;
}

void    modifyvalue(int keycode, t_map *mlx)
{
    arrows(keycode, mlx);
    if (keycode == EIGHT)
    {
        mlx->cos_angle += 2;
        mlx->sin_angle += 2;
    }
    if (keycode == TWO)
    {
        mlx->cos_angle -= 2;
        mlx->sin_angle -= 2;
    }
    if (keycode == FOUR)
        mlx->sin_angle -= 2;
    if (keycode == SIX)
        mlx->sin_angle += 2;
    if (keycode == PLUS)
        mlx->z_zoom += 2;
    if (keycode == MINUS)
        mlx->z_zoom -= 2;
    if (keycode == J)
        mlx->zoom += 2;
    if (keycode == H)
        mlx->zoom -= 2;
}
