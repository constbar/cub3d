#include "../cub3d.h"

int		exitx(t_game *g)
{
	if (g->mlx_ptr && g->win_ptr)
	{
		mlx_clear_window(g->mlx_ptr, g->win_ptr);
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	}
	free_mem(g->old_m.tabm, g->map.lo);
	free_mem(g->map.tabm, g->map.lo);
	free_ori(g);
	exit(EXIT_SUCCESS);
}

void	free_ori(t_game *g)
{
	g->t_spr.orientation ? free(g->t_spr.orientation) : 0;
	g->t_no.orientation ? free(g->t_no.orientation) : 0;
	g->t_so.orientation ? free(g->t_so.orientation) : 0;
	g->t_we.orientation ? free(g->t_we.orientation) : 0;
	g->t_ea.orientation ? free(g->t_ea.orientation) : 0;
	g->t_spr.path ? free(g->t_spr.path) : 0;
	g->t_no.path ? free(g->t_no.path) : 0;
	g->t_so.path ? free(g->t_so.path) : 0;
	g->t_we.path ? free(g->t_we.path) : 0;
	g->t_ea.path ? free(g->t_ea.path) : 0;
}

int		bctrl(int key, t_game *g)
{
	key == 119 ? g->mv.avr = 0 : 0;
	key == 115 ? g->mv.avr = 0 : 0;
	key == 100 ? g->mv.right = 0 : 0;
	key == 65363 ? g->mv.cam = 0 : 0;
	key == 65361 ? g->mv.cam = 0 : 0;
	key == 97 ? g->mv.left = 0 : 0;
	if (key == 65307)
	{
		if (g->mlx_ptr && g->win_ptr)
		{
			mlx_clear_window(g->mlx_ptr, g->win_ptr);
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		}
		free_mem(g->old_m.tabm, g->map.lo);
		free_mem(g->map.tabm, g->map.lo);
		free_ori(g);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		ctrl(int key, t_game *g)
{
	if (key == 65361 || key == 65363)
	{
		g->mv.cam = 1;
		key == 65363 ? g->rot = -0.03 : 0;
		key == 65361 ? g->rot = 0.03 : 0;
	}
	if (key == 65307)
	{
		if (g->mlx_ptr && g->win_ptr)
		{
			mlx_clear_window(g->mlx_ptr, g->win_ptr);
			mlx_destroy_window(g->mlx_ptr, g->win_ptr);
		}
		free_mem(g->old_m.tabm, g->map.lo);
		free_mem(g->map.tabm, g->map.lo);
		free_ori(g);
		exit(EXIT_SUCCESS);
	}
	g->speed_moove = 0.06;
	key == 97 ? g->mv.left = 1 : 0;
	key == 100 ? g->mv.right = 1 : 0;
	key == 115 ? g->mv.avr = -1 : 0;
	key == 119 ? g->mv.avr = 1 : 0;
	return (0);
}

void	hooks(t_game *g)
{
	mlx_hook(g->win_ptr, 2, 1L << 0, ctrl, g);
	mlx_hook(g->win_ptr, 3, 1L << 1, bctrl, g);
	mlx_hook(g->win_ptr, 17, 0L, exitx, g);
	mlx_loop_hook(g->mlx_ptr, play, g);
}
