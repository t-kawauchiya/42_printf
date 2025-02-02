NAME = libftprintf.a

CC = cc
INCDIR=./include
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

SRC = ft_printf.c ft_printhex.c ft_printint.c ft_printuint.c ft_printptr.c
OBJ = $(SRC:.c=.o)

LIBFTDIR = libft
LIBFT = libft.a
HEADER=$(INCDIR)/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFTDIR)/$(LIBFT) $(NAME)
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

.PHONY: all clean fclean re
