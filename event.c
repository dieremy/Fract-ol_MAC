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

int mouse_down(int button, double x, double y, t_fractal *d)
{
    if (button == 5)
        zoom(d, x, y, 1.1);
    else if (button == 4)
        zoom(d, x, y, 0.9);
    return (1);  
}

void    mlx_look(t_fractal *d)
{
    mlx_hook(d->win, 2, 0, ft_key_press, d);
    mlx_hook(d->win, 4, 1, mouse_down, &d);
    mlx_loop(d->mlx);
}

void zoom(t_fractal *d, double x, double y, double zoom)
{
    double  x_x;
    double  y_y;

    x_x = ((x / HW) * (d->x_end - d->x_start) + d->x_start);
    y_y = ((y / HW) * (d->y_end - d->y_start) + d->y_start);
    d->x_start = x_x + ((d->x_start - x_x) * zoom);
    d->y_start = y_y + ((d->y_start - y_y) * zoom);
    d->y_end = y_y + ((d->y_end - y_y) * zoom);
    d->x_end = x_x + ((d->x_end - x_x) * zoom);
}


int ft_key_press(int keycode, t_fractal *d)
{
    // printf("%d\n", keycode);
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(0);
    }
    else if (keycode == KEY_PLUS) //plus
        d->zoom -= 0.02; //1.2 / 2.0; //2.0 / 0.01;// + d->x_shift;
        // 1.0/mBrot->zoom + mBrot->x_shift
    else if (keycode == KEY_MINUS) //minus
        // d->zoom /= 2.0;
        d->zoom += 0.02; //1.2 / 2.0;//2.0 / 1.0;// + d->y_shift;
    else if (keycode == KEY_LEFT) //sx
        d->x_shift -= 0.02;
    else if (keycode == KEY_RIGHT) //dx
        d->x_shift += 0.02;
    else if (keycode == KEY_DOWN) //down
        d->y_shift += 0.02;
    else if (keycode == KEY_UP) //up
        d->y_shift -= 0.02;
    which_fract(d);
    return (0);
}
