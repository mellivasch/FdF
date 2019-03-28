# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mivasche <mivasche@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:23:44 by mivasche          #+#    #+#              #
#    Updated: 2018/11/02 17:23:51 by mivasche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=*.c
OBJECTS=*.o

all: $(NAME)

$(NAME):
	gcc -I libft.h -c $(SRCS) -Wall -Wextra -Werror
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all