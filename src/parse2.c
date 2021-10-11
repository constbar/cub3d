#include "../cub3d.h"

int			check_each(char c)
{
	if (c == '2' || c == 'W' || c == '0' \
		|| c == '1' || c == 'E' || c == 'S' \
		|| c == 'N' || c == ' ' || c == '4')
		return (1);
	return (0);
}

void		check_inne(char **map, t_map m, int x, int y)
{
	x = 0;
	y = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			check_each(map[x][y]) != 1 ? wtf('r') : 0;
			map[x][y] == ' ' ? map[x][y] = '0' : 0;
			if (map[x][y] != '1' && map[x][y] != '4')
			{
				map[x - 1][y] == '4' || map[x + 1][y] == '4' || map[x][y + 1] \
				== '4' || map[x][y - 1] == '4' ? wtf('s') : 0;
			}
			y++;
		}
		x++;
	}
}

void		check_bord(char **map, t_map m, int x, int y)
{
	x = 0;
	y = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			(x == 0 || x == m.lo - 1 || y == m.la - 1 || y == 0) \
			&& (map[x][y] != '1' && map[x][y] != '4') ? wtf('s') : 0;
			y++;
		}
		x++;
	}
}

void		add_elem(char **map, char *line, t_map m)
{
	m.y = 0;
	while (m.y < m.la && m.x <= m.lo)
	{
		if (line[0] == '\0')
		{
			while (m.y < m.la)
			{
				map[m.x][m.y] = '4';
				m.y++;
			}
		}
		else
		{
			if (line[0] == ' ')
				map[m.x][m.y] = '4';
			else
				map[m.x][m.y] = line[0];
			line++;
			m.y++;
		}
	}
	map[m.x][m.y] = '\0';
}
