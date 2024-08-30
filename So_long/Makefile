# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME                = so_long
NAME_BONUS          = so_long_bonus

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
GNL_DIR             = ./gnl
ASSETS_DIR          = ./assets
OBJ_DIR             = ./obj
LIBFT_DIR           = ./libft
PRINTFT_DIR         = ./ft_printf
INCLUDES_DIR        = ./inc
MLX42_LIB           = ./MLX42/lib
MLX42_INCLUDE       = ./MLX42/include

# ══ Bonus Directories ═══════════════════════════════════════════════════════ #
#    -----------------      #

SRC_BONUS_DIR       = ./bonus
INCLUDES_BONUS_DIR  = ./bonus

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A             = ${LIBFT_DIR}/libft.a
PRINTFT_A           = ${PRINTFT_DIR}/libftprintf.a
LIBMLX42_A          = ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS              = -Wall -Werror -Wextra
IFLAGS              = -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS              = -L${LIBFT_DIR} -lft \
						-L${PRINTFT_DIR} -lftprintf \
						-L${MLX42_LIB} -lmlx42 -lglfw -ldl -lm -lpthread

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

IFLAGS_BONUS        = -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC                 = ${SRC_DIR}/
GNL					= ${GNL_DIR}/get_next_line.c \
						${GNL_DIR}/get_next_line_utils.c
ASS                 = ${ASSETS_DIR}/

OBJ_SRC             = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_GNL             = $(patsubst ${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, ${GNL})
OBJ_ASS             = $(patsubst ${ASSETS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ASS})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

SRC_BONUS           = ${SRC_BONUS_DIR}/
OBJ_SRC_BONUS       = $(patsubst ${SRC_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, \
                        ${SRC_BONUS})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}
${NAME}: ftlibft ftprintf ${OBJ_SRC} ${OBJ_GNL} \
                            ${OBJ_ASS}
	@echo "$(BLUE)📌​ Compiling root... $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_GNL} \
                                	${OBJ_ASS} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@
${OBJ_DIR}/%.o: ${ASSETS_DIR}/%.c
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
${NAME_BONUS}: ftlibft ftprintf ${OBJ_ASS} ${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS}
	
	@echo "$(BLUE)📌​ Compiling Bonus 🠲 $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} \
            ${OBJ_ASS} ${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS} \
			${LFLAGS} ${IFLAGS_BONUS}
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
