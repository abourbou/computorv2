
SRC_PARSING		=	parsing_task.cpp lexer.cpp computation.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING))