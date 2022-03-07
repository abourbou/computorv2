#ifndef TOKEN_VARIABLE
# define TOKEN_VARIABLE

#include "IToken.hpp"
#include "IValue.hpp"
#include "parsing.hpp"

class Token_variable : public IToken
{
	private:
		Token_variable(void);
		IValue *_value;

	public:
		Token_variable(std::string str);
		Token_variable(const Token_variable &rhs);
		Token_variable &operator=(const Token_variable &rhs);
		virtual ~Token_variable(void);
		IValue *operation(const IValue *val1, const IValue *val2) const;
		std::string get_lit() const;

};

#endif