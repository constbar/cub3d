#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibX/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_bmp
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char t;
}				t_bmp;

typedef struct	s_map
{
	int			x;
	int			y;
	int			lo;
	int			la;
	char		**tabm;

}				t_map;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			c_hx;
	char		ori;

}				t_col;

typedef struct	s_mv
{
	int			right;
	int			left;
	int			avr;
	int			cam;

}				t_mv;

typedef struct	s_res
{
	int			he;
	int			w;

}				t_res;

typedef struct	s_image
{
	void		*img;
	char		*adrr;
	int			bpx;
	int			line_l;
	int			endian;

}				t_img;

typedef struct	s_par
{
	void		*mlx_ptr;
	void		*win_ptr;

}				t_par;

typedef struct	s_player
{
	char		ori;
	double		p_x;
	double		p_y;
	double		d_x;
	double		d_y;
	double		x;
	double		y;

}				t_pl;

typedef struct	s_texture
{
	char		*orientation;
	char		*path;
	int			w;
	int			h;
	t_img		i;
}				t_tex;

typedef struct	s_raycast
{
	double		ddx;
	double		ddy;
	double		sdx;
	double		sdy;
	double		pos;
	double		rdir_x;
	double		rdir_y;
	double		w_x;
	double		c_x;
	double		st;
	double		pwd;
	int			line_heigth;
	int			dr_st;
	int			tposx;
	int			tposy;
	int			dr_end;
	int			st_x;
	int			st_y;
	int			color;
	int			side;
	int			xact;
	int			yact;
	int			hit;
	int			x;
	int			y;
}				t_rcst;

typedef struct	s_sprite
{
	double		distwall;
	int			place;
	double		x;
	double		y;
	t_tex		t;
}				t_sprite;

typedef struct	s_sp
{
	double		*dt;
	double		t_x;
	double		t_y;
	double		in;
	double		x;
	double		y;
	int			sx;
	int			sprite_h;
	int			start_y;
	int			start_x;
	int			end_y;
	int			end_x;
	int			w;
	int			hei;
}				t_sp;

typedef	struct	s_game
{
	t_col		col_cel;
	t_col		col_flr;
	t_sprite	*s;
	t_pl		pl;
	t_tex		t_spr;
	t_tex		t_no;
	t_tex		t_so;
	t_tex		t_we;
	t_tex		t_ea;
	t_par		param;
	t_res		res;
	t_mv		mv;
	t_rcst		ray;
	t_img		img;
	t_sp		sp;
	t_map		old_m;
	t_map		map;
	double		speed_moove;
	double		oldpln_y;
	double		oldpln_x;
	double		olddr_x;
	double		olddr_y;
	double		rot;
	int			sprt_n;
	int			save;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*sprt_path;
	char		sp_path;
}				t_game;

# define NF1 "no bmp\n"
# define NF2 "screenshot made\n"
# define NF3 "image didnt create\n"
# define NF4 "2 or more positions\n"
# define NF5 "no player position\n"
# define NF6 "malloc error\n"
# define NF7 "no texture\n"
# define NF8 "novalid map\n"
# define NF9 "need .cub extension\n"
# define NF10 "malloc error with textures\n"
# define NF11 "much element in mapfile\n"
# define NF12 "no map\n"
# define NF13 "no mapfile\n"
# define NF14 "need resolution\n "
# define NF15 "bad resolution\n"
# define NF16 "too much element\n"
# define NF17 "map error\n"
# define NF18 "bad map element\n"
# define NF19 "no wall around position\n"
# define NF20 "incorrect line\n"
# define NF21 "error argument with save\n"
# define NF22 "map invalide\n"
# define NF23 "invalid format\n"
# define NF24 "too many elements for\n"
# define I (int)
# define B 256
# define M 128

# define FU1 (s - (-g->sp.w / 2 + g->sp.sx)) * g->s[i].t.w
# define FU2 (y * B - g->res.he * M + g->sp.hei * M)
# define FU3 g->img.adrr + (y * g->img.line_l + s * (g->img.bpx / 8))
# define FU4 !ft_strstr(t, "NO") || !ft_strstr(t, "EA") || !ft_strstr(t, "SO")
# define FU5 !ft_strstr(t, "WE") || !ft_strstr(t, "S ") || !ft_strstr(t, "F ")
# define FU6 !ft_strstr(t, "C ") || !ft_strstr(t, "R ")

char			*ft_strtrim(char const *s1, char const *set);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
int				ft_isnumber(char *str);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
char			*ft_strstr(char *str, char *to_find);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t n, size_t size);
char			*ft_strdup(const char *s);
char			**ft_split(char const *s, char c);
int				get_next_line(int fd, char **line);
char			*ft_substr(char const *s, unsigned int star, size_t len);
char			*ft_copy(char *dst, char *src);
char			*ft_strcpy(char *dest, char *src);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			init_game1(t_game *g);
void			init_game2(t_game *g);
void			init_game3(t_game *g);
void			init_game4(t_game *g);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			free_mem(char **tab, int lenght);
void			game_err(char letter);
void			suc(char letter);
void			check_save(char *str);
void			work_with_fd(t_game *g, char *argv);
t_map			check_fd (int fd, char *l, char *t, int i);
t_map			map_prop(int fd);
void			parse_prop(int fd, t_game *g);
t_res			parse_res(char *line, t_game *g);
void			init_map(int fd, char *line, t_game *g, int i);
void			check_and_fill(char *line, t_game *c);
void			check_end_line(char *line);
void			add_elem(char **mp, char *line, t_map m);
void			check_bord(char **mp, t_map m, int x, int y);
void			check_inne(char **mp, t_map m, int x, int y);
int				check_each(char c);
void			pars_text(t_game *g, char *line);
t_tex			texture_parse(char *line);
void			check_format(char *path);
t_col			get_color(char *line);
void			valid_color(char *buff);
void			true_color(t_col c);
int				rgb(int r, int g, int b);
void			game(t_game *g);
void			dub_map (t_game *g, int x, int y, int i);
void			invert(t_game *g, int y);
void			swap_inv(char *tab, int size);
void			playerxy(t_game *g, int x, int y, int i);
void			player_init(t_game *g);
void			spr_num(t_game *g, int x, int y);
void			spr_init(t_game *g, int x, int y, int i);
void			init_text(t_game *g);
void			spr_text(t_game *c, int i);
void			draw_env(t_game *g, int x, int y);
void			draw_up(t_game *g, int x, int y);
void			draw_dw(t_game *g, int x, int y);
void			draw_wall(t_game *g);
void			hooks(t_game *g);
int				ctrl(int k, t_game *g);
int				bctrl(int k, t_game *g);
void			free_ori(t_game *g);
int				exitx(t_game *g);
int				play(t_game *g);
void			body_mv(t_game *g);
void			left_right(t_game *g);
void			strafe_right(t_game *g, double tx, double ty);
void			strafe_left(t_game *g, double tx, double ty);
void			view_mv (t_game *g);
void			raycst(t_game *g);
void			dist_x_side(t_game *cub);
void			dist_y_side(t_game *cub);
void			dda(t_game *c);
void			lenth_ray(t_game *c);
void			walls(t_game *c);
void			text_ori(t_game *g);
unsigned int	get_n_draw(t_img img, int x, int y);
void			sprt(t_game *g, int x, int y);
void			inv_sprt(t_game *g, int i, int j);
void			prior_sprt(t_game *cub, int i, int stripe);
void			drawsprt (t_game *cub, int stripe, int i);
void			scrnsht(t_game *g, int x, int y);
void			get_pix(t_game *g, t_bmp img_data[g->res.he][g->res.w]\
				, int x, int y);
void			paint_pix(t_game *g, t_bmp sh_i[g->res.he][g->res.w]\
				, int x, int y);

#endif
