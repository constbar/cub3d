NAME = cub3d

SRC	=		src/init_game.c src/libft1.c src/libft2.c src/libft3.c \
			src/libft4.c src/libft5.c src/game.c src/err.c src/main.c \
			src/parse1.c src/parse2.c src/parse3.c src/parse4.c \
			src/draw1.c src/draw2.c src/draw3.c src/player.c src/hooks.c \
			src/play.c src/mv.c src/raycst.c src/sprt.c src/scrnsht.c \

MLX = -L./minilibX/ ./minilibX/libmlx.a -lm -lmlx -lX11 -lXext -lbsd

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@rm -rf cub3d
	@gcc -o $(NAME) $(OBJ) $(MLX) -Wall -Wextra -Werror

all : $(NAME)

clean :
	${RM} ${OBJ}

fclean:		clean
	${RM} ${NAME}
	rm -rf shot.bmp

re:	fclean all

.PHONY:		all clean fclean re