
SRC_TEST	=	test_map_variable.cpp test_computation.cpp test_syntax.cpp\
				test_token.cpp test_value.cpp test_math_function.cpp

SRC			:=	$(SRC) \
				$(addprefix test/, $(SRC_TEST))