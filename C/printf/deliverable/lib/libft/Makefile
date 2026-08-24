# vars
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC_DIR = .
INC_DIR = .
AR = ar -rcs
# obtener archivos fuente del directorio srcs
SRCS =	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
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
	ft_toupper.c
# obtener todos los .o (generados despues)
OBJS = $(SRCS:.c=.o)

# regla by default
all: $(NAME)
# bonus: all
# crear archivos .o
%.o: %.c Makefile libft.h
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
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

# ensure not to call files with the same name as the functions
.PHONY: clean fclean re all
