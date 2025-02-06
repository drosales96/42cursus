# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= cub3D

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0;39m
GRAY 				= \033[0;90m
RED 				= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
WHITE 				= \033[0;97m
BLACK 				= \033[0;99m
ORANGE 				= \033[38;5;209m
BROWN 				= \033[38;2;184;143;29m
DARK_GRAY 			= \033[38;5;234m
MID_GRAY 			= \033[38;5;245m
DARK_GREEN 			= \033[38;2;75;179;82m
DARK_YELLOW 		= \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

ANALYZ_DIR			= ./analyzer
CALCUL_DIR			= ./calculations
CONTROL_DIR			= ./control
DATAMAPS_DIR		= ./data_maps
ERRORS_DIR			= ./errors
IMAGES_DIR			= ./img
INIT_DIR			= ./init
LIBRARIES			= ./libs
OBJ_DIR				= ./obj
RND_DIR				= ./rendering
SRC_DIR				= ./src
UTILS_DIR			= ./utils
VERIFY_DIR			= ./verify
LIBFT_DIR			= libft
PRINTFT_DIR			= printf
EXAMFT_DIR			= examft
INCLUDES_DIR		= ./includes
MLX42_LIB           = ./MLX42/lib
MLX42_INCLUDE       = ./MLX42/include

# ══ Directories Bonus ═══════════════════════════════════════════════════════ #
#    -----------                                                               #


# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
EXAMFT_A			= ${LIBRARIES}/${EXAMFT_DIR}/libexamft.a
LIBMLX42_A          = ${MLX42_LIB}/libmlx42.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

# CFLAGS 				= -Wall -Werror -Wextra
CFLAGS 				= -Wall -Werror -Wextra -fsanitize=address -g
IFLAGS				= -I${INCLUDES_DIR} -I${MLX42_INCLUDE}
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
						-L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
						-L${LIBRARIES}/${EXAMFT_DIR} -lexamft -lreadline \
						-L${MLX42_LIB} -lmlx42 -lglfw -ldl -lm -lpthread
				

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

# IFLAGS_BONUS		= -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

ANZ					= ${ANALYZ_DIR}/ft_analyzer.c\
						${ANALYZ_DIR}/ft_analyzer_utils.c

CAL					= ${CALCUL_DIR}/ft_angle.c \
						${CALCUL_DIR}/ft_hypo.c \
						${CALCUL_DIR}/ft_moves.c \
						${CALCUL_DIR}/ft_ray_init.c \
						${CALCUL_DIR}/ft_raycasting.c \
						${CALCUL_DIR}/ft_rotation.c \
						${CALCUL_DIR}/ft_vert.c
						
CTRL				= ${CONTROL_DIR}/ft_control_args.c \
						${CONTROL_DIR}/ft_ext_valid.c

DMP					= ${DATAMAPS_DIR}/ft_textures.c \
						${DATAMAPS_DIR}/ft_colors.c \
						${DATAMAPS_DIR}/ft_colors_2.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c \
						${ERRORS_DIR}/ft_manage_err_2.c

INT					= ${INIT_DIR}/ft_game_init.c \
						${INIT_DIR}/ft_init_struct.c\
						${INIT_DIR}/ft_init_tools.c

RND					= ${RND_DIR}/ft_rendering.c

SRC 				= ${SRC_DIR}/cub3D.c

UTL					= ${UTILS_DIR}/ft_alloc.c \
						${UTILS_DIR}/ft_banner.c \
						${UTILS_DIR}/ft_count.c \
						${UTILS_DIR}/ft_erase.c \
						${UTILS_DIR}/ft_new_strjoin.c \
						${UTILS_DIR}/ft_splits.c

VRF					= ${VERIFY_DIR}/ft_verify_enclosure.c \
						${VERIFY_DIR}/ft_verify_content.c \
						${VERIFY_DIR}/ft_verify_cube.c \
						${VERIFY_DIR}/ft_verify_images.c \
						${VERIFY_DIR}/ft_verify_lines.c \
						${VERIFY_DIR}/ft_verify_maps.c \
						${VERIFY_DIR}/ft_verify_players.c \
						${VERIFY_DIR}/ft_verify_spaces.c

OBJ_ANZ				= $(patsubst ${ANALYZ_DIR}/%.c, ${OBJ_DIR}/%.o, ${ANZ})
OBJ_CAL				= $(patsubst ${CALCUL_DIR}/%.c, ${OBJ_DIR}/%.o, ${CAL})
OBJ_CTRL			= $(patsubst ${CONTROL_DIR}/%.c, ${OBJ_DIR}/%.o, ${CTRL})
OBJ_DMP				= $(patsubst ${DATAMAPS_DIR}/%.c, ${OBJ_DIR}/%.o, ${DMP})
OBJ_ERR				= $(patsubst ${ERRORS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERR})
OBJ_INT				= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_RND				= $(patsubst ${RND_DIR}/%.c, ${OBJ_DIR}/%.o, ${RND})
OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_UTL				= $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})
OBJ_VRF				= $(patsubst ${VERIFY_DIR}/%.c, ${OBJ_DIR}/%.o, ${VRF})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ftexamft  ${OBJ_ANZ} ${OBJ_CAL} ${OBJ_CTRL} \
										${OBJ_DMP} ${OBJ_ERR} ${OBJ_INT} \
										${OBJ_RND} ${OBJ_SRC} ${OBJ_UTL} \
										${OBJ_VRF}
									 
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_ANZ} ${OBJ_CAL} ${OBJ_CTRL} \
										${OBJ_DMP} ${OBJ_ERR} ${OBJ_INT} \
										${OBJ_RND} ${OBJ_SRC} ${OBJ_UTL} \
										${OBJ_VRF} ${LFLAGS}

	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${ANALYZ_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CALCUL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CONTROL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${DATAMAPS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERRORS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${RND_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${VERIFY_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@


ftlibft:
	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} all

ftexamft:
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} all

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} clean
	@$(RM) ${OBJ_DIR}/*.o

	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} fclean
	@${RM} ${NAME} ${NAME_BONUS}

	@echo "$(RED)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re
