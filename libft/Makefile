# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/28 15:20:11 by vimucchi          #+#    #+#              #
#    Updated: 2019/03/06 15:13:41 by vimucchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra

SRC = \
						ft_atoi.c \
						ft_itoa.c \
						ft_memalloc.c \
						ft_memset.c \
						ft_putstr.c \
						ft_strdel.c \
						ft_strlen.c \
						ft_strnew.c \
						ft_tolower.c \
						ft_bzero.c \
						ft_lstadd.c \
						ft_memccpy.c \
						ft_putchar.c \
						ft_putstr_fd.c \
						ft_strdup.c \
						ft_strmap.c \
						ft_strnstr.c \
						ft_toupper.c \
						ft_isalnum.c \
						ft_lstdel.c \
						ft_memchr.c \
						ft_putchar_fd.c \
						ft_strcat.c \
						ft_strequ.c \
						ft_strmapi.c \
						ft_strrchr.c \
						ft_isalpha.c \
						ft_lstdelone.c \
						ft_memcmp.c \
						ft_putendl.c \
						ft_strchr.c \
						ft_striter.c \
						ft_strncat.c \
						ft_strsplit.c \
						ft_isascii.c \
						ft_lstiter.c \
						ft_memcpy.c \
						ft_putendl_fd.c \
						ft_strclr.c \
						ft_striteri.c \
						ft_strncmp.c \
						ft_strstr.c \
						ft_isdigit.c \
						ft_lstmap.c \
						ft_memdel.c \
						ft_putnbr.c \
						ft_strcmp.c \
						ft_strjoin.c \
						ft_strncpy.c \
						ft_strsub.c \
						ft_isprint.c \
						ft_lstnew.c \
						ft_memmove.c \
						ft_putnbr_fd.c \
						ft_strcpy.c \
						ft_strlcat.c \
						ft_strnequ.c \
						ft_strtrim.c \
						ft_putnbr_base.c \
						ft_strlcpy.c \
						ft_power.c \
						ft_sort_tab.c \
						ft_isspace.c \
						get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	@$(CC) $(FLAGS) -Iincludes -o $@ -c $<

$(NAME): $(OBJ) includes/libft.h includes/get_next_line.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: all, clean, fclean, re
