# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 13:39:50 by ybouddou          #+#    #+#              #
#    Updated: 2021/05/04 11:01:49 by ybouddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
LIB_PATH = Libft
LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	check.c\
		utils.c\
		sorting.c\
		instructions.c\
		stack.c\
		instruc.c\
		cases.c\
		cases_tools.c\

SRC1 = checker.c\

SRC2 = push_swap.c\

OBJ = $(SRC:.c=.o)
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJ) $(OBJ1) $(LIB)
	@gcc $(OBJ) $(OBJ1) $(LIB_PATH)/$(LIB) -o $(CHECKER)

$(PUSH_SWAP): $(OBJ) $(OBJ2) $(LIB)
	@gcc $(OBJ) $(OBJ2) $(LIB_PATH)/$(LIB) -o $(PUSH_SWAP)

$(LIB):
	@make -C $(LIB_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@make clean -C $(LIB_PATH)/
	@rm -rf $(OBJ) $(OBJ1) $(OBJ2)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(CHECKER) $(PUSH_SWAP)

re: fclean all
