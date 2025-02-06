# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= libft.a

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

SRC_DIR				= ./libft
OBJ_DIR 			= ../../obj
INCLUDES 			= ../../includes/libft.h

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRCS 				= 	ft_isalpha.c \
							ft_isdigit.c \
							ft_isalnum.c \
							ft_isascii.c \
							ft_isprint.c \
							ft_strlen.c \
							ft_memset.c \
							ft_bzero.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_strlcpy.c \
							ft_strlcat.c \
							ft_toupper.c \
							ft_tolower.c \
							ft_strchr.c \
							ft_strrchr.c \
							ft_strncmp.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_strnstr.c \
							ft_atoi.c \
							ft_calloc.c \
							ft_strdup.c \
							ft_substr.c \
							ft_strjoin.c \
							ft_strtrim.c \
							ft_split.c \
							ft_itoa.c \
							ft_strmapi.c \
							ft_striteri.c \
							ft_putchar_fd.c \
							ft_putstr_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c \
							ft_lstnew.c \
							ft_lstadd_front.c \
							ft_lstsize.c \
							ft_lstlast.c \
							ft_lstadd_back.c \
							ft_lstdelone.c \
							ft_lstclear.c \
							ft_lstiter.c \
							ft_lstmap.c \
							get_next_line.c \
							get_next_line_utils.c

OBJS 				= ${SRCS:%.c=${OBJ_DIR}/%.o}

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all:	${NAME} 

${NAME} : ${OBJS} ${INCLUDES}
	@echo "$(YELLOW)Compiling libft ...$(DEF_COLOR)"
	@${AR} ${NAME} ${OBJS}
	@echo "$(GREEN) $(NAME) created ✓$(DEF_COLOR)"
	@ranlib $(NAME)
	@echo "$(GREEN) $(NAME) indexed ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: %.c ${INCLUDES}
	@${MKD} ${OBJ_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)Remove object files libft ...$(DEF_COLOR)"
	@${RM} ${OBJ_DIR}/*.o
	@echo "$(RED)OBJ_SRCS deleted $(DEF_COLOR)"	

fclean:	clean 
	@echo "$(YELLOW)Remove lib libft ...$(DEF_COLOR)"
	@${RM} ${NAME}
	@echo "$(RED)$(NAME) deleted$(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean re
