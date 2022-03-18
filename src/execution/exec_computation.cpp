
#include "string_function.hpp"
#include "parsing.hpp"

/**
 * @brief execute a computation
 *
 * @param line
 */
void	exec_computation(std::string line)
{
	static Map_variable	&map = Singleton::GetInstance()->get_map_variable();

	line = line.substr(0, line.size() - 2);
	std::list<token_ptr>	list_tok;
	lexer_computation(line, list_tok);
	std::shared_ptr<IValue> result(computation(list_tok));
	result->display();
	map.add_var("Ans", result.get());
}