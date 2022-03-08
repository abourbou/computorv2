
SRC_VARIABLE		:=	IValue.cpp IVariable.cpp Rational.cpp \
				Comput_fct.cpp Explic_fct.cpp IFunction.cpp \
				Matrix.cpp Complex.cpp Map_variable.cpp

SRC := $(SRC) \
	$(addprefix src/variable/, $(SRC_VARIABLE))