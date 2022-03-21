
SRC_MATH_FUNCTION	=	fct_sqrt.cpp fct_norm.cpp fct_abs.cpp\
						fct_sin.cpp fct_cos.cpp fct_tan.cpp \
						fct_exp.cpp fct_ln.cpp fct_log.cpp

SRC := $(SRC) \
	$(addprefix $(PATH_SRC)/math_function/, $(SRC_MATH_FUNCTION))