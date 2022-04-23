# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 01:07:12 by kfujita           #+#    #+#              #
#    Updated: 2022/04/24 03:49:50 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftprintf.a

SRC_DIR	=	./ft_printf
SRCS	=	check_no_opt_str.c \
			ft_printf.c \
			is_valid_conv_char.c \
			parse_format.c \
			parse_opt_c_str.c \
			parse_opt_num.c \
			parse_opt_ptr.c \
			print_all.c \
			util.c \

SRCS_B	=	$(SRCS) \
			is_valid_flag_char_bonus.c \
			parse_opt_bonus.c \
			parse_opt_flags_bonus.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_B	=	$(addprefix $(OBJ_DIR)/, $(SRCS_B:.c=.o))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

CFLAGS	=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(SRC_DIR)

CC		=	cc

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	ar r $@ $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT):
	$(LIBFT_MAKE)
	cp $(LIBFT) ./$(NAME)

bonus:	$(OBJS_B) $(LIBFT)
	ar r $(NAME) $(OBJS_B)

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJS)
	rm -d $(OBJ_DIR) || exit 0

fclean:	clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
