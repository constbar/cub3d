#include "../cub3d.h"

void		true_color(t_col c)
{
	if (c.r < 0 || c.b < 0 || c.g < 0)
	{
		ft_putstr("col 0-255\n");
		exit(EXIT_FAILURE);
	}
	if (c.g > 255 || c.r > 255 || c.b > 255)
	{
		ft_putstr("col 0-255\n");
		exit(EXIT_FAILURE);
	}
}
