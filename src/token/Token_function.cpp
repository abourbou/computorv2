
#include "Token_function.hpp"

/**
 * @brief transform an string expression to a IValue
 *
 * @param expr
 * @return IValue* return 0 if no conversion is sutable
 */
IValue	*expr_to_value(std::string expr)
{
	Map_variable	&map_var = Singleton::GetInstance()->get_map_variable();
	const IVariable *buffer_var;

	if (is_alpha(expr))
	{
		buffer_var = map_var.get_var(expr);
		if (buffer_var->get_type() == variable_type::function)
			throw(std::runtime_error("expression in the function must not be a function"));
		return (static_cast<IValue*>(buffer_var->clone()));
	}
	else if (expr.find('[') != std::string::npos || expr.find(']') != std::string::npos)
		return(new Matrix(expr));
	else if (expr.find('i') != std::string::npos)
		return(new Complex(expr));
	return (new Rational(expr));
}

/**
 * @brief call the function and the value from the map_var to do the computation
 *
 * @return const IValue*
 */
const IValue *compute(std::string _fct, std::string _expr)
{
	Map_variable &map_var = Singleton::GetInstance()->get_map_variable();
	const IVariable	*buffer_var;
	const IFunction *f;

	//get the fct from the map
	buffer_var = map_var.get_var(_fct);
	if (buffer_var->get_type() != variable_type::function)
		throw(std::runtime_error("the function isn't a function"));
	f = static_cast<const IFunction *>(buffer_var);

	//get the value of the fct if it is a variable, call its value from the map
	const IValue *value = expr_to_value(_expr);

	const IValue *result;
	try {
		result = f->fct_computation(value);
	}
	catch(std::exception &e)
	{
		delete value;
		throw(std::runtime_error(e.what()));
	}
	delete value;
	return(result);
}

/**
 * @brief Construct a token for a function
 *
 * @param str must be on the form [fct(var / expr)]
 */
Token_function::Token_function(std::string str): IToken(str, token_type::math_function)
{
	size_t start, end;
	Map_variable &map = Singleton::GetInstance()->get_map_variable();
	std::string	_fct;
	std::string	_expr;

	//find function
	start = str.find("(");
	if (start == std::string::npos || start == 0)
		throw std::runtime_error("unvalid function syntax");
	_fct = str.substr(0, start);
	if (!map.is_var(_fct))
		throw std::runtime_error("unknown function in function token");

	//find expr
	end = str.find(")");
	if (end == std::string::npos || end <= start + 1 || end != str.size() - 1)
		throw std::runtime_error("unvalid function syntax");
	_expr = str.substr(start + 1, end - start - 1);

	//compute result
	_result = compute(_fct, _expr);
}

Token_function::Token_function(const Token_function &rhs): IToken(rhs), _result(static_cast<IValue*>(rhs._result->clone()))
{
}

Token_function &Token_function::operator=(const Token_function &rhs)
{
	_result = static_cast<IValue*>(rhs._result->clone());

	return(*this);
}

Token_function::~Token_function()
{
	delete _result;
}

std::string Token_function::to_string(void) const
{
	return(_result->to_string());
}

IToken	*Token_function::clone(void) const
{
	return(new Token_function(*this));
}

const IValue	*Token_function::get_value(void) const
{
	return (_result);
}