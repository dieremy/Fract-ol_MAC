/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:09 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/10 10:52:14 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_mms_20191025_beta/mlx.h"
#include "fractal.h"

t_fractal   *create_struct(void)
{
    t_fractal   *elem;

    elem = malloc(sizeof(t_fractal));
    return (elem);
}

int close(int keycode, t_fractal *d)
{
    if (keycode == KEY_ESC || keycode == 17)
    {
        mlx_destroy_window(d->mlx, d->win);
        exit(1);
    }
    return (0);
}

int zoom(int button, double x, double y, t_fractal *d)
{
    if (button == 5)
    {
        x *= 1.1;
        y *= 1.1;
    }
    return (0);
}

int mandelbrot(int x, int y, int width, int height)
{
    t_fractal  mBrot;
    double      xtemp;
    int         max_i;
    int         i;

    max_i = 1000;
    i = 0;
    // mBrot = create_struct();
    mBrot.x0 = (x - width / 2.0) * 4.0 / width;
    mBrot.y0 = (y - height / 2.0) * 4.0 / width;
    mBrot.x_ = 0;
    mBrot.y_ = 0;
    while (mBrot.x_ * mBrot.x_ + mBrot.y_ * mBrot.y_ < 4 && i < max_i)
    {
        xtemp = mBrot.x_ * mBrot.x_ - mBrot.y_ * mBrot.y_ + mBrot.x0;
        mBrot.y_ = 2 * mBrot.x_ * mBrot.y_ + mBrot.y0;
        mBrot.x_ = xtemp;
        i++;
    }
    if (i == max_i)
        return 0;
    else
        return i * WHITE / max_i;
}

// int julia(int x, int y, int width, int height)
// {
//     t_fractal  julia;
//     double      xtemp;
//     int         max_i;
//     int         i;

//     max_i = 1000;
//     i = 0;
//     julia.x0 = (x - width / 2.0) * 4.0 / width;
//     julia.y0 = (y - height / 2.0) * 4.0 / width;
//     julia.x_ = -0.41;
//     julia.y_ = 0.6;
//     while (julia.x0 * julia.x0 + julia.y0 * julia.y0 < 4 && i < max_i)
//     {
//         xtemp = julia.x0 * julia.x0 - julia.y0 * julia.y0;
//         julia.y0 = 2 * julia.x0 * julia.y0 + julia.y_;
//         julia.x0 = xtemp + julia.x_;
//         i++;
//     }
//     if (i == max_i)
//         return 0;
//     else
//         return i * WHITE / max_i;
// }

int julia(int x, int y, int width, int height)
{
    t_fractal  julia;
    double      xtemp;
    int         max_i;
    int         i;

    max_i = 1000;
    i = 1;
    julia.x0 = (x - width / 2.0) * 4.0 / width;
    julia.y0 = (y - height / 2.0) * 4.0 / width;
    julia.x_ = -0.74543;
    julia.y_ = 0.11301;
    while (julia.x0 * julia.x0 + julia.y0 * julia.y0 < 4 && i < max_i)
    {
        xtemp = julia.x0;
        julia.x0 = julia.x0 * julia.x0 - julia.y0 * julia.y0 + julia.x_; 
        julia.y0 = 2 * xtemp * julia.y0 + julia.y_;
        i++;
    }
    if (i != max_i)
        return i * WHITE / max_i;
    else
        return (0);
}

void    my_mlx_pixel_put(t_fractal *d, int i, int j, int color)
{
    char    *dst;

    dst = d->addr + (j * d->line_length + i * (d->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int main()
{
    t_fractal   d;
    int         i;
    int         j;

    d.mlx = mlx_init();
    d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, "FRACTAL");
    d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
    d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_length, &d.endian);
    i = -1;
    while (++i < WIDTH)
    {
        j = -1;
        while (++j < WIDTH)
        {
            d.color = julia(i, j, WIDTH, HEIGHT);
            my_mlx_pixel_put(&d, i, j, d.color);
        }
    }
    mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
    mlx_hook(d.win, 2, 0, close, &d);
    //mlx_hook(d.win, 4, 1L << 2, zoom, &d);
    mlx_loop(d.mlx);
    return (0);
}
