CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCDIR  = srcs
INCDIR  = includes

# Source files (relative to SRCDIR)
SRC     = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS    = $(addprefix $(SRCDIR)/,$(SRC))

# Object files (next to .c files in srcs/)
OBJS    = $(SRCS:.c=.o)

NAME    = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/ft.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
