# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= minishell

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
MK 					= make -C
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

ENV_DIR					= ./env
#TOKENIZER_DIR			= ./tokenizer
MINISHELL_DIR			= ./init_mini
LIBRARIES				= ./libs
OBJ_DIR					= ./obj
LIBFT_DIR				= libft
PRINTFT_DIR				= printf
INCLUDES_DIR			= ./includes
MAIN_DIR				= ./main
#PARSER_DIR				= ./parsing
TOKER_DIR			= ./toker



# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #
CFLAGS 				= -Wall -Werror -Wextra
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
					  -L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
					  -lreadline


# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

ENV 				= ${ENV_DIR}/init_env.c

#TOKENIZER			= ${TOKENIZER_DIR}/lexer.c \
						#${TOKENIZER_DIR}/utils_lexer.c \
						${TOKENIZER_DIR}/utils_lexer2.c \
						${TOKENIZER_DIR}/utils_lexer3.c 

TOKER				= ${TOKER_DIR}/get_tokens.c \
						${TOKER_DIR}/tools.c

MINISHELL			= ${MINISHELL_DIR}/init_minishell.c

MAIN				= ${MAIN_DIR}/main.c \
						${MAIN_DIR}/signals.c

#PARSER			= ${PARSER_DIR}/ast.c \
						${PARSER_DIR}/ft_parsing.c

OBJ_ENV				= $(patsubst ${ENV_DIR}/%.c, ${OBJ_DIR}/%.o, ${ENV})
#OBJ_TOKENIZER		= $(patsubst ${TOKENIZER_DIR}/%.c, ${OBJ_DIR}/%.o, ${TOKENIZER})
OBJ_MINISHELL		= $(patsubst ${MINISHELL_DIR}/%.c, ${OBJ_DIR}/%.o, ${MINISHELL})
OBJ_MAIN			= $(patsubst ${MAIN_DIR}/%.c, ${OBJ_DIR}/%.o, ${MAIN})
#OBJ_PARSER			= $(patsubst ${PARSER_DIR}/%.c, ${OBJ_DIR}/%.o, ${PARSER})
OBJ_TOKER			= $(patsubst ${TOKER_DIR}/%.c, ${OBJ_DIR}/%.o, ${TOKER})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ${OBJ_ENV} \
							${OBJ_MINISHELL} \
							${OBJ_MAIN}  ${OBJ_TOKER}

	@echo "$(YELLOW)Compiling ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_ENV} ${OBJ_MINISHELL} \
									${OBJ_MAIN} ${OBJ_TOKER} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${MINISHELL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ENV_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

#${OBJ_DIR}/%.o: ${TOKENIZER_DIR}/%.c
#	@${MKD} $(dir $@)
#	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${TOKER_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${MAIN_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

#${OBJ_DIR}/%.o: ${PARSER_DIR}/%.c
#	@${MKD} $(dir $@)
#	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@


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

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re
