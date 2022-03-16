
#include "string_function.hpp"
#include "parsing.hpp"

/**
 * @brief execute a computation
 *
 * @param line
 */
void	exec_computation(std::string line)
{
	line = line.substr(0, line.size() - 2);
	//std::list<token_ptr> list_tok = lexer(line);
	std::list<token_ptr>	list_tok;
	lexer(line, list_tok);
	std::unique_ptr<IValue> result(computation(list_tok));
	result->display();
}