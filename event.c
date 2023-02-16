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

int mouse_down(int button, long double x, long double y, t_fractal *d)
{
    if (button == 5)
        zoom(d);
    // {
    //     d->zoom *= d->scaling;
    //     which_fract(d);
    // }
    else if (button == 4)
        zoom(d);
    // {
    //     d->zoom /= d->scaling;
    //     which_fract(d);
    // }
    which_fract(d);
    return (0);  
}

void    mlx_look(t_fractal *d)
{
    mlx_hook(d->win, 2, 4, ft_key_press, d);
    mlx_hook(d->win, 4, 3, mouse_down, d);
    mlx_mouse_hook(d->win, mouse_down, d);
    mlx_loop(d->mlx);
}

void zoom(t_fractal *d)
{
    double  x_x;
    double  y_y;

    x_x = ((d->x / HW) * (d->x_end - d->x_start) + d->x_start);
    y_y = ((d->y / HW) * (d->y_end - d->y_start) + d->y_start);
    d->x_start = x_x + ((d->x_start - x_x) / (d->zoom * d->scaling));
    d->y_start = y_y + ((d->y_start - y_y) / (d->zoom * d->scaling));
    d->y_end = y_y + ((d->y_end - y_y)  / (d->zoom * d->scaling));
    d->x_end = x_x + ((d->x_end - x_x)  / (d->zoom * d->scaling));
}
int ft_key_press3(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == KEY_X)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(0);
    }
    else if (keycode == SHIFT_SX || keycode == SHIFT_DX)
    {
        d->shade -= 4000;
        which_fract(d);
    }
    else if (keycode == KEY_MINUS)
    { //minus
        d->zoom += 0.02;
        which_fract(d);
    } //1.2 / 2.0;//2.0 / 1.0;// + d->y_shift;
    else if (keycode == KEY_PLUS)
    { //plus
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
    else if (keycode == KEY_B)
    {
        d->name = "Burningship";
        which_fract(d);
    }
    else
        ft_key_press3(keycode, d);
    return (0);
}

int ft_key_press(int keycode, t_fractal *d)
{
    // printf("%d\n", keycode);
    if (keycode == KEY_LEFT)
    { //sx
        d->x_shift -= 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_RIGHT)
    { //dx
        d->x_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_DOWN)
    { //down
        d->y_shift += 0.04;
        which_fract(d);
    }
    else if (keycode == KEY_UP)
    { //up
        d->y_shift -= 0.04;
        which_fract(d);
    }
    // else if (keycode == KEY_Z)
    // { //up
    //     which_fract(d);
    // }
    else
        ft_key_press2(keycode, d);
    return (0);
}

