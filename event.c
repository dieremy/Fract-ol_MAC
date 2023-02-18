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
    // printf("d--------->%p\n", (void*)d);
    printf("%d\n", button);
    if (button == 5)
    {
        d->y = y;
        d->x = x;
        d->zoom += 0.02;
    }
    else if (button == 4)
    {
        d->y = y;
        d->x = x;
        d->zoom -= 0.02;
    }
    which_fract(d);
    return (0);  
}

void    mlx_look(t_fractal *d)
{
    mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
    mlx_key_hook(d->win, ft_key_press, d);
    mlx_mouse_hook(d->win, mouse_hook, d);
    mlx_loop(d->mlx);
    free(d);
}

int ft_key_press3(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == KEY_X)
    {
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
    { //minus
        d->zoom += 0.02;
        which_fract(d);
    }
    else if (keycode == KEY_PLUS)
    { //plus
        d->zoom -= 0.02;
        which_fract(d);
    }
    return (0);
}

int ft_key_press2(int keycode, t_fractal *d)
{
    // printf("d--------->%p\n", (void*)d);
    // printf("keycode---->%d\n", keycode);
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
    // printf("%f\n", d->zoom);
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
    else
        ft_key_press2(keycode, d);
    return (0);
}

