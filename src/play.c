#include "../cub3d.h"

int	play(t_game *g)
{
	int x;
	int y;

	x = 0;
	y = 0;
	g->sp.dt = ft_calloc(sizeof(double*), g->res.w + 1);
	if (!g->sp.dt)
		return (-1);
	draw_env(g, x, y);
	body_mv(g);
	left_right(g);
	view_mv(g);
	raycst(g);
	sprt(g, x, y);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img.img, 0, 0);
	g->save ? scrnsht(g, x, y) : 0;
	mlx_destroy_image(g->mlx_ptr, g->img.img);
	return (0);
}
