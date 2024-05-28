/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahri <ybahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:33:36 by ybahri            #+#    #+#             */
/*   Updated: 2024/05/23 12:01:24 by ybahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	fractol;
int main(int ac, char **av)
{
	if ((2 == ac && (!ft_strcmp(av[1], "mandelbrot"))) || \
	(4 == ac && !ft_strcmp(av[1], "julia")))
	{
		fractol.name = av[1];
		fractol.julia_x = atodbl(av[2]);
		fractol.julia_y = atodbl(av[3]);
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_conx);
	}

	else
	{
		write(2, ERROR_MESSAGE, ft_strlen(ERROR_MESSAGE));
		exit(EXIT_FAILURE);
	}
}
