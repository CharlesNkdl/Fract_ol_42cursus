#include "../inc/fractol.h"

void	resetmand(t_indexer *index,t_ima *pixel,t_ima *znext, t_ptr var)
{
	pixel->reel =  1.5 * (index->x - var.width / 2) / (0.5 * var.width * var.zoom) + var.moveX - 0.5;
	pixel->imag = 1.5 * (index->y - var.height / 2) / (0.5 * var.height * var.zoom) + var.moveY;
	znext->reel = 0;
	znext->imag = 0;
	index->i = 0;
	return ;
}

void	compmand(t_ima *zn, t_ima *znext, t_ima *pixel)
{
	*zn = *znext;
	znext->reel = (zn->reel * zn->reel) - (zn->imag * zn->imag) + pixel->reel;
	znext->imag = 2 * zn->reel * zn->imag + pixel->imag;
}

void	compmine(t_ima *zn, t_ima *znext, t_ima *pixel, t_ima *zbef2)
{
	zbef2->reel = zn->reel / 2;
	zbef2->imag = zn->imag / 2;
	*zn = *znext;
	znext->reel = (zn->reel * zn->reel) - (zn->imag * zn->imag) + pixel->reel + zbef2->reel;
	znext->imag = 2 * zn->reel * zn->imag + pixel->imag + zbef2->imag;
}

void	compjulia(t_ima *zn, t_ima *znext, t_ptr var)
{
	zn->reel = znext->reel;
	zn->imag = znext->imag;
	znext->reel = (zn->reel * zn->reel) - (zn->imag * zn->imag) + var.constjulreel;
	znext->imag = 2 * zn->reel * zn->imag + var.constjulimg;
}



