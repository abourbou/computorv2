
# Compilation
NAME			=	computorv2
CC			=	clang++
FLAGS			=	-Wall -Werror -Wextra -Wshadow -std=c++11 -g3 -fsanitize=address
HEADER			=	-I$(PATH_INC) -I$(PATH_INC_VAR)

# Color Code and template code
_YELLOW			=	\033[38;5;184m
_GREEN			=	\033[38;5;46m
_RESET			=	\033[0m
_INFO			=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS		=	[$(_GREEN)SUCCESS$(_RESET)]


# Path directories
PATH_INC		=	include
PATH_SRC		=	src
PATH_OBJ		=	obj

# Source
SRC_EXTER_FCT		=	string_functions.cpp math_utility.cpp
SRC_PARSING		=	parsing_line.cpp
SRC_VARIABLE		=	Ivalue.cpp Ivariable.cpp rational.cpp map_variable.cpp \
				cfunction.cpp matrix.cpp complex.cpp
SRC_EXECUTION		=	exec_command.cpp exec_assign.cpp

SRC_EXTERNAL_FUNCTION	=	math_utility.cpp string_function.cpp polyn_equation.cpp

SRC			=	$(addprefix $(PATH_SRC)/, main.cpp) \
				$(addprefix $(PATH_SRC)/computorv1/, $(SRC_COMPUTORV1)) \
				$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING)) \
				$(addprefix $(PATH_SRC)/variable/, $(SRC_VARIABLE)) \
				$(addprefix $(PATH_SRC)/execution/, $(SRC_EXECUTION)) \
				$(addprefix $(PATH_SRC)/external_function/, $(SRC_EXTERNAL_FUNCTION))

OBJ			=	$(addprefix $(PATH_OBJ)/, $(notdir $(SRC:.cpp=.o)))

# Headers
PATH_INC_VAR		=	include/variable

INC_FILES		=	parsing.hpp math_utility.hpp string_function.hpp \
				binary_tree.hpp map_variable.hpp

INC_VAR			=	polyn_equation.hpp Ivalue.hpp Ivariable.hpp \
				rational.hpp  cfunction.hpp complex.hpp matrix.hpp

INC			=	$(addprefix $(PATH_INC)/, $(INC_FILES)) \
				$(addprefix $(PATH_INC_VAR)/, $(INC_VAR))

# Rules
all			:	$(NAME)

$(NAME)			:	$(OBJ) $(INC)
				@$(CC) $(FLAGS) $(HEADER) $(SRC) -o $(NAME)
				@echo "$(_INFO) Creation of the executable"
				@echo "$(_SUCCESS) program created"

$(PATH_OBJ)/%.o		:	$(PATH_SRC)/%.cpp $(INC)
				@$(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o		:	$(PATH_SRC)/*/%.cpp $(INC)
				@ $(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"

$(PATH_OBJ)/%.o		:	$(PATH_SRC)/*/*/%.cpp $(INC)
				@ $(CC) $(FLAGS) $(HEADER) -c $< -o $@
				@echo "$(_INFO) Compilation of $*"
clean			:
				@rm -rf $(PATH_OBJ)/*.o
				@ echo "$(_INFO) Delete temporary files"

fclean			:	clean
				@rm -rf $(NAME)
				@ echo "$(_INFO) Delete executable"

re			:	fclean all

exec			:	all
					./$(NAME)

test			:
					@echo $(INC)