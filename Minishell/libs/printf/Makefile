
NAME = libftprintf.a

FILES = 	ft_found_c.c\
			ft_found_d.c\
			ft_found_p.c\
			ft_found_s.c\
			ft_found_u.c\
			ft_found_hex.c\
			ft_printf.c

OBJ = $(FILES:.c=.o)

CC = gcc
RM = @rm -f
FLAGS = -Wall -Werror -Wextra
AR = ar crs

all: $(NAME)
$(NAME):  $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): $(FILES)
	@echo "Compiling files, please wait...\n"
	$(CC) $(FLAGS) -c $^ 

clean:

	${RM} $(OBJ)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all re clean fclean