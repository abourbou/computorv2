
SRC_TOKEN	=	IToken.cpp Token_operator.cpp Token_variable.cpp Token_function.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/token/, $(SRC_TOKEN))