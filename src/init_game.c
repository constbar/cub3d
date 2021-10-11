#include "../cub3d.h"

void		init_game1(t_game *g)
{
	g->res.he = 0;
	g->res.w = 0;
	g->old_m.tabm = NULL;
	g->map.tabm = NULL;
	g->old_m.lo = 0;
	g->old_m.la = 0;
	g->old_m.x = 0;
	g->old_m.y = 0;
	g->rot = 0;
	g->map.lo = 0;
	g->map.la = 0;
	g->map.x = 0;
	g->map.y = 0;
	g->save = 0;
	g->col_cel.ori = ' ';
	g->col_cel.c_hx = 0;
	g->col_cel.r = 0;
	g->col_cel.g = 0;
	g->col_cel.b = 0;
	g->col_flr.ori = ' ';
	g->col_flr.c_hx = 0;
	g->col_flr.r = 0;
	g->col_flr.g = 0;
	g->col_flr.b = 0;
}

void		init_game2(t_game *g)
{
	g->pl.ori = ' ';
	g->pl.p_y = 0.66;
	g->pl.p_x = 0;
	g->pl.d_x = 0;
	g->pl.d_y = 0;
	g->pl.x = 0;
	g->pl.y = 0;
	g->speed_moove = 0.1;
	g->mv.avr = 0;
	g->oldpln_x = 0;
	g->oldpln_y = 0;
	g->mv.right = 0;
	g->mv.left = 0;
	g->mv.cam = 0;
	g->olddr_x = 0;
	g->olddr_y = 0;
	g->t_spr.orientation = NULL;
	g->t_spr.path = NULL;
	g->t_spr.w = 0;
	g->t_spr.h = 0;
	g->sprt_n = 0;
}

void		init_game3(t_game *g)
{
	g->t_so.orientation = NULL;
	g->t_so.i.adrr = NULL;
	g->t_so.path = NULL;
	g->t_so.h = 0;
	g->t_so.w = 0;
	g->t_we.orientation = NULL;
	g->t_we.i.adrr = NULL;
	g->t_we.path = NULL;
	g->t_we.h = 0;
	g->t_we.w = 0;
	g->t_ea.orientation = NULL;
	g->t_ea.i.adrr = NULL;
	g->t_ea.path = NULL;
	g->t_ea.h = 0;
	g->t_ea.w = 0;
	g->t_no.orientation = NULL;
	g->t_no.i.adrr = NULL;
	g->t_no.path = NULL;
	g->t_no.h = 0;
	g->t_no.w = 0;
}

void		init_game4(t_game *g)
{
	g->ray.rdir_y = 0;
	g->ray.xact = 0;
	g->ray.yact = 0;
	g->ray.sdx = 0;
	g->ray.sdy = 0;
	g->ray.ddx = 0;
	g->ray.ddy = 0;
	g->ray.st_x = 0;
	g->ray.st_y = 0;
	g->ray.pwd = 0;
	g->ray.line_heigth = 0;
	g->ray.dr_st = 0;
	g->ray.dr_end = 0;
	g->ray.side = 0;
	g->ray.w_x = 0;
	g->ray.tposx = 0;
	g->ray.tposy = 0;
	g->ray.st = 0;
	g->ray.pos = 0;
	g->ray.color = 0;
	g->ray.c_x = 0;
	g->ray.rdir_x = 0;
	g->ray.hit = 0;
	g->ray.x = 0;
	g->ray.y = 0;
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}
