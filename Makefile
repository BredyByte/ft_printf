NAME = libftprintf.a
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = ar -rcs
REMOVE = rm -rf

SRC = ft_putvoid.c ft_puthexa.c ft_itoalong.c ft_putdeclong.c ft_putdec.c ft_putchar.c ft_putstr.c ft_printf.c
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

LIBFT_PATH = ./libft
OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./inc

R = \033[31;1m
G = \033[32;1m
B = \033[34;1m
M = \033[35;1m
C = \033[36;1m
Y = \033[33;1m
END = \033[0m

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make bonus -C $(LIBFT_PATH)
	cp $(LIBFT) ./$@
	$(ARFLAGS) $@ $(OBJ)
	@echo "\n$(G)[Compiled $(C)'$@' $(G)successfully]\n$(END)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/ft_printf.h
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	$(REMOVE) $(OBJ) $(OBJ_PATH)
	make clean -C $(LIBFT_PATH)
	@echo "\n$(Y)[Cleaned $(C) $(NAME) objects $(Y)successfully]\n$(END)"

fclean: clean
	$(REMOVE) $(NAME)
	make fclean -C $(LIBFT_PATH)
	@echo "$(R)[Removed $(C)'$(NAME)' $(R)successfully]\n$(END)"

re: fclean all