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

	pos = (y * 1000) + x;
	env->data[pos] = color;
}

void    mand_plane(t_fractal *mBrot, int x, int y, int width, int height)
{
    mBrot->max_i = 1000;
    mBrot->i = 0;
    mBrot->cx = (x - width / 2.0) * 4.0 / width;
    mBrot->cy = (y - height / 2.0) * 4.0 / width;
    mBrot->zx = 0;
    mBrot->zy = 0;
}

void mandelbrot(t_fractal mBrot, int x, int y, int width, int height)
{
    double      xtemp;

    mand_plane(&mBrot, x, y, width, height);
    while (mBrot.zx * mBrot.zx + mBrot.zy * mBrot.zy < 4 && mBrot.i < mBrot.max_i)
    {
        xtemp = mBrot.zx * mBrot.zx - mBrot.zy * mBrot.zy + mBrot.cx;
        mBrot.zy = 2 * mBrot.zx * mBrot.zy + mBrot.cy;
        mBrot.zx = xtemp;
        mBrot.i++;
    }
    put_pixel_image(x, y, &mBrot, mBrot.i * VIOLET);
}

void    julia_plane(t_fractal *julia, int x, int y, int width, int height)
{
    // julia->zx = (x - width / 2.0) * 4.0 / width;
    // julia->zy = (y - height / 2.0) * 4.0 / width;
    double zoom_x;
    double zoom_y;
    double x1 = -1;
    double x2 = 1;
    double y1 = -1.2;
    double y2 = 1.2;

    zoom_x = width / (x2 - x1);
    zoom_y = height / (y2 - y1);
    julia->max_i = 200;
    julia->i = 0;
    julia->zx = x / zoom_x + x1;
    julia->zy = y / zoom_y + y1;
    julia->cx = -0.74543;
    julia->cy = 0.11301; 
}

void julia(t_fractal julia, int x, int y, int width, int height)
{
    double      xtemp;

    julia_plane(&julia, x, y, width, height);
    while (julia.zx * julia.zx + julia.zy * julia.zy < 4 && julia.i < julia.max_i)
    {
        xtemp = julia.zx;
        julia.zx = julia.zx * julia.zx - julia.zy * julia.zy + julia.cx; 
        julia.zy = 2 * xtemp * julia.zy + julia.cy;
        julia.i++;
    }
    put_pixel_image(x, y, &julia, julia.i * VIOLET);
}
