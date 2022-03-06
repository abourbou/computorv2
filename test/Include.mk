
SRC_TEST	=	test_map_variable.cpp test_computation.cpp test_input.cpp

SRC			:=	$(SRC) \
				$(addprefix test/, $(SRC_TEST))