#include "../inc/fractol.h"

void	ft_init(t_ptr *var)
{
	var->zoom = 1;
	var->moveX = 0;
	var->moveY = 0;
	var->width = 500;
	var->height = 500;
	var->constjulreel = 0.3 * var->paramjul;
	var->constjulimg = 0.5 * var->paramjul;
}

void	letsgo(t_ptr var)
{
	if (var.fractal == 1)
		mandelbrot(var);
	else if (var.fractal == 2)
		julia(var);
	else if (var.fractal == 3)
		mafractale(var);
	return ;
}

void	ft_checking(t_ptr *var, int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strcmp("julia", argv[1]) == 0)
		{
			var->fractal = 2;
			if (ft_atoi(argv[2])>= 1 && ft_atoi(argv[2]) <= 6)
				var->paramjul = ft_atoi(argv[2]) * 0.2;
			else
				ft_instru();
		}
		else
			ft_instru();
	}
	if (ft_strcmp("mandelbrot", argv[1]) == 0)
		var->fractal = 1;
	else if (ft_strcmp("julia", argv[1]) == 0)
		var->fractal = 2;
	else if (ft_strcmp("mine", argv[1]) == 0)
		var->fractal = 3;
	else
		ft_instru();
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (c1[i] == c2[i] && c1[i] != 0 && c2[i] != 0)
		i++;
	return (c1[i] - c2[i]);
}

void	ft_instru(void)
{
	ft_printf("######################################################\n");
	ft_printf("#             WELCOME TO CNIKDEL'S FRACTOL           #\n");
	ft_printf("#    HOW TO LAUNCH IT :                              #\n");
	ft_printf("#    1)  The name : 'mandelbrot', 'julia' or 'mine'  #\n");
	ft_printf("#    COMMANDS :                                      #\n");
	ft_printf("#           *Move with arrows keys                   #\n");
	ft_printf("#           *Zoom-in and out with mouse              #\n");
	ft_printf("#           *You can point the mouse to zoom in      #\n");
	ft_printf("#                a particuliar area                  #\n");
	ft_printf("#   *In Julia's Fractal, H = up the real part of K   #\n");
	ft_printf("#   *J to reduce it                                  #\n");
	ft_printf("#   *K to up the imaginary part of K, L to reduce    #\n");
	ft_printf("#                 ENJOY                              #\n");
	ft_printf("######################################################\n");
	exit(0);
}
