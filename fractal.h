/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:52:00 by robegarc          #+#    #+#             */
/*   Updated: 2023/02/10 10:52:05 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HW 1000

# include "minilibx_mms_20191025_beta/mlx.h"
# include "hook.h"
# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	double	zx; //Z's real part
	double	zy; //Z's imaginary part
	double	cx; //C's real part
	double	cy; //C's imaginary part
	double	x_start; //x1 negative(sx)
	double	x_end; //x2 positive(dx)
	double	y_start; //y1 negative(down)
	double	y_end; //y2 positive(up)
	double	zoom;
	double	x_shift;
	double	y_shift;
	float		x; //1. axis for nested cicle
	float		y; //2. axis for nested cicle
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		i;
	int		max_i;
	char	*name;
}				t_fractal;

void	put_pixel_image(int x, int y, t_fractal *d, int color);
void	zoom(t_fractal *d, double x, double y, double zoom);
void	which_fract(t_fractal *d);
void	julia_plane(t_fractal *julia);
void	mand_plane(t_fractal *mBrot);
void	mandelbrot(t_fractal *mBrot);
void	julia(t_fractal *julia);
void    mlx_look(t_fractal *d);
int		mouse_down(int button, double x, double y, t_fractal *d);
int		ft_key_press(int keycode, t_fractal *d);
int		ft_strcmp(char *s1, char *s2);

#endif
