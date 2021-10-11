#include "../cub3d.h"

void	init_text(t_game *g)
{
	if (!(g->t_no.i.img = mlx_xpm_file_to_image(g->mlx_ptr, \
		g->t_no.path, &g->t_no.w, &g->t_no.h)))
		wtf('e');
	g->t_no.i.adrr = mlx_get_data_addr(g->t_no.i.img, \
		&g->t_no.i.bpx, &g->t_no.i.line_l, &g->t_no.i.endian);
	if (!(g->t_we.i.img = mlx_xpm_file_to_image(g->mlx_ptr, \
		g->t_we.path, &g->t_we.w, &g->t_we.h)))
		wtf('e');
	g->t_we.i.adrr = mlx_get_data_addr(g->t_we.i.img, \
		&g->t_we.i.bpx, &g->t_we.i.line_l, &g->t_we.i.endian);
	if (!(g->t_so.i.img = mlx_xpm_file_to_image(g->mlx_ptr, \
			g->t_so.path, &g->t_so.w, &g->t_so.h)))
		wtf('e');
	g->t_so.i.adrr = mlx_get_data_addr(g->t_so.i.img, \
		&g->t_so.i.bpx, &g->t_so.i.line_l, &g->t_so.i.endian);
	if (!(g->t_ea.i.img = mlx_xpm_file_to_image(g->mlx_ptr, \
			g->t_ea.path, &g->t_ea.w, &g->t_ea.h)))
		wtf('e');
	g->t_ea.i.adrr = mlx_get_data_addr(g->t_ea.i.img, \
		&g->t_ea.i.bpx, &g->t_ea.i.line_l, &g->t_ea.i.endian);
}

void	spr_init(t_game *g, int x, int y, int i)
{
	i = 0;
	x = 0;
	y = 0;
	g->s = ft_calloc(sizeof(t_sprite) * g->sprt_n, 1);
	!g->s ? wtf('d') : 0;
	while (x < g->map.lo)
	{
		y = 0;
		while (y < g->map.la)
		{
			if (g->map.tabm[x][y] == '2')
			{
				g->s[i].y = y + 0.5;
				g->s[i].x = x + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	spr_num(t_game *g, int x, int y)
{
	x = 0;
	y = 0;
	while (x < g->map.lo)
	{
		y = 0;
		while (y++ < g->map.la)
			g->map.tabm[x][y] == '2' ? g->sprt_n++ : 0;
		x++;
	}
}

void	player_init(t_game *g)
{
	if (g->pl.ori == 'W')
	{
		g->pl.d_x = 0.0;
		g->pl.d_y = 1.0;
		g->pl.p_x = -0.66 * g->pl.d_y;
	}
	else if (g->pl.ori == 'N')
	{
		g->pl.d_x = -1.0;
		g->pl.d_y = 0.0;
		g->pl.p_x = -0.66 * g->pl.d_y;
	}
	else if (g->pl.ori == 'E')
	{
		g->pl.d_x = 0.0;
		g->pl.d_y = -1.0;
		g->pl.p_x = -0.66 * g->pl.d_y;
	}
	else if (g->pl.ori == 'S')
	{
		g->pl.d_x = 1.0;
		g->pl.d_y = 0.0;
		g->pl.p_x = -0.66 * g->pl.d_y;
	}
	g->pl.p_y = 0.66 * g->pl.d_x;
}

void	playerxy(t_game *g, int x, int y, int i)
{
	i = 0;
	x = 0;
	y = 0;
	while (x < g->map.lo)
	{
		y = 0;
		while (y < g->map.la)
		{
			i > 1 ? wtf('b') : 0;
			if (g->map.tabm[x][y] == 'S' || g->map.tabm[x][y] == 'N' \
				|| g->map.tabm[x][y] == 'E' || g->map.tabm[x][y] == 'W')
			{
				g->pl.ori = g->map.tabm[x][y];
				g->pl.y = y + 0.5;
				g->pl.x = x + 0.5;
				i++;
			}
			y++;
		}
		x++;
	}
	g->pl.ori == ' ' ? wtf('f') : 0;
}
