NAME = push_swap

DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m

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
       sort_utils.c \
       sorting.c \
       stack_utils.c \
       utils.c

LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a

CC = gcc
RM = rm -f
FLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@echo "${BLUE} x $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
	@echo "${BLUE}Linking objects and creating executable..."
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft -L$(FT_PRINTF_PATH) -lftprintf
	@echo "${GREEN}Compiled $(NAME)!"

$(LIBFT_ARCHIVE):
	@echo "${BLUE}Building libft...${DEF_COLOR}"
	@$(MAKE) -C $(LIBFT_PATH) all

$(FT_PRINTF_ARCHIVE):
	@echo "${BLUE}Building ft_printf...${DEF_COLOR}"
	@$(MAKE) -C $(FT_PRINTF_PATH) all

clean:
	@echo "${BLUE}Cleaning object files...${DEF_COLOR}"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean
	@echo "${GREEN}All object files are clean!"

fclean: clean
	@echo "${BLUE}Cleaning executable and libraries...${DEF_COLOR}"
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@echo "${GREEN}All object files and executables are clean!"

re: fclean all

.PHONY: all clean fclean re
