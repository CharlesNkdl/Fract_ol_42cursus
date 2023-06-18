#include "../inc/fractol.h"

int	zoom_event(int keycode,int x, int y, t_ptr *var)
{
	if (keycode == 5)
	{
		var->zoom /= 1.2;
		var->moveY += (y - var->height / 2) / (0.5 * var->height * var->zoom);
		var->moveX += (x - var->width / 2) / (0.5 * var->width * var->zoom);
		letsgo(*var);
	}
	else if (keycode == 4)
	{
		var->zoom *= 1.2;
		var->moveY += (y - var->height / 2) / (0.5 * var->height * var->zoom);
		var->moveX += (x - var->width / 2) / (0.5 * var->width * var->zoom);
		letsgo(*var);
	}
	return (0);
}

int	destroy(t_ptr *var)
{
	if (var->img)
		mlx_destroy_image(var->mlx, var->img);
	if (var->win)
	{
		mlx_clear_window(var->mlx, var->win);
		mlx_destroy_window(var->mlx, var->win);
	}
	if (var->mlx)
	{
		mlx_loop_end(var->mlx);
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
	exit(0);
	return (0);
}

int	handler(int keycode, t_ptr *var)
{
	if (keycode == 65363)
		var->moveX += 0.5 / var->zoom;
	else if (keycode == 65361)
		var->moveX -= 0.5 / var->zoom;
	else if (keycode == 65364)
		var->moveY += 0.5 / var->zoom;
	else if (keycode == 65362)
		var->moveY -= 0.5 / var->zoom;
	else if (keycode == 65307)
		destroy(var);
	else if (keycode == 104)
		var->constjulreel += 0.1;
	else if (keycode == 106)
		var->constjulreel -= 0.1;
	else if (keycode == 107)
		var->constjulimg += 0.1;
	else if (keycode == 108)
		var->constjulimg -= 0.1;
	letsgo(*var);
	return (0);
}

void	coloring(t_ptr var, t_indexer index)
{
	var.addr[(index.y * var.line_length) + (index.x * 4) + 1] = (((index.maxit - index.i + 1) * index.i));
	var.addr[(index.y * var.line_length) + (index.x * 4) + 2] = (((index.maxit - index.i + 1)));
	var.addr[(index.y * var.line_length) + (index.x * 4) + 3] = (((index.maxit - index.i + 1)));
}

void	initindex(t_indexer *index, t_ptr var)
{
	index->i = 0;
	index->y = 0;
	index->x = 0;
	if (var.zoom > 1837408780)
		ft_printf("*** Last Zoom before Overflow ! ***\n");
	index->maxit = 20 + var.zoom;
	if (index->maxit >= 180)
		index->maxit = 180;
}
