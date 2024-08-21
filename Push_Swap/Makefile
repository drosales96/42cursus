# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME                = push_swap
NAME_BONUS          = checker

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE            = \033[2K
ITALIC              = \033[3m
BOLD                = \033[1m
DEF_COLOR           = \033[0;39m
GRAY                = \033[0;90m
RED                 = \033[0;91m
GREEN               = \033[0;92m
YELLOW              = \033[0;93m
BLUE                = \033[0;94m
MAGENTA             = \033[0;95m
CYAN                = \033[0;96m
WHITE               = \033[0;97m
BLACK               = \033[0;99m
ORANGE              = \033[38;5;209m
BROWN               = \033[38;2;184;143;29m
DARK_GRAY           = \033[38;5;234m
MID_GRAY            = \033[38;5;245m
DARK_GREEN          = \033[38;2;75;179;82m
DARK_YELLOW         = \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC                  = clang
AR                  = ar rcs
RM                  = rm -f
MK                  = make -C
MKD                 = mkdir -p
MCL                 = make clean -C
MFCL                = make fclean -C
MK_                 = && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

SRC_DIR             = ./src
INIT_DIR            = ./init
MOVES_DIR           = ./moves
SORT_DIR            = ./sort
UTILS_DIR           = ./utils
OBJ_DIR             = ./obj
LIBFT_DIR           = ./libft
PRINTFT_DIR         = ./ft_printf
INCLUDES_DIR        = ./inc

# ══ Bonus Directories ═══════════════════════════════════════════════════════ #
#    -----------------      #

SRC_BONUS_DIR       = ./bonus
INCLUDES_BONUS_DIR  = ./bonus

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A             = ${LIBFT_DIR}/libft.a
PRINTFT_A           = ${PRINTFT_DIR}/libftprintf.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS              = -Wall -Werror -Wextra
IFLAGS              = -I${INCLUDES_DIR}
LFLAGS              = -L${LIBFT_DIR} -lft -L${PRINTFT_DIR} -lftprintf 

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

IFLAGS_BONUS        = -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC                 = ${SRC_DIR}/main.c
INT                 = ${INIT_DIR}/argv_tratement.c \
                        ${INIT_DIR}/mo_costs.c \
                        ${INIT_DIR}/pos_target.c
MOV                 = ${MOVES_DIR}/do_moves.c \
                        ${MOVES_DIR}/ft_push.c \
                        ${MOVES_DIR}/ft_reverse_rotate.c \
                        ${MOVES_DIR}/ft_rotate.c \
                        ${MOVES_DIR}/ft_swap.c
SRT                 = ${SORT_DIR}/sorting.c \
                        ${SORT_DIR}/sort_three.c 
UTL                 = ${UTILS_DIR}/stack_utils.c \
                        ${UTILS_DIR}/utils.c \
                        ${UTILS_DIR}/utils2.c

OBJ_SRC             = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_INT             = $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_MOV             = $(patsubst ${MOVES_DIR}/%.c, ${OBJ_DIR}/%.o, ${MOV})
OBJ_SRT             = $(patsubst ${SORT_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRT})
OBJ_UTL             = $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

SRC_BONUS           = ${SRC_BONUS_DIR}/checker_bonus.c
GNL_BONUS           = ${GNL_BONUS_DIR}/get_next_line.c \

OBJ_SRC_BONUS       = $(patsubst ${SRC_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
                        ${SRC_BONUS})
OBJ_GNL_BONUS       = $(patsubst ${GNL_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
                        ${GNL_BONUS})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}
${NAME}: ftlibft ftprintf ${OBJ_SRC} ${OBJ_INT} \
                            ${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL}
	@echo "$(BLUE)📌​ Compiling root... $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_INT} \
                                	${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${MOVES_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${SORT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@echo "$(BLUE)📌​ Compiling Libft... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) all > /dev/null 2>&1
	@echo "$(GREEN) Libft created ✓$(DEF_COLOR)"

ftprintf:
	@echo "$(BLUE)📌​ Compiling Ftprintf... $(DEF_COLOR)"
	@cd ${PRINTFT_DIR} && $(MAKE) all > /dev/null 2>&1
	@echo "$(GREEN) Ftprintf created ✓$(DEF_COLOR)"

bonus: ${NAME_BONUS}
${NAME_BONUS}: ftlibft ftprintf ${OBJ_INT} ${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} \
                                    ${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS}
	@echo "$(BLUE)📌​ Compiling Bonus 🠲 $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} \
            ${OBJ_INT} ${OBJ_MOV} ${OBJ_SRT} ${OBJ_UTL} ${OBJ_SRC_BONUS} \
            ${OBJ_GNL_BONUS} ${LFLAGS} ${IFLAGS_BONUS}
	@echo "$(GREEN) $(NAME_BONUS) has been created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_BONUS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${GNL_BONUS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

clean:
	@echo "$(ORANGE)🗑️​  Removing object files...$(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) clean > /dev/null 2>&1
	@cd ${PRINTFT_DIR} && $(MAKE) clean > /dev/null 2>&1
	@$(RM) ${OBJ_DIR}/*.o
	@$(RM) ${SRC_BONUS_DIR}/*.o
	@echo "$(GREEN)Object files removed $(DEF_COLOR)"

fclean: clean
	@echo "$(ORANGE)🗑️​  Removing files *.a...$(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) fclean > /dev/null 2>&1
	@cd ${PRINTFT_DIR} && $(MAKE) fclean > /dev/null 2>&1
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "$(GREEN)Files *.a removed $(DEF_COLOR)"

re: fclean all

.PHONY: all ftlibft ftprintf clean fclean bonus re
