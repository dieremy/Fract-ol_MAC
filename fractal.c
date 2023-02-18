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
    d->scaling = 1.2;
}

void    description(int ac, char **av)
{
    if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "Burningship") == 0)
    {
        write(1, "KEYBOARD SHORCUTS\n\n", 20);
        write(1, "CLOSE THE PROGRAM:\tX/ESC\n", 25);
        write(1, "CHANGE COLOR SHADE:\tSHIFT\n", 26);
        write(1, "MOVE FRACTAL:\t\tARROW-LEFT/ARROW-RIGHT/ARROW-UP/ARROW-DOWN\n", 58);
        write(1, "ZOOM/UNZOOM:\t\tPLUS/MINUS\n", 25);
        write(1, "CHANGE TO JULIA:\tJ\n", 19);
        write(1, "CHANGE TO MANDELBROT:\tM\n", 24);
        write(1, "CHANGE TO BURNINGSHIP:\tB\n", 25);
    }
}

void    which_fract(t_fractal *d)
{
    if (ft_strcmp(d->name, "Mandelbrot") != 0 && ft_strcmp(d->name, "Julia") != 0 && ft_strcmp(d->name, "Burningship") != 0)
    {
        write(1, "USAGE: ./fractal", 16);
        write(1, "\tMandelbrot\tJulia\tBurningship", 29);
        exit(0);
    }
    if (ft_strcmp(d->name, "Mandelbrot") == 0)
        mandelbrot(d);
    else if (ft_strcmp(d->name, "Julia") == 0)
        julia(d);
    else if (ft_strcmp(d->name, "Burningship") == 0)
        burningship(d);
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
        d->win = mlx_new_window(d->mlx, HW, HW, "FRACTAL");
        d->img = mlx_new_image(d->mlx, HW, HW);
        d->addr = (int *)mlx_get_data_addr(d->img, &d->bits_per_pixel, &d->line_length, &d->endian);
        id(av[1], d);
        which_fract(d);
    }
    else
    {
        write(1, "USAGE: ./fractal", 16);
        write(1, "\tMandelbrot\tJulia\tBurningship", 29);
    }
    return (0);
}
