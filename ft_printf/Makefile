# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmeurant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/15 16:08:31 by dmeurant          #+#    #+#              #
#    Updated: 2023/04/19 23:03:31 by dmeurant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${filter-out $(wildcard *_bonus.c), $(wildcard *.c)}
OBJS = $(patsubst %.c, %.o, $(SRCS))
SRCS_BONUS = $(wildcard *.c)
OBJS_BONUS = $(patsubst %.c, %.o, $(SRCS_BONUS))
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

bonus : $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS_BONUS)

.PHONY : all clean fclean re bonus