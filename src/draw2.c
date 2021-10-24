#include "../cub3d.h"

void	draw_wall(t_game *g)
{
	g->ray.y = g->ray.dr_st;
	if (g->ray.side == 0)
		g->ray.w_x = g->pl.y + g->ray.pwd * g->ray.rdir_y;
	else
		g->ray.w_x = g->pl.x + g->ray.pwd * g->ray.rdir_x;
	walls(g);
	while (++g->ray.y < g->ray.dr_end)
		text_ori(g);
}

void	draw_dw(t_game *g, int x, int y)
{
	char *result;

	x = 0;
	while (x < g->res.w)
	{
		y = (g->res.he / 2);
		while (y < g->res.he)
		{
			result = g->img.adrr + (y * g->img.line_l + x * (g->img.bpx / 8));
			*(unsigned int *)result = g->col_flr.c_hx;
			y++;
		}
		x++;
	}
}

void	draw_up(t_game *g, int x, int y)
{
	char *result;

	x = 0;
	while (x < g->res.w)
	{
		y = 0;
		while (y < g->res.he / 2)
		{
			result = g->img.adrr + (y * g->img.line_l + x * (g->img.bpx / 8));
			*(unsigned int *)result = g->col_cel.c_hx;
			y++;
		}
		x++;
	}
}

void	draw_env(t_game *g, int x, int y)
{
	g->img.img = mlx_new_image(g->mlx_ptr, \
		g->res.w, g->res.he);
	g->img.img ? 0 : game_err('c');
	g->img.adrr = mlx_get_data_addr(g->img.img, &g->img.bpx, \
		&g->img.line_l, &g->img.endian);
	draw_up(g, x, y);
	draw_dw(g, x, y);
}

void	spr_text(t_game *g, int i)
{
	i = 0;
	while (i < g->sprt_n)
	{
		if (!(g->s[i].t.i.img = mlx_xpm_file_to_image(g->mlx_ptr, \
			g->t_spr.path, &g->s[i].t.w, \
			&g->s[i].t.h)))
			game_err('e');
		g->s[i].t.i.adrr = mlx_get_data_addr(g->s[i].t.i.img, \
			&g->s[i].t.i.bpx, &g->s[i].t.i.line_l, \
			&g->s[i].t.i.endian);
		i++;
	}
}
