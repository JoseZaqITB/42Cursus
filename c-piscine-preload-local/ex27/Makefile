# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
SRC_DIR = ./
# obtener archivos fuente del directorio srcs
SRCS = $(shell find $(SRC_DIR) -name '*.c')
# obtener todos los .o (generados despues)
OBJS = $(SRCS:.c=.o)

# regla by default
all: $(NAME)
# crear archivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# Compilar la biblioteca
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
# remover todos los .0
clean:
	rm -f $(OBJS)
 # llamar a clean  y remover el binario (libreria .a)
fclean: clean
	rm -f $(NAME)
