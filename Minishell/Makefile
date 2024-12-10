# ══ Names ═══════════════════════════════════════════════════════════════════ #

NAME 				= minishell

# ══ Colors ══════════════════════════════════════════════════════════════════ #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0m
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
CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C
MKD					= mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #

ENV_DIR					= ./env
MINISHELL_DIR			= ./init_mini
LIBRARIES				= ./libs
OBJ_DIR					= ./obj
LIBFT_DIR				= libft
PRINTFT_DIR				= printf
INCLUDES_DIR			= ./includes
MAIN_DIR				= ./main
PARSER_DIR				= ./parsing
TOKER_DIR				= ./toker
EXE_DIR					= ./built_in
EXT_DIR					= ./external_cmd
FREE_DIR				= ./free

# ══ Library Archives ════════════════════════════════════════════════════════ #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #

CFLAGS 				= -Wall -Werror -Wextra
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
					  -L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
					  -lreadline

# ══ Sources ═════════════════════════════════════════════════════════════════ #

ENV 				= ${ENV_DIR}/init_env.c \
						${ENV_DIR}/utils_env.c

TOKER				= ${TOKER_DIR}/ft_get_tokens.c \
						${TOKER_DIR}/ft_utils_1.c\
						${TOKER_DIR}/ft_utils_2.c\
						${TOKER_DIR}/ft_utils_3.c \
						${TOKER_DIR}/ft_utils_4.c \
						${TOKER_DIR}/ft_utils_5.c \
						${TOKER_DIR}/ft_utils_6.c \
						${TOKER_DIR}/ft_utils_7.c

MINISHELL			= ${MINISHELL_DIR}/init_minishell.c

MAIN				= ${MAIN_DIR}/main.c \
						${MAIN_DIR}/signals.c

PARSER				= ${PARSER_DIR}/ast.c \
						${PARSER_DIR}/ft_parsing.c \
						${PARSER_DIR}/ft_utils_parsing.c

EXE 				= ${EXE_DIR}/ft_built_in.c \
						${EXE_DIR}/ft_utils_exe.c \
						${EXE_DIR}/ft_err_msg.c \
						${EXE_DIR}/ft_exit.c \
						${EXE_DIR}/ft_cd.c \
						${EXE_DIR}/ft_clear.c \
						${EXE_DIR}/ft_pwd.c \
						${EXE_DIR}/ft_env.c \
						${EXE_DIR}/ft_echo.c \
						${EXE_DIR}/ft_unset.c \
						${EXE_DIR}/ft_export.c \
						${EXE_DIR}/ft_utils_exit.c

EXT 				= ${EXT_DIR}/ft_find_exe.c \
						${EXT_DIR}/ft_exec.c \
						${EXT_DIR}/ft_redir_exe.c \
						${EXT_DIR}/ft_handle_fds.c \
						${EXT_DIR}/ft_pipe.c \
						${EXT_DIR}/ft_utils_exec.c \
						${EXT_DIR}/ft_utils_redir.c \
						${EXT_DIR}/ft_heredoc.c

FREE				= ${FREE_DIR}/ft_free.c \
						${FREE_DIR}/ft_free_mini.c \
												

OBJ_ENV				= $(patsubst ${ENV_DIR}/%.c, ${OBJ_DIR}/%.o, ${ENV})
OBJ_MINISHELL		= $(patsubst ${MINISHELL_DIR}/%.c, ${OBJ_DIR}/%.o, ${MINISHELL})
OBJ_MAIN			= $(patsubst ${MAIN_DIR}/%.c, ${OBJ_DIR}/%.o, ${MAIN})
OBJ_PARSER			= $(patsubst ${PARSER_DIR}/%.c, ${OBJ_DIR}/%.o, ${PARSER})
OBJ_TOKER			= $(patsubst ${TOKER_DIR}/%.c, ${OBJ_DIR}/%.o, ${TOKER})
OBJ_EXE				= $(patsubst ${EXE_DIR}/%.c, ${OBJ_DIR}/%.o, ${EXE})
OBJ_EXT				= $(patsubst ${EXT_DIR}/%.c, ${OBJ_DIR}/%.o, ${EXT})
OBJ_FREE			= $(patsubst ${FREE_DIR}/%.c, ${OBJ_DIR}/%.o, ${FREE})
# ═══ Rules ══════════════════════════════════════════════════════════════════ #

all: ${NAME}

${NAME}: ftlibft ftprintf ${OBJ_ENV} \
							${OBJ_MINISHELL} \
							${OBJ_MAIN} ${OBJ_TOKER} ${OBJ_PARSER} ${OBJ_EXE} ${OBJ_EXT} ${OBJ_FREE}

	@echo "$(YELLOW)Compiling ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJ_ENV} ${OBJ_MINISHELL} \
									${OBJ_MAIN} ${OBJ_TOKER} ${OBJ_PARSER} ${OBJ_EXE} ${OBJ_FREE} ${OBJ_EXT} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${MINISHELL_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ENV_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${TOKER_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${MAIN_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${PARSER_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${EXE_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${EXT_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${FREE_DIR}/%.c
	@${MKD} $(dir $@)
	@${CC} ${CFLAGS} -c $< -o $@

ftlibft:
	echo Building Libft from: ${LIBRARIES}/${LIBFT_DIR}
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} all

ftprintf:
	echo Building ft_printf from: ${LIBRARIES}/${PRINTFT_DIR}
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} all

clean:
	@echo "$(YELLOW)Removing object files!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} clean
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} clean
	@find ${OBJ_DIR} -name "*.o" -type f -delete
	@echo "$(RED)Object files removed! $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries!$(DEF_COLOR)"
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${LIBFT_DIR} fclean
	@$(MAKE) --no-print-directory -C ${LIBRARIES}/${PRINTFT_DIR} fclean
	@${RM} ${NAME}
	@echo "$(RED)Binaries removed! $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf clean fclean re
