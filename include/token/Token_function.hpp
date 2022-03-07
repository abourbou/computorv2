#ifndef TOKEN_FUNCTION
# define TOKEN_FUNCTION

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"
#include "singleton.hpp"

class Token_function : public IToken
{
	private:
		std::string _fct;
		std::string _expr;

	public:
		Token_function(void) = delete;
		Token_function(std::string str);
		Token_function(const Token_function &rhs);
		Token_function &operator=(const Token_function &rhs);
		virtual ~Token_function(void);

		const IValue	*get_fct(void) const;
		std::string	get_lit(void) const;

};

#endif