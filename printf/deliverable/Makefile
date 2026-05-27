# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC_DIR = .
AR = ar -rcs
# header settings
INC_DIR = .
# lib settings
LIB_DIR = ./lib/libft
LIB_A = $(LIB_DIR)/libft.a
# add all flagas
CFLAGS += -I$(LIB_DIR) -I$(INC_DIR)
# obtener archivos fuente del directorio srcs
SRCS =	ft_printf.c \
	ft_putnbr_count.c \
	ft_putstr_count.c \
# obtener todos los .o (generados despues)
OBJS = $(SRCS:.c=.o)

# regla by default
all: $(LIB_A) $(NAME)

# compile libft
$(LIB_A):
	$(MAKE) -C $(LIB_DIR)

# bonus: all
# crear archivos .o
%.o: %.c Makefile libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@
# Compilar la biblioteca
$(NAME): $(LIB_A) $(OBJS)
	cp $(LIB_A) $(NAME)
	$(AR) $(NAME) $(OBJS)
# remover todos los .0
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean
 # llamar a clean  y remover el binario (libreria .a)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
# llamar a fclean y hacer un make
re: fclean $(NAME) $(LIB_A)

# ensure not to call files with the same name as the functions
.PHONY: clean fclean re all
