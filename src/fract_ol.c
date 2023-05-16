/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:21:45 by cnikdel           #+#    #+#             */
/*   Updated: 2023/05/17 00:23:15 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	mandelbrot(t_ptr var)
{
	t_ima	pixel;
	t_ima	zn;
	t_ima	znext;
	t_indexer	index;

	initindex(&index, var);
	while (index.y++ < var.height)
	{
		while (index.x++ < var.width)
		{
			resetmand(&index, &pixel, &znext, var);
			while (index.i++ < index.maxit)
			{
				compmand(&zn, &znext, &pixel);
				if (powf(znext.reel, 2) + powf(znext.imag, 2) > 4)
					break;
			}
			coloring(var, index);
		}
		index.x = 0;
	}
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
}

void	mafractale(t_ptr var)
{
	t_ima	pixel;
	t_ima	zn;
	t_ima	znext;
	t_ima	zbef2;
	t_indexer	index;

	initindex(&index, var);
	while (index.y++ < var.height)
	{
		while (index.x++ < var.width)
		{
			resetmand(&index, &pixel, &znext, var);
			zn = znext;
			while (index.i++ < index.maxit)
			{
				compmine(&zn, &znext, &pixel, &zbef2);
				if (powf(znext.reel, 2) + powf(znext.imag, 2) > 4)
					break;
			}
			coloring(var, index);
		}
		index.x = 0;
	}
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
}

void	julia(t_ptr var)
{
	t_ima	zn;
	t_ima	znext;
	t_indexer	index;

	initindex(&index, var);
	while (index.y++ < var.height)
	{
		while (index.x++ < var.width)
		{
			znext.reel = 1.5 * (index.x - var.width / 2) / (0.5 * var.width * var.zoom) + var.moveX;
			znext.imag = 1.5 * (index.y - var.height / 2) / (0.5 * var.height * var.zoom) + var.moveY;
			index.i = 0;
			while (index.i++ < index.maxit)
			{
				compjulia(&zn, &znext, var);
				if (powf(znext.reel, 2) + powf(znext.imag, 2) > 4)
					break;
			}
			coloring(var, index);
		}
		index.x = 0;
	}
	mlx_put_image_to_window(var.mlx, var.win, var.img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_ptr	var;

	var.paramjul = 1;
	if (argc != 2 && argc != 3)
		ft_instru();
	else
		ft_checking(&var, argc, argv);
	ft_init(&var);
	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, var.width, var.height, "Fract_ol 42 CNikdel");
	var.img = mlx_new_image(var.mlx, var.width, var.height);
	var.addr = mlx_get_data_addr(var.img, &var.bits_per_pixel, &var.line_length, &var.endian);
	letsgo(var);
	mlx_hook(var.win, 17, 0, destroy, &var);
	mlx_hook(var.win, 2, (1L<<0), handler, &var);
	mlx_hook(var.win, 4, (1L<<2), zoom_event, &var);
	mlx_loop(var.mlx);
	return (0);
}
