# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouddou <ybouddou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 22:34:18 by ybouddou          #+#    #+#              #
#    Updated: 2021/04/18 12:29:23 by ybouddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_memset.c\
	  ft_bzero.c\
	  ft_strlen.c\
	  ft_strdup.c\
	  ft_strlcpy.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isprint.c\
	  ft_substr.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_strsplit.c\
	  ft_strsplittools.c\
	  ft_itoa.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  get_next_line.c\

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
