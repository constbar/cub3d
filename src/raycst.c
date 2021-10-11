#include "../cub3d.h"

void	lenth_ray(t_game *g)
{
	if (g->ray.side == 0)
		g->ray.pwd = (g->ray.xact - g->pl.x \
			+ (1 - g->ray.st_x) / 2) / g->ray.rdir_x;
	else
		g->ray.pwd = (g->ray.yact - g->pl.y \
			+ (1 - g->ray.st_y) / 2) / g->ray.rdir_y;
	g->ray.line_heigth = (int)(g->res.he / g->ray.pwd);
	g->ray.dr_st = (int)(-g->ray.line_heigth / 2 + g->res.he / 2);
	g->ray.dr_st < 0 ? g->ray.dr_st = 0 : 0;
	g->ray.dr_end = (int)(g->ray.line_heigth / 2 + g->res.he / 2);
	g->ray.dr_end >= g->res.he ? g->ray.dr_end = g->res.he - 1 : 0;
	draw_wall(g);
	g->sp.dt[g->ray.x] = g->ray.pwd;
}

void	dda(t_game *g)
{
	if (g->ray.sdx > g->ray.sdy)
	{
		g->ray.sdy = g->ray.sdy + g->ray.ddy;
		g->ray.yact = g->ray.yact + g->ray.st_y;
		g->ray.side = 1;
	}
	else if (g->ray.sdx < g->ray.sdy)
	{
		g->ray.sdx = g->ray.sdx + g->ray.ddx;
		g->ray.xact = g->ray.xact + g->ray.st_x;
		g->ray.side = 0;
	}
	else
	{
		g->ray.sdy = g->ray.sdy + g->ray.ddy;
		g->ray.yact = g->ray.yact + g->ray.st_y;
		g->ray.side = 1;
	}
	g->map.tabm[g->ray.xact][g->ray.yact] == '1' ? g->ray.hit = 1 : 0;
}

void	dist_x_side(t_game *g)
{
	if (g->ray.rdir_x < 0)
	{
		g->ray.st_x = -1;
		g->ray.sdx = (g->pl.x - g->ray.xact) * g->ray.ddx;
	}
	else
	{
		g->ray.st_x = 1;
		g->ray.sdx = (g->ray.xact + 1.0 - g->pl.x) * g->ray.ddx;
	}
}

void	dist_y_side(t_game *g)
{
	if (g->ray.rdir_y < 0)
	{
		g->ray.st_y = -1;
		g->ray.sdy = (g->pl.y - g->ray.yact) * g->ray.ddy;
	}
	else
	{
		g->ray.st_y = 1;
		g->ray.sdy = (g->ray.yact + 1.0 - g->pl.y) * g->ray.ddy;
	}
}

void	raycst(t_game *c)
{
	c->ray.x = 0;
	while (c->ray.x <= c->res.w)
	{
		c->ray.hit = 0;
		c->ray.c_x = 2.0 * (double)c->ray.x / (double)c->res.w - 1.0;
		c->ray.rdir_x = c->pl.d_x + c->pl.p_x * c->ray.c_x;
		c->ray.rdir_y = c->pl.d_y + c->pl.p_y * c->ray.c_x;
		c->ray.xact = (int)c->pl.x;
		c->ray.yact = (int)c->pl.y;
		c->ray.ddx = sqrt(1 + (c->ray.rdir_y * c->ray.rdir_y) \
			/ (c->ray.rdir_x * c->ray.rdir_x));
		c->ray.ddy = sqrt(1 + (c->ray.rdir_x * c->ray.rdir_x) \
			/ (c->ray.rdir_y * c->ray.rdir_y));
		dist_x_side(c);
		dist_y_side(c);
		while (!c->ray.hit)
			dda(c);
		lenth_ray(c);
		c->ray.x++;
	}
}
