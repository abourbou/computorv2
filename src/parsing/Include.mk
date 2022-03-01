
SRC_PARSING		=	parsing_line.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/parsing/, $(SRC_PARSING))