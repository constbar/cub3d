#include "../cub3d.h"

void	paint_pix(t_game *g, \
t_bmp sh_i[g->res.he][g->res.w], int x, int y)
{
	unsigned int	color;
	char			*p;

	p = g->img.adrr + (x * (g->img.bpx / 8) + y * g->img.line_l);
	color = *(unsigned int *)p;
	sh_i[y][x].t = color >> 24;
	sh_i[y][x].b = color & 0XFF;
	sh_i[y][x].g = color >> 8 & 0xFF;
	sh_i[y][x].r = color >> 16 & 0XFF;
}

void	scrnsht(t_game *g, int fd, int i)
{
	t_bmp					sh_i[g->res.he][g->res.w];
	static char				head[54];
	unsigned int			pbpr;

	i = 0;
	fd = open("shot.bmp", O_RDWR | O_CREAT, 0644);
	fd < 0 ? game_err('a') : 0;
	pbpr = g->res.w * sizeof(t_bmp);
	head[0] = 'B';
	head[1] = 'M';
	*(unsigned int*)&head[2] = 54 + pbpr * g->res.he;
	head[10] = 54;
	head[14] = 40;
	*(unsigned int*)&head[18] = g->res.w;
	*(unsigned int*)&head[22] = -g->res.he;
	head[26] = 1;
	head[28] = 32;
	write(fd, head, 54);
	get_pix(g, sh_i, fd, i);
	while (i++ < g->res.he)
		write(fd, sh_i[i], pbpr);
	close(fd);
	suc('z');
}

void	get_pix(t_game *g, \
t_bmp sh_i[g->res.he][g->res.w], int x, int y)
{
	int h;
	int w;

	h = g->res.he;
	w = g->res.w;
	y = 0;
	while (++y < h)
	{
		x = 0;
		while (++x < w)
			paint_pix(g, sh_i, x, y);
	}
}
