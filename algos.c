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
    double      xtemp;

    mBrot->x = -1;
    while (++mBrot->x < HW)
    {
        mBrot->y = -1;
        while (++mBrot->y < HW)
        {
            mand_plane(mBrot);
            while (mBrot->zx * mBrot->zx + mBrot->zy * mBrot->zy < 4 && mBrot->i < mBrot->max_i)
            {
                xtemp = mBrot->zx * mBrot->zx - mBrot->zy * mBrot->zy + mBrot->cx;
                mBrot->zy = 2 * mBrot->zx * mBrot->zy + mBrot->cy;
                mBrot->zx = xtemp;
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
    double      xtemp;

    julia->x = -1;
    while (++julia->x < HW)
    {
        julia->y = -1;
        while (++julia->y < HW)
        {
            julia_plane(julia);
            while (julia->zx * julia->zx + julia->zy * julia->zy < 4 && julia->i < julia->max_i)
            {
                xtemp = julia->zx;
                julia->zx = julia->zx * julia->zx - julia->zy * julia->zy + julia->cx;
                julia->zy = 2 * xtemp * julia->zy + julia->cy;
                julia->i++;
            }
            put_pixel_image(julia->x, julia->y, julia, julia->color);
        }
    }
    mlx_look(julia);
}

void    burn_plane(t_fractal *burn)
{
    burn->color = burn->i * BLACK + burn->shade;
    burn->max_i = 500;
    burn->i = 0 + burn->iterations;
    burn->x_start = -2.2;
    burn->x_end = 2.0;
    burn->y_start = -2.2;
    burn->y_end = 2.0;
    burn->cx = (burn->x / (HW / (burn->x_end - burn->x_start)) + burn->x_start) * burn->zoom + burn->x_shift;
    burn->cy = (burn->y / (HW / (burn->y_end - burn->y_start)) + burn->y_start) * burn->zoom + burn->y_shift;
    burn->zx = 0;
    burn->zy = 0; 
}

int ft_abs(int n)
{
    if (n < 0)
        n *= -1;
    return (n);
}

void burningship(t_fractal *burn)
{
    double      xtemp;

    burn->x = -1;
    while (++burn->x < HW)
    {
        burn->y = -1;
        while (++burn->y < HW)
        {
            burn_plane(burn);
            while (burn->zx * burn->zx + burn->zy * burn->zy < 4 && burn->i < burn->max_i)
            {
                xtemp = burn->zx * burn->zx - burn->zy * burn->zy + burn->cx;
                burn->zy = ft_abs(2 * burn->zx * burn->zy) + burn->cy;
                burn->zx = xtemp;
                burn->i++;
            }
            put_pixel_image(burn->x, burn->y, burn, burn->color);
        }
    }
    mlx_look(burn);
}
