
SRC_EXTERNAL_FUNCTION	:=	math_utility.cpp string_function.cpp Polyn_equation.cpp

SRC			:=	$(SRC) \
				$(addprefix src/external_function/, $(SRC_EXTERNAL_FUNCTION))