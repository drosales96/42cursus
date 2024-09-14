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
ETS_DIR             = ./ets
OBJ_DIR             = ./obj
LIBFT_DIR           = ./libft
PRINTFT_DIR         = ./ft_printf
INCLUDES_DIR        = ./inc
MLX42_LIB           = ./MLX42/lib
MLX42_INCLUDE       = ./MLX42/include

# ══ Bonus Directories ═══════════════════════════════════════════════════════ #
#    -----------------      #

SRC_BONUS_DIR       = ./src_bonus
INCLUDES_BONUS_DIR  = ./inc

# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A             = ${LIBFT_DIR}/libft.a
PRINTFT_A           = ${PRINTFT_DIR}/libftprintf.a
LIBMLX42_A          = ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS              = -Wall -Werror -Wextra -g
IFLAGS              = -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS              = -L${LIBFT_DIR} -lft \
						-L${PRINTFT_DIR} -lftprintf \
						-L${MLX42_LIB} -lmlx42 -lglfw -ldl -lm -lpthread

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

IFLAGS_BONUS        = -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC                 = ${SRC_DIR}/ft_flood_fill.c \
						${SRC_DIR}/ft_utils.c \
						${SRC_DIR}/ft_print_character.c \
						${SRC_DIR}/ft_free.c \
						${SRC_DIR}/ft_mapping.c \
						${SRC_DIR}/ft_materials.c \
						${SRC_DIR}/ft_mlx_init.c \
						${SRC_DIR}/ft_moves.c \
						${SRC_DIR}/ft_matrix.c \
						${SRC_DIR}/ft_utils2.c \
						${SRC_DIR}/ft_rendering.c \
						${SRC_DIR}/so_long.c
GNL					= ${GNL_DIR}/get_next_line.c \

OBJ_SRC             = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_GNL             = $(patsubst ${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, ${GNL})

# ══ Sources Bonus ═══════════════════════════════════════════════════════════ #
#    -------------                                                             #

SRC_BONUS                 = ${SRC_BONUS_DIR}/ft_cells_management_bonus.c \
						${SRC_BONUS_DIR}/ft_utils_bonus.c \
						${SRC_BONUS_DIR}/ft_print_character_bonus.c \
						${SRC_BONUS_DIR}/ft_free_bonus.c \
						${SRC_BONUS_DIR}/ft_mapping_bonus.c \
						${SRC_BONUS_DIR}/ft_materials_bonus.c \
						${SRC_BONUS_DIR}/ft_mlx_init_bonus.c \
						${SRC_BONUS_DIR}/ft_moves_bonus.c \
						${SRC_BONUS_DIR}/ft_matrix_bonus.c \
						${SRC_BONUS_DIR}/ft_utils2_bonus.c \
						${SRC_BONUS_DIR}/ft_rendering_bonus.c \
						${SRC_BONUS_DIR}/so_long_bonus.c
OBJ_SRC_BONUS       = $(patsubst ${SRC_BONUS_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC_BONUS})
OBJ_GNL_BONUS       = $(patsubst ${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, ${GNL})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ${OBJ_SRC} ${OBJ_GNL}
	@echo "$(BLUE)📌​ Compiling root... $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_GNL} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@echo "$(BLUE)📌​ Compiling Libft... $(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) -s all > /dev/null 2>&1
	@echo "$(GREEN) Libft created ✓$(DEF_COLOR)"

ftprintf:
	@echo "$(BLUE)📌​ Compiling Ftprintf... $(DEF_COLOR)"
	@cd ${PRINTFT_DIR} && $(MAKE) -s all > /dev/null 2>&1
	@echo "$(GREEN) Ftprintf created ✓$(DEF_COLOR)"

bonus: ${NAME_BONUS}

${NAME_BONUS}: ftlibft ftprintf ${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS}
	@echo "$(BLUE)📌​ Compiling Bonus 🠲 $(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -o ${NAME_BONUS} \
        	${OBJ_SRC_BONUS} ${OBJ_GNL_BONUS} ${LFLAGS}
	@echo "$(GREEN) $(NAME_BONUS) has been created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_BONUS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} ${IFLAGS_BONUS} -c $< -o $@

clean:
	@echo "$(ORANGE)🗑️​  Removing object files...$(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) -s clean > /dev/null 2>&1
	@cd ${PRINTFT_DIR} && $(MAKE) -s clean > /dev/null 2>&1
	@$(RM) -r ${OBJ_DIR}
	@echo "$(GREEN)Object files removed ✓$(DEF_COLOR)"

fclean: clean
	@echo "$(ORANGE)🗑️​  Removing files *.a and executables...$(DEF_COLOR)"
	@cd ${LIBFT_DIR} && $(MAKE) -s fclean > /dev/null 2>&1
	@cd ${PRINTFT_DIR} && $(MAKE) -s fclean > /dev/null 2>&1
	@${RM} ${NAME} ${NAME_BONUS}
	@${RM} ${LIBFT_A} ${PRINTFT_A}
	@echo "$(GREEN)Files *.a and executables removed ✓$(DEF_COLOR)"

re: fclean all

.PHONY: all ftlibft ftprintf clean fclean bonus re
