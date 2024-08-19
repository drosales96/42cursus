NAME = push_swap

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
ORANGE = \033[38;5;209m
RED = \033[1;91m

SRCS = main.c \
       argv_tratement.c \
       do_moves.c \
       ft_push.c \
       ft_reverse_rotate.c \
       ft_rotate.c \
       ft_swap.c \
       mo_costs.c \
       pos_target.c \
       sort_three.c \
       sorting.c \
       stack_utils.c \
       utils.c

CHECKER_PATH = checker_bonus
CHECKER_EXEC = $(CHECKER_PATH)/checker_bonus
CHECKER_SRCS = $(CHECKER_PATH)/checker_bonus.c
LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a
GET_NEXT_LINE_PATH = get_next_line
GET_NEXT_LINE_SRCS = $(GET_NEXT_LINE_PATH)/get_next_line.c \
                     $(GET_NEXT_LINE_PATH)/get_next_line_utils.c
GET_NEXT_LINE_OBJS = $(GET_NEXT_LINE_SRCS:.c=.o)

CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@echo "${BLUE} x $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@


$(GET_NEXT_LINE_PATH)/%.o: $(GET_NEXT_LINE_PATH)/%.c
	@echo "${BLUE} x $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME) $(CHECKER_EXEC)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "${BLUE}Linking objects and creating executable..."
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf
	@echo "${GREEN}Compiled $(NAME)!"

$(CHECKER_EXEC): $(CHECKER_SRCS) $(GET_NEXT_LINE_OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "${BLUE}Building checker executable..."
	@$(CC) $(CHECKER_SRCS) $(GET_NEXT_LINE_OBJS) -o $(CHECKER_EXEC) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf
	@echo "${GREEN}Compiled $(CHECKER_EXEC)!"

$(LIBFT_ARCHIVE):
	@echo "${BLUE}Building libft...${DEF_COLOR}"
	@$(MAKE) -C $(LIBFT_PATH) all

$(FT_PRINTF_ARCHIVE):
	@echo "${BLUE}Building ft_printf...${DEF_COLOR}"
	@$(MAKE) -C $(FT_PRINTF_PATH) all

clean:
	@echo "${BLUE}Cleaning object files...${DEF_COLOR}"
	@$(RM) $(OBJS) $(GET_NEXT_LINE_OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@$(MAKE) -C $(CHECKER_PATH) clean
	@echo "${GREEN}All object files are clean!"

fclean: clean
	@echo "${BLUE}Cleaning executable and libraries...${DEF_COLOR}"
	@$(RM) $(NAME)
	@$(RM) $(CHECKER_EXEC)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@$(MAKE) -C $(CHECKER_PATH) fclean
	@echo "${GREEN}All object files and executables are clean!"

re: fclean all

.PHONY: all clean fclean re
