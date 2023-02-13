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

#include "minilibx_mms_20191025_beta/mlx.h"
#include "fractal.h"

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int ft_exit(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(0);
    }
    return (0);
}

int zoom(int button, double x, double y, t_fractal *d)
{
    if (button == 5)
    {
        x *= 1.1;
        y *= 1.1;
    }
    return (0);
}

void    which_fract(char *s, t_fractal d)
{
    if (ft_strcmp(s, "Mandelbrot") == 0)
        mandelbrot(d);
    else if (ft_strcmp(s, "Julia") == 0)
        julia(d);
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
        which_fract(av[1], d);
        mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
        mlx_hook(d.win, 2, 0, ft_exit, &d);
        mlx_loop(d.mlx);
    }
    else
    {
        write(1, "USAGE: ./fractol [fractal name]\n", 32);
        write(1, "OPTIONS: Mandelbrot\tJulia", 26);
    }
    return (0);
}
