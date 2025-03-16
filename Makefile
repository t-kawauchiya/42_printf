NAME = libftprintf.a

INCDIR = include/

SRC_DIR = src/
SRC_FILES = ft_printhex.c ft_printint.c ft_printuint.c ft_printptr.c ft_printf.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(SRC:.c=.o)

HEADER=$(INCDIR)/ft_printf.h

LIBFTDIR = libft/
LIBFT = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFTDIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "Archive $(NAME) created successfully!"

$(LIBFT):
	@make -C $(LIBFTDIR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFTDIR) clean
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "$(NAME) removed."

re: fclean all

test: re
	@cc test.c -L. -lftprintf -o runtest
	@./runtest

.PHONY: all clean fclean re
