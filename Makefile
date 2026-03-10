# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 11:49:10 by fadzejli          #+#    #+#              #
#    Updated: 2025/04/30 14:40:04 by fadzejli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror -g
SRCS = ft_printf.c utils.c utils2.c
OBJS = $(SRCS:.c=.o)
INC = ft_printf.h

all : $(NAME)

%.o: %.c $(INC)
	$(CC) -c $< -o $@

$(NAME): $(OBJS) $(INC)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re all clean fclean
