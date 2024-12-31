
SRC_S = src/server.c

SRC_C = src/client.c

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

LIBFT = libft/libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

all: server client

server: ${OBJ_S} libft_build
	${CC} ${FLAGS} ${OBJ_S} ${LIBFT} -o server

client: ${OBJ_C} libft_build
	${CC} ${FLAGS} ${OBJ_C} ${LIBFT} -o client

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f $(OBJ_S) ${OBJ_C}

fclean: clean
	${MAKE} -C libft/ fclean
	rm -f client server

libft_build:
	${MAKE} -C libft/ bonus

