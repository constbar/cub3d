#include "../cub3d.h"

void	view_mv(t_game *g)
{
	if (g->mv.cam == 1)
	{
		g->olddr_x = g->pl.d_x;
		g->pl.d_x = g->pl.d_x * cos(-g->rot) -
			g->pl.d_y * sin(-g->rot);
		g->pl.d_y = g->olddr_x * sin(-g->rot) +
			g->pl.d_y * cos(-g->rot);
		g->oldpln_x = g->pl.p_x;
		g->pl.p_x = g->pl.p_x * cos(-g->rot) -
			g->pl.p_y * sin(-g->rot);
		g->pl.p_y = g->oldpln_x * sin(-g->rot) +
			g->pl.p_y * cos(-g->rot);
	}
}

void	strafe_right(t_game *g, double tx, double ty)
{
	tx = g->pl.x;
	ty = g->pl.y;
	if (g->mv.right == 1)
	{
		g->pl.x += g->pl.p_x * g->speed_moove;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2'\
		? g->pl.x = tx : 0;
		g->pl.y += g->pl.p_y * g->speed_moove;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2'\
		? g->pl.y = ty : 0;
	}
}

void	strafe_left(t_game *g, double tx, double ty)
{
	tx = g->pl.x;
	ty = g->pl.y;
	if (g->mv.left == 1)
	{
		g->pl.x -= g->pl.p_x * g->speed_moove;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2'\
		? g->pl.x = tx : 0;
		g->pl.y -= g->pl.p_y * g->speed_moove;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2'\
		? g->pl.y = ty : 0;
	}
}

void	left_right(t_game *g)
{
	double	tx;
	double	ty;

	tx = 0;
	ty = 0;
	strafe_right(g, tx, ty);
	strafe_left(g, tx, ty);
}

void	body_mv(t_game *g)
{
	double	tx;
	double	ty;

	tx = g->pl.x;
	ty = g->pl.y;
	if (g->mv.avr != 0)
	{
		g->pl.x += (g->speed_moove * g->pl.d_x) * g->mv.avr;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2'\
		? g->pl.x = tx : 0;
		g->pl.y += (g->speed_moove * g->pl.d_y) * g->mv.avr;
		g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '1' \
		|| g->map.tabm[(int)g->pl.x][(int)g->pl.y] == '2' \
		? g->pl.y = ty : 0;
	}
}
