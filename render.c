/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahri <ybahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:33:26 by ybahri            #+#    #+#             */
/*   Updated: 2024/05/22 12:39:42 by ybahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_or_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;

	z.x = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, WIDTH) * fractol->zoom) + fractol->shift_y;

	mandel_or_julia(&z, &c, fractol);

	while (i < fractol->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, fractol->iterations);
			pixel_put(x, y, &fractol->img, color);
			return;
		}
		++i;
	}
	pixel_put(x, y, &fractol->img, PSYCHEDELIC_PURPLE);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_conx, fractol->mlx_window,
						fractol->img.img_ptr, 0, 0);
}
