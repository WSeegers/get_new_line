# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: WSeegers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/14 12:34:01 by WSeegers          #+#    #+#              #
#    Updated: 2018/05/13 22:10:41 by wseegers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -I ./includes
SRC = ft_strtol.c ft_isalpha.c ft_memset.c ft_lstiter.c ft_strnstr.c \
		ft_strdup.c ft_strlen.c ft_strnlen.c ft_islower.c ft_strncpy.c \
		ft_strnew.c ft_strnequ.c ft_strchr.c ft_memccpy.c ft_strdel.c \
		ft_putendl.c ft_striteri.c ft_strncmp.c ft_isblank.c ft_putstr_fd.c \
		ft_lstradd.c ft_itostr.c ft_max.c ft_isalnum.c ft_strjoin.c \
		ft_strncat.c ft_strmapi.c ft_putnbr.c ft_putchar.c ft_memcmp.c \
		ft_strlcat.c ft_memalloc.c ft_strsplit.c ft_itoa.c ft_toupper.c \
		ft_min.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_strmap.c \
		ft_putstr.c ft_intlen.c ft_isdigit.c ft_memdel.c ft_isprint.c \
		ft_tolower.c ft_abs.c ft_isspace.c ft_strtrim.c ft_isascii.c  \
		ft_strcmp.c ft_strcat.c ft_lstnew.c ft_putendl_fd.c \
		ft_toascii.c ft_strrchr.c ft_strcpy.c \
		ft_putnbr_fd.c ft_lstdel.c ft_isupper.c ft_bzero.c ft_atoi.c \
		ft_strstr.c ft_strequ.c ft_strsub.c ft_lstmap.c ft_strclr.c \
		ft_putchar_fd.c ft_lstdelone.c ft_putbyte.c ft_striter.c ft_lstadd.c

O_PATH = ./.obj/
OBJ := $(addprefix $(O_PATH),$(SRC:.c=.o))
DEP = $(SRC:%.c=$(O_PATH)%.d)


NAME_SO = libft.so
SO_PATH = ./.obj_so/
SO_OBJ :=  $(addprefix $(SO_PATH),$(SRC:.c=.o))

all: $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $?
	ranlib $(NAME)

$(O_PATH)%.o : %.c
	@mkdir -p $(O_PATH)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEP)

so : $(NAME_SO)

$(NAME_SO) : $(SO_OBJ)
	gcc -shared -o libft.so $?

$(SO_PATH)%.o : %.c
	@mkdir -p $(SO_PATH)
	$(CC) $(CFLAGS) -fpic -c $< -o $@

clean :
	rm -f $(OBJ) $(DEP) $(SO_OBJ)

fclean : clean
	rm -f $(NAME) $(NAME_SO)

re : fclean all

