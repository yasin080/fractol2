/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahri <ybahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:33:32 by ybahri            #+#    #+#             */
/*   Updated: 2024/05/22 12:43:03 by ybahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problems with Malloc");
	exit(EXIT_FAILURE);
}
static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress,
			KeyPressMask,
			key_handler, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress,
			ButtonPressMask, mouse_handler,
			fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify,
			StructureNotifyMask, close_handler,
			fractol);
	mlx_hook(fractol->mlx_window, MotionNotify,
			PointerMotionMask, julia_track,
			fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_conx = mlx_init();
	if (NULL == fractol->mlx_conx)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_conx,
										WIDTH, HEIGHT, fractol->name);
	if (NULL == fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_conx);
		free(fractol->mlx_conx);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_conx, WIDTH, HEIGHT);
	if (NULL == fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_conx, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_conx);
		free(fractol->mlx_conx);
		malloc_error();
	}
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
												&fractol->img.bpp,
												&fractol->img.line_len,
												&fractol->img.endian);
	events_init(fractol);
	data_init(fractol);
}
