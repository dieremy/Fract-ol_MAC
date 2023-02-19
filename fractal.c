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

void    id(char *s, t_fractal *d)
{
    d->name = s;
    d->zoom = 1;
    d->x_shift = 0;
    d->y_shift = 0;
    d->shade = 0;
    d->x_start = -2.0;
    d->x_end = 2.0;
    d->y_start = -2.0;
    d->y_end = 2.0;
}

void    which_fract(t_fractal *d)
{
    if (ft_strcmp(d->name, "Mandelbrot") != 0 && ft_strcmp(d->name, "Julia") != 0 && ft_strcmp(d->name, "Douady") != 0)
    {
        write(1, "USAGE: ./fractal", 16);
        write(1, "\tMandelbrot\tJulia\tDouady", 24);
        exit(0);
    }
    if (ft_strcmp(d->name, "Mandelbrot") == 0)
        mandelbrot(d);
    else if (ft_strcmp(d->name, "Julia") == 0)
        julia(d);
    else if (ft_strcmp(d->name, "Douady") == 0)
        douady(d);
}
t_fractal   *create_struct()
{
    t_fractal   *out;

    out = (t_fractal *)malloc(sizeof(t_fractal));
    return (out);
}

int main(int ac, char **av)
{
    t_fractal   *d;

    if (ac == 2)
    {
        d = create_struct();
        description(ac, av);
        d->mlx = mlx_init();
        d->win = mlx_new_window(d->mlx, HW, HW, "FRACT'OL");
        d->img = mlx_new_image(d->mlx, HW, HW);
        d->addr = (int *)mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
        id(av[1], d);
        which_fract(d);
    }
    else
    {
        write(1, "USAGE: ./fractal", 16);
        write(1, "\tMandelbrot\tJulia\tDouady", 29);
    }
    return (0);
}
