NAME			= miniRT
LIBFT			= libft.a
LIBFT_DIR		= ./libft/
CC				= clang
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror
INCLUDES		= ./includes
SRC_DIR			= ./sources/
SRC				= minirt.c			errors.c			checks.c
OBJ				= $(addprefix $(SRC_DIR), $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(OBJ)
					echo "Libft is compiling..."
					make -C $(LIBFT_DIR)
					cp $(addprefix $(LIBFT_DIR), $(LIBFT)) .
					echo "Libft is compiled successfully!"
					$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft
					echo "\n\n"
					echo "miniRT is done!"

%.o:		%.c
					@$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@
					@echo "Compiled $< successfully..."

clean:
					make clean -C $(LIBFT_DIR)
					$(RM) $(OBJ) $(LIBFT)

fclean: 	clean
					$(RM) $(NAME)

re: fclean all

.PHONY:		all, clean, fclean, re