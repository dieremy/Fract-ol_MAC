/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:33:38 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/12 13:33:42 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void mandelbrot(t_fractal *mBrot)
{
    mBrot->x = -1;
    while (++mBrot->x < HW)
    {
        mBrot->y = -1;
        while (++mBrot->y < HW)
        {
            mand_plane(mBrot);
            while (mBrot->zx * mBrot->zx + mBrot->zy * mBrot->zy < 4 && mBrot->i < mBrot->max_i)
            {
                mBrot->tmp = mBrot->zx * mBrot->zx - mBrot->zy * mBrot->zy + mBrot->cx;
                mBrot->zy = 2 * mBrot->zx * mBrot->zy + mBrot->cy;
                mBrot->zx = mBrot->tmp;
                mBrot->i++;
            }
            put_pixel_image(mBrot->x, mBrot->y, mBrot, mBrot->color);
        }
    }
    mlx_look(mBrot);
}

void julia(t_fractal *julia)
{
    julia->x = -1;
    while (++julia->x < HW)
    {
        julia->y = -1;
        while (++julia->y < HW)
        {
            julia_plane(julia);
            while (julia->zx * julia->zx + julia->zy * julia->zy < 4 && julia->i < julia->max_i)
            {
                julia->tmp = julia->zx;
                julia->zx = julia->zx * julia->zx - julia->zy * julia->zy + julia->cx;
                julia->zy = 2 * julia->tmp * julia->zy + julia->cy;
                julia->i++;
            }
            put_pixel_image(julia->x, julia->y, julia, julia->color);
        }
    }
    mlx_look(julia);
}

void douady(t_fractal *dou)
{
    dou->x = -1;
    while (++dou->x < HW)
    {
        dou->y = -1;
        while (++dou->y < HW)
        {
            dou_plane(dou);
            while (dou->zx * dou->zx + dou->zy * dou->zy < 4 && dou->i < dou->max_i)
            {
                dou->tmp = dou->zx;
                dou->zx = dou->zx * dou->zx - dou->zy * dou->zy + dou->cx;
                dou->zy = 2 * dou->tmp * dou->zy + dou->cy;
                dou->i++;
            }
            put_pixel_image(dou->x, dou->y, dou, dou->color);
        }
    }
    mlx_look(dou);
}

void    mlx_look(t_fractal *d)
{
    mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
    str_put(d);
    mlx_key_hook(d->win, ft_key_press, d);
    mlx_hook(d->win, 17, 1L<<0, ft_close, d);
    mlx_mouse_hook(d->win, mouse_hook, d);
    mlx_loop(d->mlx);
    free(d);
}