#include "../cub3d.h"

void	drawsprt(t_game *g, int s, int i)
{
	unsigned int	clr;
	char			*r;
	int				tx;
	int				ty;
	int				y;

	while (s++ < g->sp.end_x)
	{
		tx = I(B * FU1 / g->sp.w) / B;
		if (g->sp.t_y > 0 && s > 0 && s < g->res.w && g->sp.t_y < g->sp.dt[s])
		{
			y = g->sp.start_y - 1;
			while (++y < g->sp.end_y)
			{
				ty = ((FU2 * g->s[i].t.h) / g->sp.hei) / B;
				clr = get_n_draw(g->s[i].t.i, tx, ty);
				if ((clr & 0x00FFFFFF) != 0)
				{
					r = FU3;
					*(unsigned int *)r = clr;
				}
			}
		}
	}
}

void	prior_sprt(t_game *g, int i, int stripe)
{
	i = 0;
	while (i < g->sprt_n)
	{
		g->sp.x = g->s[g->s[i].place].x - g->pl.x;
		g->sp.x = g->s[g->s[i].place].x - g->pl.x;
		g->sp.y = g->s[g->s[i].place].y - g->pl.y;
		g->sp.in = 1.0 / (g->pl.p_x * g->pl.d_y - g->pl.d_x * g->pl.p_y);
		g->sp.t_x = g->sp.in * (g->pl.d_y * g->sp.x - g->pl.d_x * g->sp.y);
		g->sp.t_y = g->sp.in * (-g->pl.p_y * g->sp.x + g->pl.p_x * g->sp.y);
		g->sp.sx = (int)((g->res.w / 2) * (1 + g->sp.t_x / g->sp.t_y));
		g->sp.hei = abs((int)(g->res.he / (g->sp.t_y)));
		g->sp.start_y = -g->sp.hei / 2 + g->res.he / 2;
		g->sp.start_y < 0 ? g->sp.start_y = 0 : 0;
		g->sp.end_y = g->sp.hei / 2 + g->res.he / 2;
		g->sp.end_y >= g->res.he ? g->sp.end_y = g->res.he - 1 : 0;
		g->sp.w = abs((int)(g->res.he / g->sp.t_y));
		g->sp.start_x = -g->sp.w / 2 + g->sp.sx;
		g->sp.start_x < 0 ? g->sp.start_x = 0 : 0;
		g->sp.end_x = g->sp.w / 2 + g->sp.sx;
		g->sp.end_x >= g->res.w ? g->sp.end_x = g->res.w - 1 : 0;
		stripe = g->sp.start_x;
		drawsprt(g, stripe, i);
		i++;
	}
	free(g->sp.dt);
}

void	inv_sprt(t_game *g, int i, int j)
{
	int tmp;

	i = 0;
	j = g->sprt_n - 1;
	while (g->s[i].distwall < g->s[i + 1].distwall)
	{
		tmp = g->s[i].place;
		g->s[i].place = g->s[j].place;
		g->s[j].place = tmp;
		i++;
		j--;
	}
}

void	sprt(t_game *g, int i, int stripe)
{
	i = 0;
	while (i < g->sprt_n)
	{
		g->s[i].place = i;
		g->s[i].distwall = (g->pl.x - g->s[i].x) * (g->pl.x - g->s[i].x) \
		+ (g->pl.y - g->s[i].y) * (g->pl.y - g->s[i].y);
		i++;
	}
	inv_sprt(g, i, stripe);
	prior_sprt(g, i, stripe);
}
