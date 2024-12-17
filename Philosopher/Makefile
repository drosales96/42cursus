# ══ Names ═══════════════════════════════════════════════════════════════════ #

NAME                    = philo

# ══ Colors ══════════════════════════════════════════════════════════════════ #

DEL_LINE                = \033[2K
ITALIC                  = \033[3m
BOLD                    = \033[1m
DEF_COLOR               = \033[0m
GREEN                   = \033[0;92m
YELLOW                  = \033[0;93m
RED                     = \033[0;91m

# ══ Compilation══════════════════════════════════════════════════════════════ #

CC                      = clang
RM                      = rm -f
MKD                     = mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #

OBJ_DIR                 = ./obj
INCLUDES_DIR            = ./includes
SRC_DIR                 = ./src
MAIN_DIR                = ./main
INIT_DIR				= ./init

# ══ Flags ═══════════════════════════════════════════════════════════════════ #

CFLAGS                  = -Wall -Werror -Wextra -O3 -pthread 
INCLUDES                = -I$(INCLUDES_DIR)

# ══ Sources ═════════════════════════════════════════════════════════════════ #

SRC                     = ${SRC_DIR}/ft_utils.c \
							${SRC_DIR}/ft_thread_creation.c \
							${SRC_DIR}/ft_routine_tools.c \
							${SRC_DIR}/ft_print_status.c \
							${SRC_DIR}/ft_eating_checker.c \
							${SRC_DIR}/ft_dead_utils.c \
                          	${SRC_DIR}/ft_arg_checker.c
MAIN                    = ${MAIN_DIR}/main.c
INIT					= ${INIT_DIR}/ft_init_table.c \
							${INIT_DIR}/ft_init_philos.c \
							${INIT_DIR}/ft_init_arguments.c \
							${INIT_DIR}/ft_init_forks.c

# ══ Objects ═════════════════════════════════════════════════════════════════ #

OBJ_MAIN                = $(patsubst ${MAIN_DIR}/%.c, ${OBJ_DIR}/%.o, ${MAIN})
OBJ_SRC                 = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_INIT                = $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INIT})

# ══ Rules ══════════════════════════════════════════════════════════════════ #

all: ${NAME}

${NAME}: ${OBJ_MAIN} ${OBJ_SRC} ${OBJ_INIT}
	@echo "$(YELLOW)Compiling...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJ_MAIN} ${OBJ_SRC} ${OBJ_INIT}
	@echo "$(GREEN)$(NAME) created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJ_DIR}/%.o: ${MAIN_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

clean:
	@echo "$(GREEN)Removing object files!$(DEF_COLOR)"
	@find ${OBJ_DIR} -name "*.o" -type f -delete
	@echo "$(GREEN)Object files removed!$(DEF_COLOR)"

fclean: clean
	@echo "$(GREEN)Removing binaries!$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(GREEN)Binaries removed!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
