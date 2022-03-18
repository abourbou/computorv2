
SRC_MATH_FUNCTION	=	fct_sqrt.cpp fct_norm.cpp fct_trigo.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/math_function/, $(SRC_MATH_FUNCTION))