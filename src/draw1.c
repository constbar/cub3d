#include "../cub3d.h"

int	rgb(int r, int g, int b)
{
	unsigned int	c;

	c = r;
	c = (c << 8) + g;
	c = (c << 8) + b;
	return (c);
}
