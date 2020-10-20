NAME			= miniRT

LIBFT			= libft.a

LIBFT_DIR		= ./libft/

LIB_LINK		= -L$(LIBFT_DIR) -lft

MLX				= libmlx.a

MLX_DIR			= ./mlx_linux

MLX_LINK		= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

CC				= clang

RM				= rm -rf

FLAGS			= -Wall -Wextra -O0

INCLUDES		= ./includes

SRC_DIR			= ./sources/

SRC				= minirt.c			errors.c			checks.c\
				  get_next_line.c	get_next_line_utils.c\
				  parse.c			utils.c\
				  validate_obj.c	validate_scene.c\
				  math_utils.c

OBJ				= $(addprefix $(SRC_DIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
					@echo "Libft is compiling..."
					@make bonus -C $(LIBFT_DIR)
					@echo "Libft is compiled successfully!"
					@echo "mlx is compiling..."
					@make -C $(MLX_DIR)
					@echo "mlx is compiled successfully!"
					$(CC) -o $(NAME) $(OBJ) $(LIB_LINK) $(MLX_LINK) -g
					echo "\n\n"
					echo "miniRT is done!"

%.o:		%.c
					@$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@ -g
					@echo "Compiled $< successfully..."

clean:
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(OBJ) $(LIBFT)

fclean: 	clean
					$(RM) $(NAME)

re: fclean all

.PHONY:		all, clean, fclean, re

.SILENT:	