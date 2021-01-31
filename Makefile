# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elegija <elegija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/10 18:48:30 by msafflow          #+#    #+#              #
#    Updated: 2021/01/31 06:50:44 by elegija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

sources			=	sources/cub3d.c \
					sources/flags.c \
                	sources/parsing_main.c \
					sources/rc_utils.c \
					sources/mv.c \
					sources/rc_texture_utils.c \
					sources/rc_texture.c \
					sources/buttons.c \
					sources/bmp.c \
					sources/parsing_clr_and_res.c \
					sources/parsing_map.c \
					sources/parsing_pos.c \
					sources/parsing_utils.c \
					sources/error.c \
					sources/sort.c \
					sources/rc_raycast.c \
					sources/rc_sprites.c \

includesS		=	includes/cub3d.h\

OBJS			= $(sources:.c=.o)

NAME			= cub3D
CC				= clang
CFLAGS			= -O3 -Wall -Wextra -Werror -g -Iincludes/ -Imlx/ -Ilibft/includes/
RM				= rm -f
MLX				= libmlx.dylib
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft
LIBFT			= ./libft/libft.a

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJS) $(includesS)
				@cp mlx/$(MLX) .
				clang ${CFLAGS} -o cub3D ${OBJS} ${LIBS}
				@echo "Done"

$(LIBFT):
				@make -C libft

$(MLX):
				@make -C mlx

clean:
					$(RM) $(OBJS)
					@make clean -C libft

fclean:			clean
					$(RM) $(NAME) $(MLX) $(LIBFT)
					@make clean -C mlx 

re:				fclean $(NAME)

bonus:			all

.PHONY:			all clean fclean re