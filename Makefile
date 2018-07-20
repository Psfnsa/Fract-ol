NAME = fractol

MLX_PATH = /usr/local/lib

LFT_PATH = ./libft

FLAGS = -Wall -Wextra -Werror

FRMW = -framework OpenGL -framework AppKit

LIBS = -L $(MLX_PATH) -lmlx -L $(LFT_PATH) -lft -lpthread

SRC = ./*.c

OBJ = $(SRC:.c=.o)

all:
	@make -C $(LFT_PATH)
	@gcc -I $(LFT_PATH)/includes $(FLAGS) -c $(SRC)
	@gcc $(LIBS) $(FRMW) $(OBJ) -o $(NAME) -I $(LFT_PATH)/includes $(FLAGS)

clean:
	@make clean -C $(LFT_PATH)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LFT_PATH)

re: fclean all
