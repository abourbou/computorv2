
# Compilation
NAME			=	computorv2
CC				=	clang++
FLAGS			=	-Wall -Werror -Wextra -Wshadow -std=c++11
HEADER			=	-I$(PATH_INC) -I$(PATH_INC_VAR) -I$(PATH_TEST)

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
PATH_TEST		=	test

# Source

SRC_TEST		=	$(wildcard $(PATH_TEST)/*.cpp)

SRC			=	$(addprefix $(PATH_SRC)/, main.cpp)

OBJ			=	$(addprefix $(PATH_OBJ)/, $(SRC:.cpp=.o))

#include
include src/computation/Include.mk
include src/execution/Include.mk
include src/external_function/Include.mk
include src/parsing/Include.mk
include src/variable/Include.mk
include test/Include.mk

# Headers
PATH_INC_VAR		=	include/variable

INC_FILES		=	parsing.hpp math_utility.hpp string_function.hpp \
				binary_tree.hpp computation.hpp execution.hpp

INC_VAR			=	Polyn_equation.hpp IValue.hpp IVariable.hpp \
				Rational.hpp  Function.hpp Complex.hpp Matrix.hpp \
				Map_variable.hpp

INC_TEST		=	test.hpp

INC			=	$(addprefix $(PATH_INC)/, $(INC_FILES)) \
				$(addprefix $(PATH_INC_VAR)/, $(INC_VAR)) \
				$(addprefix $(PATH_TEST)/, $(INC_TEST))

# Rules
all			:	$(NAME)

$(NAME)			:	$(OBJ) $(INC)
				@$(CC) $(FLAGS) $(HEADER) $(OBJ) -o $(NAME)
				@echo "$(_INFO) Creation of the executable"
				@echo "$(_SUCCESS) program created"

change_flag		:
				$(eval FLAGS := $(FLAGS) -g3 -fsanitize=address)

debug			:	change_flag all
				@echo "$(_SUCCESS) program with debug mode"

$(PATH_OBJ)/%.o		: 	%.cpp    $(INC)
				@mkdir -p $(dir $@)
				@echo "$(_INFO) Compilation of $*"
				@$(CC) $(FLAGS) $(HEADER) -c -o $@ $<

# $(PATH_OBJ)/%.o		:	$(PATH_TEST)/%.cpp $(INC)
# 				$(CC) $(FLAGS) $(HEADER) -c $< -o $@
# 				@echo "$(_INFO) Compilation of $*"
clean			:
				@ find $(PATH_OBJ) -name '*.o' -delete
				@ echo "$(_INFO) Delete temporary files"

fclean			:	clean
				@rm -rf $(NAME)
				@ echo "$(_INFO) Delete executable"

re			:	fclean all

exec			:	all
				./$(NAME)

test			:
				@echo $(SRC)