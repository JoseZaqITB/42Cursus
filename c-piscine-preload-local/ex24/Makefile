# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_DIR = ./srcs
INC_DIR = ./includes
AR = ar -rcs
# obtener archivos fuente del directorio srcs
SRCS = $(shell find $(SRC_DIR) -name '*.c')
# obtener archivos de encabezado del directorio includes
INCS = $(shell find $(INC_DIR) -name '*.h')

# regla by default
all: $(NAME)
# crear archivos .o
%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<
# Compilar la biblioteca
$(NAME): $(OBJS)
$(AR)
