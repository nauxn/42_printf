# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nisim <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/09 15:05:36 by nisim             #+#    #+#              #
#    Updated: 2026/08/20 20:32:30 by nisim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar rcs
RM		= rm -f

SRCS		= ft_printf.c ft_printf_utils.c ft_printf_utils_hex.c 
BONUS_SRCS	= bonus/ft_printf_bonus.c \
		  bonus/ft_printf_utils_bonus.c \
		  bonus/ft_printf_flags_bonus.c \
		  bonus/ft_printf_utils_flags_bonus.c \
		  bonus/ft_printf_utils_hex_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

%.o	: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c 
	$(CC) $(CFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(RM) .bonus_flag
	$(AR) $(NAME) $(OBJS)
	
bonus	: .bonus_flag

.bonus_flag	: $(BONUS_OBJS)
	$(RM) $(OBJS) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus_flag

clean	:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus_flag

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all bonus clean fclean re
