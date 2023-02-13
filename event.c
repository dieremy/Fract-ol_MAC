#include "fractal.h"

int mouse_down(int button, double x, double y, t_fractal *d)
{
    if ( button == 5)
        zoom(d, x, y, 1.1);
    else if (button == 4)
        zoom(d, x, y, 0.9);
    return (1);  
}

int zoom(t_fractal *d, double x, double y, double zoom)
{
    double  x_x;
    double  y_y;

    x_x = ((d->x / HW) * (d->x_end - d->x_start) + d->x_start);
    y_y = ((d->y / HW) * (d->y_end - d->y_start) + d->y_start);
    d->x_start = x_x + ((d->x_start - x_x) * zoom);
    d->y_start = y_y + ((d->y_start - y_y) * zoom);
    d->y_end = y_y + ((d->y_end - y_y) * zoom);
    d->x_end = x_x + ((d->x_end - x_x) * zoom);
}

int ft_exit(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(1);
    }
    return (0);
}