#ifndef TOKEN_VARIABLE
# define TOKEN_VARIABLE

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"
#include "singleton.hpp"

class Token_variable : public IToken
{
	private:
		Token_variable(void);

	public:
		Token_variable(std::string str);
		Token_variable(const Token_variable &rhs);
		Token_variable &operator=(const Token_variable &rhs);
		virtual ~Token_variable(void);
		const IValue	*get_var(void) const;
		std::string		get_lit(void) const;

};

#endif