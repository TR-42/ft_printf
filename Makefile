# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 01:07:12 by kfujita           #+#    #+#              #
#    Updated: 2022/04/22 20:36:52 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a

SRC_DIR	=	./ft_printf
SRCS	=	$(SRC_DIR)/ft_printf.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	ar r $@ $^

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT):
	$(LIBFT_MAKE)

bonus:	$(NAME)

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJS)
	rm -d $(OBJ_DIR) || exit 0

fclean:	clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
