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

void	put_pixel_image(int x, int y, t_fractal *env, int color)
{
	int pos;

	pos = (y * HW) + x;
	env->addr[pos] = color;
}

void    mand_plane(t_fractal *mBrot)
{
    mBrot->max_i = 1000;
    mBrot->i = 0;
    mBrot->x_start = -2.10;
    mBrot->x_end = 0.6;
    mBrot->y_start = -1.2;
    mBrot->y_end = 1.2;
    mBrot->cx = mBrot->x / (HW / (mBrot->x_end - mBrot->x_start)) + mBrot->x_start;
    mBrot->cy = mBrot->y / (HW / (mBrot->y_end - mBrot->y_start)) + mBrot->y_start;
    mBrot->zx = 0;
    mBrot->zy = 0; 
}

void mandelbrot(t_fractal *mBrot)
{
    double      xtemp;

    mBrot->x = 0;
    while (mBrot->x < HW)
    {
        mBrot->y = 0;
        while (mBrot->y < HW)
        {
            mand_plane(mBrot);
            while (mBrot->zx * mBrot->zx + mBrot->zy * mBrot->zy < 4 && mBrot->i < mBrot->max_i)
            {
                xtemp = mBrot->zx * mBrot->zx - mBrot->zy * mBrot->zy + mBrot->cx;
                mBrot->zy = 2 * mBrot->zx * mBrot->zy + mBrot->cy;
                mBrot->zx = xtemp;
                mBrot->i++;
            }
            put_pixel_image(mBrot->x, mBrot->y, mBrot, mBrot->i * VIOLET);
            mBrot->y++;
        }
        mBrot->x++;
    }
}

void    julia_plane(t_fractal *julia)
{
    julia->max_i = 1000;
    julia->i = 0;
    julia->x_start = -1;
    julia->x_end = 1;
    julia->y_start = -1.2;
    julia->y_end = 1.2;
    julia->zx = julia->x / (HW / (julia->x_end - julia->x_start)) + julia->x_start;
    julia->zy = julia->y / (HW / (julia->y_end - julia->y_start)) + julia->y_start;
    julia->cx = -0.74543;
    julia->cy = 0.11301; 
}

void julia(t_fractal *julia)
{
    double      xtemp;

    julia->x = 0;
    while (julia->x < HW)
    {
        julia->y = 0;
        while (julia->y < HW)
        {
            julia_plane(julia);
            while (julia->zx * julia->zx + julia->zy * julia->zy < 4 && julia->i < julia->max_i)
            {
                xtemp = julia->zx;
                julia->zx = julia->zx * julia->zx - julia->zy * julia->zy + julia->cx;
                julia->zy = 2 * xtemp * julia->zy + julia->cy;
                julia->i++;
            }
            put_pixel_image(julia->x, julia->y, julia, julia->i * VIOLET);
            julia->y++;
        }
        julia->x++;
    }
}
