# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #
NAME 				= account

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

CXX					= c++
RM 					= rm -f
MKD					= mkdir -p

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

SRC_DIR				= ./src
OBJ_DIR				= ./obj

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CXXFLAGS 			= -Wall -Werror -Wextra -std=c++98

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC 				= ${SRC_DIR}/Account.cpp \
						${SRC_DIR}/tests.cpp 

OBJ_SRC				= $(patsubst ${SRC_DIR}/%.cpp, ${OBJ_DIR}/%.o, ${SRC})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ${OBJ_SRC} ${OBJ_MAIN}
									 
	@echo "$(BLUE)Compiling $(NAME) ...$(DEF_COLOR)"
	@${CXX} ${CXXFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_MAIN}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp
	@${MKD} $(dir $@)
	@$(CXX) ${CXXFLAGS} -c $< -o $@

clean:
	@echo "$(RED)Removing object files ...$(DEF_COLOR)"
	@$(RM) ${OBJ_DIR}/*.o
	@echo "$(GREEN)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(RED)Removing binaries ...$(DEF_COLOR)"
	@${RM} ${NAME} ${NAME_BONUS}
	@echo "$(GREEN)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all clean fclean bonus re