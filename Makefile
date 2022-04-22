# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 01:07:12 by kfujita           #+#    #+#              #
#    Updated: 2022/04/23 00:13:46 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a

SRC_DIR	=	./ft_printf
SRCS	=	ft_printf.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	cp $(LIBFT) ./$@
	ar r $@ $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
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
