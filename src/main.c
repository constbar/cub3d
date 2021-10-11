#include "../cub3d.h"

t_map		map_prop(int fd)
{
	int		nl;
	t_map	pr;
	char	*l;

	l = NULL;
	pr.lo = 1;
	pr.la = 0;
	while (get_next_line(fd, &l) && l[0] != '\0')
	{
		nl = ft_strlen(l);
		nl > pr.la ? pr.la = nl : 0;
		pr.lo++;
		free(l);
	}
	free(l);
	return (pr);
}

t_map		check_fd(int fd, char *l, char *t, int i)
{
	t_map	m;

	l = NULL;
	t = NULL;
	i = 0;
	t = ft_calloc(17, sizeof(char));
	!t ? wtf('h') : 0;
	while (get_next_line(fd, &l))
	{
		if (l[0] == '1' || l[0] == ' ')
			m = map_prop(fd);
		else if ((l[0] >= 'a' && l[0] <= 'z') || (l[0] >= 'A' && l[0] <= 'Z'))
		{
			i > 15 ? wtf('k') : 0;
			t[i] = l[0];
			t[i + 1] = l[1];
			i += 2;
		}
		free(l);
	}
	free(l);
	FU4 || FU5 || FU6 ? wtf('l') : 0;
	free(t);
	m.la < 3 || m.lo < 3 ? wtf('i') : 0;
	return (m);
}

void		work_with_fd(t_game *g, char *argv)
{
	int		fd;
	char	*l;
	char	*t;
	int		i;

	i = 0;
	t = NULL;
	l = NULL;
	fd = open(argv, O_RDONLY);
	g->map = check_fd(fd, l, t, i);
	close(fd);
	fd = open(argv, O_RDONLY);
	parse_prop(fd, g);
	close(fd);
}

void		check_save(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			wtf('y');
	}
	if (!(str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b'))
		wtf('q');
}

int			main(int argc, char **argv)
{
	int		save;
	t_game	g;

	ft_bzero(&g, sizeof(t_game));
	init_game1(&g);
	init_game2(&g);
	init_game3(&g);
	init_game4(&g);
	save = 0;
	argc == 3 && (argv[2][0] == '-' && argv[2][1] == \
		'-' && argv[2][2] == 's' && argv[2][3] == 'a' \
	&& argv[2][4] == 'v' && argv[2][5] == 'e') ? save = 1 : 0;
	g.save = save;
	if (argc < 2)
		wtf('g');
	else if ((argc == 3 && save == 1) || argc == 2)
	{
		check_save(argv[1]);
		work_with_fd(&g, argv[1]);
		game(&g);
	}
	else
		wtf('x');
	return (EXIT_SUCCESS);
}
