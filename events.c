/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahri <ybahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:55:58 by ybahri            #+#    #+#             */
/*   Updated: 2024/05/23 12:09:11 by ybahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_conx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_conx, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_conx);
	free(fractol->mlx_conx);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_plus)
		fractol->iterations += 10;
	else if (keysym == XK_minus)
		fractol->iterations -= 10;
	fractol_render(fractol);
	return 0;
}

int	mouse_handler(int button, t_fractol *fractol)
{
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return 0;
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "julia"))
	{
		fractol->julia_x = map(x, -2, +2, WIDTH) * fractol->zoom + fractol->shift_x;
		fractol->julia_y = map(y, +2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
		fractol_render(fractol);
	}
	return 0;
}
