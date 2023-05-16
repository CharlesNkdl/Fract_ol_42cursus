#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include "../Libft/Headers/ft_printf.h"
# include "../Libft/Headers/get_next_line_bonus.h"
# include "../Libft/Headers/libft.h"

typedef struct s_ima
{
	double	reel;
	double	imag;
}			t_ima;

typedef struct s_indexer {
	int	i;
	int	y;
	int x;
	int	maxit;
}		t_indexer;


typedef struct s_ptr {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int 	fractal;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double		paramjul;
	double		constjulreel;
	double		constjulimg;
	double zoom;
	double	moveX;
	double	moveY;
}		t_ptr;

void	letsgo(t_ptr var);
void	initindex(t_indexer *index, t_ptr var);
void	resetmand(t_indexer *index,t_ima *pixel,t_ima *znext, t_ptr var);
void	coloring(t_ptr var, t_indexer index);
void	ft_init(t_ptr *var);
void	ft_checking(t_ptr *var, int argc, char **argv);
int	ft_strcmp(char *s1, char *s2);
void	ft_instru(void);
int	zoom_event(int keycode,int x, int y, t_ptr *var);
int	destroy(t_ptr *var);
int	handler(int keycode, t_ptr *var);
void	coloring(t_ptr var, t_indexer index);
void	initindex(t_indexer *index, t_ptr var);
void	mandelbrot(t_ptr var);
void	mafractale(t_ptr var);
void	julia(t_ptr var);
void	compmand(t_ima *zn, t_ima *znext, t_ima *pixel);
void	compmine(t_ima *zn, t_ima *znext, t_ima *pixel, t_ima *zbef2);
void	compjulia(t_ima *zn, t_ima *znext, t_ptr var);

#endif
