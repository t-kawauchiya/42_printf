# プロジェクトの名前
NAME = libft.a

# コンパイラとフラグ
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)
INCDIR=../include
HEADER=$(INCDIR)/libft.h

# ソースファイルとオブジェクトファイル
SRC = ft_isdigit.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c \
ft_atoi.c ft_isprint.c ft_memset.c ft_strdup.c ft_strncmp.c \
ft_bzero.c ft_itoa.c ft_putchar_fd.c ft_striteri.c ft_strnstr.c \
ft_calloc.c ft_lstnew.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
ft_isalnum.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
ft_isascii.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c
OBJ = $(SRC:.c=.o)

# ルール
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Archive $(NAME) created successfully!"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -f $(OBJ)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed."

re: fclean all

# 無関係なファイルとして扱う
.PHONY: all clean fclean re
