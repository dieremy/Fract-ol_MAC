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

# define HEIGHT 1000
# define WIDTH 1000

# include "hook.h"
# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fractal
{
	int		color;
	void	*mlx;
	void	*win;
	double	y0;
	double	x0;
	double	y_;
	double	x_;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_fractal;

// typedef struct s_data
// {
	
// }				t_data;

#endif
