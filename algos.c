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

void	put_pixel_image(int x, int y, t_fractal *d, int color)
{
	int pos;

	pos = (y * HW) + x;
	d->addr[pos] = color;
}

void    mand_plane(t_fractal *mBrot)
{
    mBrot->color = mBrot->i * BLUE + mBrot->shade;
    mBrot->max_i = 500;
    mBrot->i = 0;
    mBrot->x_start = -2.0;
    mBrot->x_end = 2.0;
    mBrot->y_start = -2.0;
    mBrot->y_end = 2.0;
    mBrot->cx = (mBrot->x / (HW / (mBrot->x_end - mBrot->x_start)) + mBrot->x_start) * mBrot->zoom + mBrot->x_shift; 
    mBrot->cy = (mBrot->y / (HW / (mBrot->y_end - mBrot->y_start)) + mBrot->y_start) * mBrot->zoom + mBrot->y_shift;
    mBrot->zx = 0;
    mBrot->zy = 0; 
}

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

void    julia_plane(t_fractal *julia)
{
    julia->color = julia->i * VIOLET + julia->shade;
    julia->max_i = 500;
    julia->i = 0 + julia->iterations;
    julia->x_start = -1;
    julia->x_end = 1;
    julia->y_start = -1.2;
    julia->y_end = 1.2;
    julia->zx = (julia->x / (HW / (julia->x_end - julia->x_start)) + julia->x_start) * julia->zoom + julia->x_shift;
    julia->zy = (julia->y / (HW / (julia->y_end - julia->y_start)) + julia->y_start) * julia->zoom + julia->y_shift;
    julia->cx = -0.74543;
    julia->cy = 0.11301; 
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

void    dou_plane(t_fractal *dou)
{
    dou->color = dou->i * BLACK + dou->shade;
    dou->max_i = 500;
    dou->i = 0 + dou->iterations;
    dou->x_start = -2.2;
    dou->x_end = 2.0;
    dou->y_start = -2.2;
    dou->y_end = 2.0;
    dou->zx = (dou->x / (HW / (dou->x_end - dou->x_start)) + dou->x_start) * dou->zoom + dou->x_shift;
    dou->zy = (dou->y / (HW / (dou->y_end - dou->y_start)) + dou->y_start) * dou->zoom + dou->y_shift;
    dou->cx = -0.12565651;
    dou->cy = 0.65720; 
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
