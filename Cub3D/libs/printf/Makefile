# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= libftprintf.a

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 			=	\033[2K
ITALIC 				=	\033[3m
BOLD 				=	\033[1m
DEF_COLOR 			= 	\033[0;39m
GRAY 				= 	\033[0;90m
RED 				= 	\033[0;91m
GREEN 				= 	\033[0;92m
YELLOW 				= 	\033[0;93m
BLUE 				= 	\033[0;94m
MAGENTA 			= 	\033[0;95m
CYAN 				= 	\033[0;96m
WHITE 				= 	\033[0;97m
BLACK 				=	\033[0;99m
ORANGE 				=	\033[38;5;209m
BROWN 				=	\033[38;2;184;143;29m
DARK_GRAY 			=	\033[38;5;234m
MID_GRAY 			=	\033[38;5;245m
DARK_GREEN 			=	\033[38;2;75;179;82m
DARK_YELLOW 		=	\033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MKD					= mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

SRC_DIR				= ./printf
OBJ_DIR 			= ../../obj
INCLUDES 			= ../../includes/ft_printf.h

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRCS 				= 	ft_printf.c \
							ft_putchar.c \
							ft_puthex.c \
							ft_putnbr_uns.c \
							ft_putnbr.c \
							ft_putptr.c \
							ft_putstr.c 

OBJS 				= ${SRCS:%.c=${OBJ_DIR}/%.o}

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all:	${NAME} 

${NAME} : ${OBJS} ${INCLUDES}
	@echo "$(YELLOW)Compiling printf ...$(DEF_COLOR)"
	@${AR} ${NAME} ${OBJS}
	@echo "$(GREEN) $(NAME) created ✓$(DEF_COLOR)"
	@ranlib $(NAME)
	@echo "$(GREEN) $(NAME) indexed ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: %.c ${INCLUDES}
	@${MKD} ${OBJ_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Remove object files printf ...$(DEF_COLOR)"
	@${RM} ${OBJ_DIR}/*.o
	@echo "$(RED)OBJS deleted $(DEF_COLOR)"	

fclean:	clean 
	@echo "$(YELLOW)Remove lib printf ...$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean re