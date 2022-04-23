# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 01:07:12 by kfujita           #+#    #+#              #
#    Updated: 2022/04/24 04:59:37 by kfujita          ###   ########.fr        #
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

SRCS_M	=	parse_opt.c

SRCS_B	=	is_valid_flag_char_bonus.c \
			parse_opt_bonus.c \
			parse_opt_flags_bonus.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_M	=	$(addprefix $(OBJ_DIR)/, $(SRCS_M:.c=.o))
OBJS_B	=	$(addprefix $(OBJ_DIR)/, $(SRCS_B:.c=.o))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

CFLAGS	=	-Wall -Wextra -Werror -I $(LIBFT_DIR) -I $(SRC_DIR)

CC		=	cc

ifdef WITH_BONUS
OBJS += $(OBJS_B)
OBJS_TO_DEL	=	$(OBJS_M)
else
OBJS += $(OBJS_M)
OBJS_TO_DEL	=	$(OBJS_B)
endif

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar r $@ $(OBJS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $^

$(LIBFT):
	$(LIBFT_MAKE)

bonus:
	make WITH_BONUS=1

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJS_M) $(OBJS_B) $(OBJS)
	rm -d $(OBJ_DIR) || exit 0

fclean:	clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean
