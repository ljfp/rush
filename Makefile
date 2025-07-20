CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-01
SRCS = *.c

all:
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	rm -f $(NAME)

re: clean all

test: all
	@chmod +x test.sh
	@./test.sh

.PHONY: all clean re test
