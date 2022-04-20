# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 06:23:32 by kfujita           #+#    #+#              #
#    Updated: 2022/04/21 01:46:33 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_atoi.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memmove.c \
			ft_putendl_fd.c \
			ft_split.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_strtrim.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isprint.c \
			ft_memcmp.c \
			ft_memset.c \
			ft_putnbr_fd.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strmapi.c \
			ft_strrchr.c \
			ft_substr.c \
			ft_calloc.c \
			ft_isascii.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_striteri.c \
			ft_tolower.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

all:	$(NAME)

$(NAME):	$(OBJS)
	ar r $@ $^

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJS)
	rmdir $(OBJ_DIR) || exit 0

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
