
SRC_TEST	=	test_map_variable.cpp test_computation.cpp

SRC			:=	$(SRC) \
				$(addprefix test/, $(SRC_TEST))