# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safuente <safuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 19:25:08 by safuente          #+#    #+#              #
#    Updated: 2024/12/30 12:36:47 by safuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ft_printf.c ft_chars.c ft_ints.c ft_hex.c ft_extra.c

OBJS	= ${SRC:.c=.o}

NAME	= libftprintf.a

CC		= cc -Wall -Wextra -Werror

%.o: %.c
			${CC} -I. -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
