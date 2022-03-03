
SRC_COMPUTATION = computation.cpp

SRC		:=	$(SRC) \
			$(addprefix src/computation/, $(SRC_COMPUTATION))