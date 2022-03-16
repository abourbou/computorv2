
SRC_PARSING		=	lexer.cpp computation.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING))