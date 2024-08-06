NAME	=	libftprintf.a

FILES	=	ft_printf.c \
			ft_puthex.c \
			ft_putcharf.c \
			ft_putnbrf.c \
			ft_putstrf.c \
			ft_putunsgf.c \
			ft_pointer.c

OBJ = $(FILES:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra
AR = ar crs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): %.o : %.c
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@
	@echo

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
