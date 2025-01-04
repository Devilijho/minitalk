# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: safuente <safuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 18:06:19 by safuente          #+#    #+#              #
#    Updated: 2025/01/04 12:54:06 by safuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putstr_fd.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strtrim.c \
			  ft_substr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_putstr.c \
			  ft_putchar.c \
			  ft_putnbr.c

SRCS_BONUS	= ft_lstadd_back.c \
			  ft_lstadd_front.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstlast.c \
			  ft_lstnew.c \
			  ft_lstsize.c \
			  ft_lstiter.c \
			  ft_lstiter.c \
			  ft_lstmap.c

OBJS_PRINTF = ft_printf/ft_printf.o ft_printf/ft_chars.o ft_printf/ft_ints.o ft_printf/ft_hex.o ft_printf/ft_extra.o

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

CC			= cc -Wall -Wextra -Werror

%.o: %.c
			${CC} -I. -c $< -o $@

all:		${NAME}

$(NAME):	${OBJS}
			${MAKE} -C ft_printf/
			ar rcs ${NAME} ${OBJS} ${OBJS_PRINTF}
			cp ${PRINTF_LIB} ${NAME}

bonus:	${NAME} .bonus_done

.bonus_done: ${NAME} ${OBJS_BONUS}
	ar -rcs ${NAME} ${OBJS_BONUS}
	touch .bonus_done

clean:
			rm -f ${OBJS} ${OBJS_BONUS} .bonus_done
			${MAKE} -C ft_printf/ fclean

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
