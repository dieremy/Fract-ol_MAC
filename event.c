/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:46:56 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/14 09:46:59 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int mouse_hook(int button, int x, int y, t_fractal *d)
{
    if (button == 5)
    {
        d->y = y;
        d->x = x;
        d->zoom *= 1.1;
    }
    else if (button == 4)
    {
        d->y = y;
        d->x = x;
        d->zoom *= 0.9;
    }
    which_fract(d);
    return (0);  
}

int ft_key_press3(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == KEY_X)
    {
        write(1, "\nWELCOME HOME SON.\n", 19);
        mlx_destroy_window(d->mlx, d->win);
        free(d);
        exit(0);
    }
    else if (keycode == SHIFT_SX || keycode == SHIFT_DX)
    {
        d->shade -= 4000;
        which_fract(d);
    }
    else if (keycode == KEY_MINUS)
    { 
        d->zoom += 0.02;
        which_fract(d);
    }
    else if (keycode == KEY_PLUS)
    { 
        d->zoom -= 0.02;
        which_fract(d);
    }
    return (0);
}

int ft_key_press2(int keycode, t_fractal *d)
{
    if (keycode == KEY_M)
    {
        d->name = "Mandelbrot";
        which_fract(d);
    }
    else if (keycode == KEY_J)
    {
        d->name = "Julia";
        which_fract(d);
    }
    else if (keycode == KEY_D)
    {
        d->name = "Douady";
        which_fract(d);
    }
    else
        ft_key_press3(keycode, d);
    return (0);
}

int ft_key_press(int keycode, t_fractal *d)
{
    if (keycode == KEY_LEFT)
    { 
        d->x_shift -= 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_RIGHT)
    { 
        d->x_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_DOWN)
    {
        d->y_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_UP)
    { 
        d->y_shift -= 0.04;
        which_fract(d);
    }
    else
        ft_key_press2(keycode, d);
    return (0);
}

