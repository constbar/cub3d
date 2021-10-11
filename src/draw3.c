#include "../cub3d.h"

unsigned int	get_n_draw(t_img img, int x, int y)
{
	unsigned int	color;
	char			*ptr;

	ptr = img.adrr + (y * img.line_l + x * (img.bpx / 8));
	color = *(unsigned int *)ptr;
	return (color);
}

void			text_ori(t_game *g)
{
	char *result;
	char *ptr;

	g->ray.tposy = (int)g->ray.pos & (64 - 1);
	g->ray.pos += g->ray.st;
	g->ray.rdir_x > 0 && !g->ray.side ? ptr = g->t_no.i.adrr + (g->ray.tposy \
	* g->t_no.i.line_l + g->ray.tposx * (g->t_no.i.bpx / 8)) : 0;
	g->ray.rdir_x < 0 && !g->ray.side ? ptr = g->t_so.i.adrr + (g->ray.tposy \
	* g->t_so.i.line_l + g->ray.tposx * (g->t_so.i.bpx / 8)) : 0;
	(g->ray.rdir_x > 0 && g->ray.side && g->ray.rdir_y > 0) || (g->ray.side \
	&& g->ray.rdir_y > 0) ? ptr = g->t_ea.i.adrr + (g->ray.tposy \
	* g->t_ea.i.line_l + g->ray.tposx * (g->t_ea.i.bpx / 8)) : 0;
	(g->ray.rdir_x > 0 && g->ray.side && g->ray.rdir_y < 0) \
		|| (g->ray.side \
	&& g->ray.rdir_y < 0) ? ptr = g->t_we.i.adrr + (g->ray.tposy \
	* g->t_we.i.line_l + g->ray.tposx * (g->t_we.i.bpx / 8)) : 0;
	g->ray.color = *(unsigned int *)ptr;
	result = g->img.adrr + (g->ray.y * g->img.line_l \
	+ g->ray.x * (g->img.bpx / 8));
	*(unsigned int *)result = g->ray.color;
}

void			walls(t_game *g)
{
	g->ray.w_x -= floor((g->ray.w_x));
	g->ray.tposx = (int)(g->ray.w_x * (double)(64));
	g->ray.side == 0 && g->ray.rdir_x > 0 \
	? g->ray.tposx = 64 - g->ray.tposx - 1 : 0;
	g->ray.side == 1 && g->ray.rdir_y < 0 \
	? g->ray.tposx = 64 - g->ray.tposx - 1 : 0;
	g->ray.st = 1.0 * 64 / g->ray.line_heigth;
	g->ray.pos = (g->ray.y - g->res.he / 2 \
	+ g->ray.line_heigth / 2) * g->ray.st;
}
