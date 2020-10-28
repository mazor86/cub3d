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

OBJ_DIR			= ./objects/

SRC				=	checks.c\
					copy.c\
					cylinder_inter.c\
					errors.c\
					get_next_line_utils.c\
					get_next_line.c\
					image.c\
					math_utils.c\
					minirt.c\
					parse.c\
					plane_inter.c\
					sphere_inter.c\
					square_inter.c\
					trace_ray.c\
					triangle_inter.c\
					utils.c\
					validate_obj.c\
					validate_scene.c\
					vector_operation.c\
					window.c

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