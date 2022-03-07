
SRC_PARSING		=	parsing_line.cpp lexer.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING))