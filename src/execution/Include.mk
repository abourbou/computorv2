
SRC_EXECUTION	=	exec_command.cpp exec_assign.cpp main_exec.cpp

SRC				:=	$(SRC) \
					$(addprefix src/execution/, $(SRC_EXECUTION))