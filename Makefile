
# Compilation
NAME			=	computorv2
CC				=	clang++
FLAGS			=	-Wall -Werror -Wextra -Wshadow -std=c++17
HEADER			=	-I$(PATH_INC) -I$(PATH_INC_VAR) -I$(PATH_INC_TOKEN) -I$(PATH_TEST)

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

SRC			=	$(addprefix $(PATH_SRC)/, main.cpp singleton.cpp)

OBJ			=	$(addprefix $(PATH_OBJ)/, $(SRC:.cpp=.o))

#include
include src/variable/Include.mk
include src/execution/Include.mk
include src/external_function/Include.mk
include src/parsing/Include.mk
include src/token/Include.mk
include test/Include.mk

# Headers
PATH_INC_VAR		=	include/variable

PATH_INC_TOKEN		=	include/token

INC_FILES		=	parsing.hpp math_utility.hpp string_function.hpp \
				execution.hpp singleton.hpp

INC_VAR			=	Polyn_equation.hpp IValue.hpp IVariable.hpp \
				Rational.hpp  Comput_fct.hpp Explic_fct.hpp \
				IFunction.hpp Complex.hpp Matrix.hpp Map_variable.hpp

INC_TOKEN		=	IToken.hpp Token_function.hpp Token_operator.hpp \
				Token_parenth.hpp Token_variable.hpp Token_value.hpp

INC_TEST		=	test.hpp

INC			=	$(addprefix $(PATH_INC)/, $(INC_FILES)) \
				$(addprefix $(PATH_INC_VAR)/, $(INC_VAR)) \
				$(addprefix $(PATH_INC_TOKEN)/, $(INC_TOKEN)) \
				$(addprefix $(PATH_TEST)/, $(INC_TEST))

# Rules
all			:	$(NAME)

$(NAME)			:	$(OBJ) $(INC)
				@$(CC) $(FLAGS) $(HEADER) $(OBJ) -o $(NAME)
				@echo "$(_INFO) Creation of the executable"
				@echo "$(_SUCCESS) program created"

change_flag		:
				$(eval FLAGS := $(FLAGS) -g3 -fsanitize=address)

debug			: change_flag all
				@echo "$(_SUCCESS) program with debug mode"

$(PATH_OBJ)/%.o		: 	%.cpp    $(INC)
				@mkdir -p $(dir $@)
				@echo "$(_INFO) Compilation of $*"
				@$(CC) $(FLAGS) $(HEADER) -c -o $@ $<

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