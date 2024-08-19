NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -g

SRCS = get_next_line.c \
		checker_bonus.c 
		
OBJS = $(SRCS:.c=.o)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
