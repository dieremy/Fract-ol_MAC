#include "fractal.h"

void    mand_plane(t_fractal *mBrot)
{
    mBrot->color = mBrot->i * BLUE + mBrot->shade;
    mBrot->max_i = 500;
    mBrot->i = 0;
    mBrot->cx = (mBrot->x / (HW / (mBrot->x_end - mBrot->x_start)) + mBrot->x_start) * mBrot->zoom + mBrot->x_shift; 
    mBrot->cy = (mBrot->y / (HW / (mBrot->y_end - mBrot->y_start)) + mBrot->y_start) * mBrot->zoom + mBrot->y_shift;
    mBrot->zx = 0;
    mBrot->zy = 0; 
}

void    julia_plane(t_fractal *julia)
{
    julia->color = julia->i * VIOLET + julia->shade;
    julia->max_i = 500;
    julia->i = 0;
    julia->zx = (julia->x / (HW / (julia->x_end - julia->x_start)) + julia->x_start) * julia->zoom + julia->x_shift;
    julia->zy = (julia->y / (HW / (julia->y_end - julia->y_start)) + julia->y_start) * julia->zoom + julia->y_shift;
    julia->cx = -0.74543;
    julia->cy = 0.11301; 
}

void    dou_plane(t_fractal *dou)
{
    dou->color = dou->i * BLACK + dou->shade;
    dou->max_i = 500;
    dou->i = 0;
    dou->zx = (dou->x / (HW / (dou->x_end - dou->x_start)) + dou->x_start) * dou->zoom + dou->x_shift;
    dou->zy = (dou->y / (HW / (dou->y_end - dou->y_start)) + dou->y_start) * dou->zoom + dou->y_shift;
    dou->cx = -0.12565651;
    dou->cy = 0.65720; 
}

void	put_pixel_image(int x, int y, t_fractal *d, int color)
{
	int pos;

	pos = (y * HW) + x;
	d->addr[pos] = color;
}