# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 06:23:32 by kfujita           #+#    #+#              #
#    Updated: 2022/04/23 22:52:58 by kfujita          ###   ########.fr        #
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

SRCS04	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

SRCS_AD	=	ft_strtol.c \
			ft_strndup.c \
			ft_strnlen.c \
			ft_min.c \
			ft_max.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS04	=	$(addprefix $(OBJ_DIR)/, $(SRCS04:.c=.o))
OBJS_AD	=	$(addprefix $(OBJ_DIR)/, $(SRCS_AD:.c=.o))

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

all:	$(NAME)

$(NAME):	$(OBJS) $(OBJS04) $(OBJS_AD)
	ar r $@ $^

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

bonus:	$(NAME)

clean:
	rm -f $(OBJS) $(OBJS04) $(OBJS_AD)
	rm -d $(OBJ_DIR) || exit 0

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
