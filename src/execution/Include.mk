
SRC_EXECUTION	=	exec_command.cpp exec_assign.cpp main_exec.cpp computation.cpp

SRC				:=	$(SRC) \
					$(addprefix src/execution/, $(SRC_EXECUTION))