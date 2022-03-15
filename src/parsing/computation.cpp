
#include <list>
#include <string>
#include "IToken.hpp"
#include "Token_operator.hpp"
#include "IValue.hpp"
#include "parsing.hpp"

size_t		priority(std::string str_operator)
{
	if (str_operator == "+" || str_operator == "-")
		return (1);
	else if (str_operator == "*" || str_operator == "/" || str_operator == "%" || str_operator == "**")
		return (2);
	else if (str_operator == "^")
		return (3);
	else
		return (0);
}

std::list<token_ptr>::iterator	find_priority_operator(std::list<token_ptr> &list_token)
{
	size_t	max_priority = 0;
	auto	it = std::next(list_token.begin());
	size_t	position = 1;
	auto	priority_it = list_token.end();

	while (position < list_token.size())
	{
		std::string current_operator = (*it)->to_string();
		size_t	current_priority = priority(current_operator);
		if (current_priority > max_priority)
		{
			max_priority = current_priority;
			priority_it = it;
		}
		std::advance(it, 2);
		position += 2;
	}
	return (priority_it);
}

IValue *do_operation(std::list<token_ptr>::iterator priority_it)
{
	const IValue *left_value = 0;
	const IValue *right_value = 0;
	IValue *result_operation = 0;

	std::unique_ptr<Token_operator> operator_it(static_cast<Token_operator *>((*priority_it)->clone()));
	try{
		left_value = (*std::prev(priority_it))->get_value();
		right_value = (*std::next(priority_it))->get_value();
		result_operation = operator_it->operation(left_value, right_value);
	}
	catch(const std::exception& e)
	{
		if ((*std::prev(priority_it))->get_type() == token_type::parenthesis && left_value)
			delete left_value;
		if ((*std::next(priority_it))->get_type() == token_type::parenthesis && right_value)
			delete right_value;
		throw(std::runtime_error(e.what()));
	}
	if ((*std::prev(priority_it))->get_type() == token_type::parenthesis)
		delete left_value;
	if ((*std::next(priority_it))->get_type() == token_type::parenthesis)
		delete right_value;

	return (result_operation);
}

//do computation on the list
//carefull it will modify the list
IValue *computation(const std::list<token_ptr>& list_token)
{
	std::list<token_ptr>	copy_list;

	for (const auto& elem: list_token)
		copy_list.push_back(std::unique_ptr<IToken>(elem->clone()));

	while (1)
	{
		//find priority operator
		std::list<token_ptr>::iterator	priority_it = find_priority_operator(copy_list);
		if (priority_it == copy_list.end())
		{
			//std::cout << "no more operator" << std::endl;
			IValue *result = static_cast<IValue*>(copy_list.front()->get_value()->clone());
			//clean_list_token(copy_list);
			return (result);
		}
		else
		{
			IValue *result_operation = do_operation(priority_it);
			*priority_it = std::make_unique<Token_value>(Token_value(result_operation));

			copy_list.erase(std::next(priority_it));
			copy_list.erase(std::prev(priority_it));
		}
	}
	return (0);
}