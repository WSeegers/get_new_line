# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/23 21:40:52 by wseegers          #+#    #+#              #
#    Updated: 2018/05/23 21:54:35 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl_test
CC = clang
CFLAGS = -Wall -Wextra -Werror -I ../libft/includes -I ../

all : $(NAME)

$(NAME) : ../libft/libft.a get_next_line.o
	$(CC) $(CFLAGS) -o $@ main.c $?

get_next_line.o :
	$(CC) $(CFLAGS) -c -o $@ ../get_next_line.c

../libft/libft.a :
	make -C ../libft/ fclean && make -C ../libft/

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
