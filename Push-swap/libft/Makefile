NAME = libft.a
FILES = ft_atoi.c\
    ft_bzero.c\
    ft_isalnum.c\
    ft_isalpha.c\
    ft_isascii.c\
    ft_isdigit.c\
    ft_isprint.c\
    ft_memcpy.c\
    ft_memset.c\
    ft_strchr.c\
    ft_strlcpy.c\
    ft_strlen.c\
    ft_strncmp.c\
    ft_strnstr.c\
    ft_strrchr.c\
    ft_tolower.c\
    ft_toupper.c\
    ft_strlcat.c\
    ft_memcmp.c\
    ft_memchr.c\
    ft_calloc.c\
    ft_strdup.c\
    ft_memmove.c\
    ft_substr.c\
    ft_strjoin.c\
    ft_strtrim.c\
    ft_split.c\
    ft_itoa.c\
    ft_strmapi.c\
    ft_striteri.c\
    ft_putchar_fd.c\
    ft_putstr_fd.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    
BFILES = ft_lstnew_bonus.c\
    ft_lstadd_front_bonus.c\
    ft_lstsize_bonus.c\
    ft_lstlast_bonus.c\
    ft_lstadd_back_bonus.c


OBJ = $(FILES:.c=.o)
OBJB = $(BFILES:.c=.o)
RM = @rm -f
FLAGS =	-Wall -Werror -Wextra
$(NAME): $(FILES) $(OBJ)
	@gcc -c $(FLAGS) $(FILES) $(BFILES)
	@ar rcs $(NAME) $(OBJ) $(OBJB)
bonus: $(OBJ) $(OBJB)
	@ar rcs $(NAME) $(OBJ) $(OBJB)
all: $(NAME)
clean:
	${RM} $(OBJ) $(OBJB)
fclean: clean
	${RM} $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
