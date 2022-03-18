
SRC_MATH_FUNCTION	=	fct_sqrt.cpp fct_norm.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/math_function/, $(SRC_MATH_FUNCTION))