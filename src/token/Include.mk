
SRC_TOKEN	=	IToken.cpp Token_operator.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/token/, $(SRC_TOKEN))