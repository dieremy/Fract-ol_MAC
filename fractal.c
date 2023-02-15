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

void    id(char *s, t_fractal *d)
{
    d->name = s;
    d->zoom = 1;
    d->x_shift = 0;
    d->y_shift = 0;
    d->shade = 0;
}

void    which_fract(t_fractal *d)
{
    if (ft_strcmp(d->name, "Mandelbrot") == 0)
        mandelbrot(d);
    else if (ft_strcmp(d->name, "Julia") == 0)
        julia(d);
    else
    {
        write(1, "USAGE: ./fractol [fractal name]\n", 32);
        write(1, "OPTIONS: Mandelbrot || Julia\n", 29);
        exit(0);
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
        id(av[1], &d);
        which_fract(&d);
    }
    else
    {
        write(1, "USAGE: ./fractol [fractal name]\n", 32);
        write(1, "OPTIONS: Mandelbrot || Julia\n", 29);
    }
    return (0);
}
