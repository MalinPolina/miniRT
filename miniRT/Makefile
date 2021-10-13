
CC		= gcc

CFLAGS	=  -Wall -Wextra -Werror

LIBFT	= 	libft/libft.a

LFLAGS	=	-L . -lmlx

LMLX	=	libmlx.dylib

HEADER	=	includes

SRCS	=  main.c image.c \
		   parser.c parser_scene.c parser_obj.c parser_util.c \
		   gnl/get_next_line.c gnl/get_next_line_utils.c \
		   vector.c vector2.c\
		   colors.c \
		   raytracing.c camera.c\
		   bmp.c util.c ft_atof.c\
		   sphere.c plane.c triangle.c square.c cylinder.c \
		   light.c

OBJS	= ${SRCS:.c=.o}

RM		= rm -rf

NAME	= miniRT

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(LMLX) $(HEADER)
			$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(LMLX) $(OBJS) $(LIBFT) -o $@
$(LMLX):	
			$(MAKE) -C mlx
			mv mlx/$(LMLX) .

$(LIBFT):
			$(MAKE) -C libft

.c.o:		
			$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
			${MAKE} fclean -C ./libft
			${MAKE} clean -C ./mlx
			${MAKE}	clean -C ./minilibx_opengl
			${RM} ${OBJS}

fclean:		clean
			${RM} libmlx.dylib
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
