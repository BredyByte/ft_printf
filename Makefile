NAME = libftprintf.a
SRC = ft_putchar.c ft_putstr.c ft_printf.c 
CC = cc
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
HEADERS = ft_printf.h libft/libft.h
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	@$(REMOVE) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(REMOVE) $(NAME)

re: fclean all
