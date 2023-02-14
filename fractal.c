/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:09 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/10 10:52:14 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

// int ft_exit(int keycode, t_fractal *d)
// {
//     if (keycode == KEY_ESC)
//     {
//         mlx_destroy_window(d->mlx, d->win);
//         exit(1);
//     }
//     return (0);
// }

// int mouse_down(int button, double x, double y, t_fractal *d)
// {
//     if ( button == 5)
//         zoom(d, x, y, 1.1);
//     else if (button == 4)
//         zoom(d, x, y, 0.9);
//     return (1);  
// }

// int zoom(t_fractal *d, double x, double y, double zoom)
// {
//     double  x_x;
//     double  y_y;

//     x_x = ((d->x / HW) * (d->x_end - d->x_start) + d->x_start);
//     y_y = ((d->y / HW) * (d->y_end - d->y_start) + d->y_start);
//     d->x_start = x_x + ((d->x_start - x_x) * zoom);
//     d->y_start = y_y + ((d->y_start - y_y) * zoom);
//     d->y_end = y_y + ((d->y_end - y_y) * zoom);
//     d->x_end = x_x + ((d->x_end - x_x) * zoom);
//     return(1);
// }

void    which_fract(char *s, t_fractal *d)
{
    if (ft_strcmp(s, "Mandelbrot") == 0)
        mandelbrot(d);
    else if (ft_strcmp(s, "Julia") == 0)
        julia(d);
    else
    {
        write(1, "USAGE: ./fractol [fractal name]\n", 32);
        write(1, "OPTIONS: Mandelbrot\tJulia", 26);
        exit (1);
    }
}

int main(int ac, char **av)
{
    t_fractal   d;

    if (ac == 2)
    {
        d.mlx = mlx_init();
        d.win = mlx_new_window(d.mlx, HW, HW, "FRACTAL");
        d.img = mlx_new_image(d.mlx, HW, HW);
        d.addr = (int *)mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
        which_fract(av[1], &d);
        mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
        mlx_hook(d.win, 2, 0, ft_exit, &d);
        mlx_hook(d.win, 4, 1, mouse_down, &d);
        mlx_loop(d.mlx);
    }
    else
    {
        write(1, "USAGE: ./fractol [fractal name]\n", 32);
        write(1, "OPTIONS: Mandelbrot\tJulia", 26);
    }
    return (0);
}
