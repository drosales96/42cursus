# ______NAMES______ #

NAME = push_swap
BONUS_NAME = checker_bonus_executable  # Asegúrate de que este nombre sea único y no coincida con un directorio

# ______LIBRARIES______ #

LIBFT_PATH = libft
LIBFT_ARCHIVE = $(LIBFT_PATH)/libft.a
FT_PRINTF_PATH = ft_printf
FT_PRINTF_ARCHIVE = $(FT_PRINTF_PATH)/libftprintf.a

# ______FLAGS______ #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE)
RM = rm -f

# ______SOURCES______ #

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

BONUS_SRCS = bonus/checker_bonus.c \
             bonus/get_next_line.c 
 
# ______ FROM .C TO .O______ #

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# ______COLORS______ #

BLUE = \033[0;34m
DEF_COLOR = \033[0m

# ______RULES______ #

all: $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

$(LIBFT_ARCHIVE):
	@echo "${BLUE}Building libft...${DEF_COLOR}"
	@$(MAKE) -C $(LIBFT_PATH) all

$(FT_PRINTF_ARCHIVE):
	@echo "${BLUE}Building ft_printf...${DEF_COLOR}"
	@$(MAKE) -C $(FT_PRINTF_PATH) all

bonus: $(LIBFT_ARCHIVE) $(FT_PRINTF_ARCHIVE) $(BONUS_NAME) all

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(LIBS)

# ______CLEANING______ #

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)  # Elimina el ejecutable principal y el del bonus
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all bonus

.PHONY: all clean fclean re bonus
