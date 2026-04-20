# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_DIR = ./srcs
INC_DIR = ./includes
AR = ar -rcs
# obtener archivos fuente del directorio srcs
SRCS = $(shell find $(SRC_DIR) -name '*.c')
# obtener todos los .o (generados despues)
OBJS = $(SRCS:.c=.o)

# regla by default
all: $(NAME)
# crear archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c -o $@ $<
# Compilar la biblioteca
$(NAME): $(OBJS)
	$(AR) $(NAME) $^
# remover todos los .0
clean:
	rm -f $(OBJS)
 # llamar a clean  y remover el binario (libreria .a)
fclean: clean
	rm -f $(NAME)
# llamar a fclean y hacer un make
re: fclean $(NAME)
