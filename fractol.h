/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahri <ybahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:33:49 by ybahri            #+#    #+#             */
/*   Updated: 2024/05/23 12:15:55 by ybahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

#define ERROR_MESSAGE "Please enter:\n\"./fractol mandelbrot\"\n" \
						"or\n\"./fractol julia <real> <imaginary>\"\n"
#define WIDTH	800
#define HEIGHT	800

#define BLACK					0x000000
#define WHITE					0xFFFFFF
#define RED						0xFF0000
#define GREEN					0x00FF00
#define BLUE					0x0000FF
#define MAGENTA_BURST			0xFF00FF
#define LIME_SHOCK				0xCCFF00
#define NEON_ORANGE				0xFF6600
#define PSYCHEDELIC_PURPLE		0x660066
#define AQUA_DREAM				0x33CCCC
#define HOT_PINK				0xFF66B2
#define ELECTRIC_BLUE			0x0066FF
#define LAVA_RED				0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}					t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_conx;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}					t_fractol;

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strlen(char *str);
void		fractol_init(t_fractol *fractol);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		fractol_render(t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_handler(int button, t_fractol *fractol);
double		atodbl(char *s);
int			julia_track(int x, int y, t_fractol *fractol);

#endif
