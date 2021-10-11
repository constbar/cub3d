#include "../cub3d.h"

void		swap_inv(char *t, int le)
{
	int		i;
	int		j;
	char	tmp;

	j = le - 1;
	i = 0;
	while (i < j)
	{
		tmp = t[i];
		t[i] = t[j];
		t[j] = tmp;
		i++;
		j--;
	}
}

void		invert(t_game *g, int y)
{
	char	*tmp;

	y = 0;
	while (y < g->map.lo)
	{
		tmp = ft_strdup(g->map.tabm[y]);
		swap_inv(tmp, g->map.la);
		ft_strcpy(g->map.tabm[y], tmp);
		y++;
		free(tmp);
	}
}

void		dub_map(t_game *g, int x, int y, int i)
{
	x = 0;
	y = 0;
	i = 0;
	g->old_m.tabm = malloc(sizeof(g->old_m.tabm) * g->map.la);
	!g->old_m.tabm ? wtf('d') : 0;
	while (i++ < g->map.lo)
	{
		g->old_m.tabm[i - 1] = malloc(sizeof(*g->old_m.tabm) * g->map.lo);
		!g->old_m.tabm[i - 1] ? wtf('d') : 0;
	}
	x = 0;
	while (x < g->map.lo)
	{
		y = 0;
		while (y < g->map.la)
		{
			g->old_m.tabm[x][y] = g->map.tabm[x][y];
			y++;
		}
		x++;
	}
}

void		game(t_game *g)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->res.w, \
		g->res.he, "agroup project");
	dub_map(g, x, y, i);
	invert(g, y);
	playerxy(g, x, y, i);
	player_init(g);
	spr_num(g, x, y);
	spr_init(g, x, y, i);
	init_text(g);
	spr_text(g, i);
	hooks(g);
	mlx_loop(g->mlx_ptr);
}
