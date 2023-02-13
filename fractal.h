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
	float	zoom_y;
	float	zoom_x;
	float		x; //1. axis for nested cicle
	float		y; //2. axis for nested cicle
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		i;
	int		max_i;
}				t_fractal;

void	mandelbrot(t_fractal mBrot);
void	julia_plane(t_fractal *julia);
void	mand_plane(t_fractal *mBrot);
void	julia(t_fractal julia);
void	put_pixel_image(int x, int y, t_fractal *env, int color);
void	which_fract(char *s, t_fractal d);
int		zoom(int button, double x, double y, t_fractal *d);
int		ft_exit(int keycode, t_fractal *d);
int		ft_strcmp(char *s1, char *s2);

#endif
