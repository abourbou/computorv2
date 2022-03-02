
SRC_TEST	=	test_map_variable.cpp

SRC			:=	$(SRC) \
				$(addprefix test/, $(SRC_TEST))