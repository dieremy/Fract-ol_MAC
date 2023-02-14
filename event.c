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

// int mouse_down(int button, double x, double y, t_fractal *d)
// {
//     if (button == 5)
//         zoom(d, x, y, 1.1);
//     else if (button == 4)
//         zoom(d, x, y, 0.9);
//     return (1);  
// }

void    mlx_look(t_fractal *d)
{
    mlx_hook(d->win, 2, 0, ft_key_press, d);
    // mlx_hook(d.win, 4, 1, mouse_down, &d);
    mlx_loop(d->mlx);
}

// void zoom(t_fractal *d, double x, double y, double zoom)
// {
//     double  x_x;
//     double  y_y;

//     x_x = ((x / HW) * (d->x_end - d->x_start) + d->x_start);
//     y_y = ((y / HW) * (d->y_end - d->y_start) + d->y_start);
//     d->x_start = x_x + ((d->x_start - x_x) * zoom);
//     d->y_start = y_y + ((d->y_start - y_y) * zoom);
//     d->y_end = y_y + ((d->y_end - y_y) * zoom);
//     d->x_end = x_x + ((d->x_end - x_x) * zoom);
// }

void    zoomP(t_fractal *d)
{
    if (d->x_start < 0 && d->y_start < 0 && d->x_end > 0 && d->y_end > 0)
    {
        d->x_start += 0.015;
        d->y_start += 0.015;
        d->x_end -= 0.015;
        d->y_end -= 0.015;
    }
}

void    zoomM(t_fractal *d)
{
        d->x_start -= 0.040;
        d->y_start -= 0.040;
        d->x_end += 0.040;
        d->y_end += 0.040;
}

int ft_key_press(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(0);
    }
    else if (keycode == 69)
    {
        d->zoom *= 2;
        which_fract(d);
    }
    else if (keycode == 78)
    {
        d->zoom /= 2;
        which_fract(d);
    }
    else if (keycode == 123)
    {
        d->x_shift -= 0.2;
        which_fract(d);
    }
    else if (keycode == 124)
    {
        d->x_shift = 0.2;
        which_fract(d);
    }
    else if (keycode == 125)
    {
        d->y_shift += 0.2;
        which_fract(d);
    }
    else if (keycode == 126)
    {
        d->y_shift -= 0.2;
        which_fract(d);
    }
    return (0);
}
