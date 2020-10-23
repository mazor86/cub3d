NAME			= miniRT

LIBFT			= libft.a

LIBFT_DIR		= ./libft/

LIB_LINK		= -L$(LIBFT_DIR) -lft

MLX				= libmlx.a

MLX_DIR			= ./mlx_linux/

MLX_LINK		= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

CC				= clang

RM				= rm -rf

FLAGS			= -Wall -Wextra -O0

INCLUDES		= ./includes/

SRC_DIR			= ./sources/

SRC				= minirt.c			errors.c			checks.c\
				  get_next_line.c	get_next_line_utils.c\
				  parse.c			utils.c				copy.c\
				  math_utils.c		validate_scene.c	validate_obj.c\

OBJ				= $(addprefix $(SRC_DIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
					@echo "linking...\n"
					$(CC) -o $(NAME) $(OBJ) $(LIB_LINK) $(MLX_LINK)
					@echo "miniRT is done!\n"

$(LIBFT):
					@echo "Creating $@ ..."
					make bonus -C $(LIBFT_DIR)
					@echo "$@ is done!\n"

$(MLX):
					@echo "Creating $@ ..."
					make -C $(MLX_DIR)
					@echo "$@ is done!\n"

%.o:		%.c
					$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@ -g
					@echo "Compiled $< successfully..."

clean:
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(OBJ) $(LIBFT)

fclean: 	clean
					$(RM) $(NAME)
					$(RM) $(LIBFT_DIR)$(LIBFT)
					$(RM) $(MLX_DIR)$(MLX)

re: fclean all

.PHONY:		all, clean, fclean, re

.SILENT:	$(LIBFT) $(MLX)