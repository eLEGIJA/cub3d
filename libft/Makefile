NAME = libft.a

INC_DIR		= 	./includes
SRC_DIR		= 	./sources
OBJ_DIR		= 	./obj
PFT_DIR		= 	./pft

HEAD		=	$(INC_DIR)/libft.h\
				$(INC_DIR)/get_next_line.h\
				$(INC_DIR)/ft_printf.h

SRC			=	ft_atoi.c\
				ft_isalpha.c\
				ft_itoa.c\
				ft_memcmp.c\
				ft_putchar_fd.c\
				ft_split.c\
				ft_strlcat.c\
				ft_strncmp.c\
				ft_substr.c\
				ft_bzero.c\
				ft_isascii.c\
				ft_memcpy.c\
				ft_putendl_fd.c\
				ft_strchr.c\
				ft_strlcpy.c\
				ft_strnstr.c\
				ft_tolower.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_putnbr_fd.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strrchr.c\
				ft_toupper.c\
				ft_isalnum.c\
				ft_isprint.c\
				ft_memchr.c\
				ft_memset.c\
				ft_putstr_fd.c\
				ft_strjoin.c\
				ft_strmapi.c\
				ft_strtrim.c\
				ft_lstdelone.c\
				ft_lstnew.c\
				ft_lstadd_back.c\
				ft_lstiter.c\
				ft_lstclear.c\
				ft_lstmap.c\
				ft_lstsize.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				get_next_line.c\
				ft_printf.c\
				ft_printf_cs.c\
				ft_printf_diux.c\
				ft_printf_p.c\
				ft_printf_pars.c\
				ft_putnbr_base_fd.c

OBJS		=	$(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

FLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ_DIR) $(OBJS) $(HEAD)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libft.a was created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	clang $(FLAGS) -g -c $< -I$(INC_DIR) -o $@ -MMD 

clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects was deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "libft.a was deleted"

re: fclean all

norm:
	@norminette

.PHONY: all clean fclean re norm pft