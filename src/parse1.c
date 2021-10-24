#include "../cub3d.h"

void	check_end_line(char *l)
{
	int		len;
	char	*tmp;

	tmp = ft_strtrim(l, " ");
	len = ft_strlen(tmp);
	tmp[0] != '1' ? game_err('t') : 0;
	tmp[len - 1] != '1' ? game_err('t') : 0;
	free(tmp);
}

void	check_and_fill(char *line, t_game *g)
{
	check_end_line(line);
	add_elem(g->map.tabm, line, g->map);
	g->map.x++;
}

void	init_map(int fd, char *line, t_game *g, int i)
{
	char		*l;
	int			ret;
	int			x;
	int			y;

	l = NULL;
	i = 0;
	g->map.tabm = malloc(sizeof(g->map.tabm) * g->map.lo);
	!g->map.tabm ? game_err('d') : 0;
	while (i++ < g->map.lo)
	{
		g->map.tabm[i - 1] = malloc(g->map.la * sizeof(char) + 1);
		!g->map.tabm[i - 1] ? game_err('d') : 0;
	}
	g->map.x = 0;
	check_and_fill(line, g);
	while ((ret = get_next_line(fd, &l)))
	{
		g->map.x < g->map.lo ? check_and_fill(l, g) : 0;
		!l[0] ? game_err('p') : 0;
		free(l);
	}
	free(l);
	check_bord(g->map.tabm, g->map, x, y);
	check_inne(g->map.tabm, g->map, x, y);
}

t_res	parse_res(char *line, t_game *g)
{
	int				mx;
	int				my;
	char			**res;
	t_res			rsl;

	res = ft_split(line, ' ');
	!res[1] ? game_err('m') : 0;
	rsl.w = ft_atoi(res[1]);
	!res[2] ? game_err('m') : 0;
	rsl.he = ft_atoi(res[2]);
	if (!res[3])
	{
		!rsl.he || !rsl.w ? game_err('n') : 0;
		g->mlx_ptr = mlx_init();
		rsl.he < 1 ? game_err('n') : 0;
		rsl.w < 1 ? game_err('n') : 0;
		mlx_get_screen_size(g->mlx_ptr, &mx, &my);
		rsl.he > my ? rsl.he = my : 0;
		rsl.w > mx ? rsl.w = mx : 0;
		free_mem(res, 3);
	}
	else
		game_err('o');
	return (rsl);
}

void	parse_prop(int fd, t_game *g)
{
	char	*l;
	int		i;

	i = 0;
	l = NULL;
	while (get_next_line(fd, &l) == 1)
	{
		if (l[0] == 'R')
			g->res = parse_res(l, g);
		else if (l[0] == '0' || l[0] == '1' \
			|| l[0] == ' ')
			init_map(fd, l, g, i);
		else if (l[0] == 'W' || l[0] == 'E' \
			|| l[0] == 'N' || l[0] == 'S')
			pars_text(g, l);
		else if (l[0] == 'F')
			g->col_flr = get_color(l);
		else if (l[0] == 'C')
			g->col_cel = get_color(l);
		free(l);
	}
	free(l);
}
