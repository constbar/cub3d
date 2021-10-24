#include "../cub3d.h"

void			valid_color(char *buff)
{
	if ((buff == NULL) || (!ft_isnumber(buff)))
	{
		ft_putstr("color error\n");
		exit(EXIT_FAILURE);
	}
}

t_col			get_color(char *l)
{
	t_col			c;
	char			**buf;

	buf = NULL;
	c.ori = l[0];
	l++;
	while (l[0] == ' ')
		l++;
	buf = ft_split(l, ',');
	valid_color(buf[0]);
	valid_color(buf[1]);
	valid_color(buf[2]);
	c.r = ft_atoi(buf[0]);
	c.g = ft_atoi(buf[1]);
	c.b = ft_atoi(buf[2]);
	if (!buf[3])
	{
		true_color(c);
		c.c_hx = rgb(c.r, c.g, c.b);
		free_mem(buf, 3);
	}
	else
		game_err('z');
	return (c);
}

void			check_format(char *p)
{
	char	*t;

	t = NULL;
	p++;
	if (!ft_strchr(p, '.'))
	{
		ft_putstr("wrong text/format\n");
		exit(EXIT_FAILURE);
	}
	while (p[0] != '.')
		p++;
	t = ft_substr(p, 0, 5);
	if (ft_strncmp(t, ".xpm", 5) != 0)
	{
		ft_putstr("wrong text/format\n");
		exit(EXIT_FAILURE);
	}
	free(t);
}

t_tex			texture_parse(char *l)
{
	t_tex			t;
	char			**res;

	res = NULL;
	ft_strlen(l) <= 2 ? game_err('e') : 0;
	res = ft_split(l, ' ');
	t.orientation = ft_strdup(res[0]);
	if (ft_strlen(t.orientation) > 2)
	{
		ft_putstr("Error\nwrong text format\n");
		exit(EXIT_FAILURE);
	}
	t.path = ft_strdup(res[1]);
	if (!res[2])
	{
		check_format(res[1]);
		free_mem(res, 2);
	}
	else
	{
		ft_putstr("Error\nmore than 2 elememts\n");
		exit(EXIT_FAILURE);
	}
	return (t);
}

void			pars_text(t_game *g, char *l)
{
	if (l[0] == 'N')
		g->t_no = texture_parse(l);
	else if (l[0] == 'S')
	{
		if (l[1] == 'O')
			g->t_so = texture_parse(l);
		else
			g->t_spr = texture_parse(l);
	}
	else if (l[0] == 'E')
		g->t_ea = texture_parse(l);
	else if (l[0] == 'W')
		g->t_we = texture_parse(l);
}
