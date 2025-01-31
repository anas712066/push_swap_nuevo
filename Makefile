# Nombre del ejecutable
NAME = push_swap

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRCS = main.c \
       operations.c \
	   parsing.c \
	   sorting.c \
	   utils.c \
	   push_swap.c
OBJS = $(SRCS:.c=.o)

# Ruta de la libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Reglas principales
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all
	make -C $(LIBFT_DIR) bonus  # Invoca el bonus de libft

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re