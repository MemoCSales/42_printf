NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

SRC = ft_printf.c printchar.c printstring.c \
		printdecimal.c printunsigned.c \
		printhexa.c

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) ./ft_printf.h
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re