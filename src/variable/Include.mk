
SRC_VARIABLE		:=	IValue.cpp IVariable.cpp Rational.cpp \
				Computable_function.cpp Matrix.cpp Complex.cpp \
				Map_variable.cpp
SRC := $(SRC) \
	$(addprefix src/variable/, $(SRC_VARIABLE))