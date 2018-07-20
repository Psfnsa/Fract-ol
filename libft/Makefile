# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabanciu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/22 15:59:11 by mabanciu          #+#    #+#              #
#    Updated: 2018/05/22 15:59:13 by mabanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./includes/

FLAGS = -Wall -Werror -Wextra

SRC = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		apply_flags.c \
		char_handle.c \
		ft_itoa_long.c \
		ft_printf.c \
		hex_handle.c \
		init_data.c \
		int_handler.c \
		n_handle.c \
		octal_handle.c \
		parse_flags.c \
		parse_length.c \
		parse_precision.c \
		parse_specifiers.c \
		parse_width.c \
		percent_handle.c \
		print_string.c \
		string_handle.c \
		undefined_handle.c \
		unsigned_handle.c \
		wide_string.c \
		binary_handle.c \
		wide_things.c \
		adress_handle.c \
		ft_strncomplex.c \

### PATH ###
SRCS_PATH = src/
OBJ_PATH = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRC))
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
