
SRC_EXECUTION	=	exec_command.cpp exec_assign.cpp exec_line.cpp\
			exec_computation.cpp exec_get_var.cpp exec_polyn.cpp

SRC				:=	$(SRC) \
					$(addprefix src/execution/, $(SRC_EXECUTION))