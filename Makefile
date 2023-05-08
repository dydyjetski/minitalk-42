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

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FTPRINTF = ./ft_printf/libftprintf.a

CLIENT = client
SERVER = server

SRC_C = client.c
OBJ_C = $(SRC_C:%.c=%.o)

SRC_S = server.c
OBJ_S = $(SRC_S:%.c=%.o)


#Rules:
all: $(SERVER) $(CLIENT)

$(FTPRINTF):
	@$(MAKE) -C ./ft_printf

$(SERVER): $(OBJ_S) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(OBJ_S) $(FTPRINTF) -o server

$(CLIENT): $(OBJ_C) $(FTPRINTF)
	@$(CC) $(CFLAGS) $(OBJ_C) $(FTPRINTF) -o client

clean:
	@$(MAKE) clean -C ./ft_printf
	@$(RM) $(OBJ_S) $(OBJ_C)

fclean: clean
	@$(MAKE) fclean -C ./ft_printf
	@$(RM) $(SERVER) $(CLIENT)

re: fclean all