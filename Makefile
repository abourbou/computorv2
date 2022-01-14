
# Compilation
NAME			=	computorv2
CC				=	clang++
FLAGS			=	-Wall -Werror -Wextra -Wshadow -std=c++11
HEADER			=	-I$(PATH_INC)

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]


# Path directories
PATH_INC		=	include
PATH_SRC		=	src
PATH_OBJ		=	obj

#Computorv1 integration
SRC_COMPUTORV1	=	computorv1_functions.cpp polyn_equation.cpp
INC_COMPUTORV1	=	computorv1_functions.hpp polyn_equation.hpp

# Source
SRC_EXTER_FCT	=	string_functions.cpp
SRC_PARSING		=	parsing_line.cpp
SRC_CLASS		=	Ivariable.cpp
SRC_EXECUTION	=	exec_command.cpp

SRC				=	$(addprefix $(PATH_SRC)/, main.cpp) \
					$(addprefix $(PATH_SRC)/computorv1/, $(SRC_COMPUTORV1)) \
					$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING)) \
					$(addprefix $(PATH_SRC)/class/, $(SRC_CLASS)) \
					$(addprefix $(PATH_SRC)/execution/, $(SRC_EXECUTION))

OBJ				=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRC:.cpp=.o)))

# Headers
INC_FILES		=	parsing.hpp
INC_CLASS		=	polyn_equation.hpp computorv1_functions.hpp parsing.hpp \
					Ivariable.hpp binary_tree.hpp

INC				=	$(addprefix $(PATH_INC)/, $(INC_FILES)) \
					$(addprefix $(PATH_INC)/, $(INC_COMPUTORV1)) \

# Rules
all				:	$(NAME)

$(NAME)			:	$(OBJ) $(INC)
				@$(CC) $(FLAGS) $(HEADER) $(SRC) -o $(NAME)
				@echo "$(_INFO) Creation of the executable"
				@echo "$(_SUCCESS) program created"

$(PATH_OBJ)/%.o	:	$(PATH_SRC)/%.cpp $(INC)
				$(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o	:	$(PATH_SRC)/*/%.cpp $(INC)
				@ $(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o	:	$(PATH_SRC)/*/*/%.cpp $(INC)
				@ $(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"
clean			:
				@rm -rf $(PATH_OBJ)/*.o
				@ echo "$(_INFO) Delete temporary files"

fclean			:	clean
				@rm -rf $(NAME)
				@ echo "$(_INFO) Delete executable"

re				:	fclean all

exec			:	all
					./$(NAME)