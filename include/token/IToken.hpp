#ifndef ITOKEN_HPP
# define ITOKEN_HPP


#include <string>
#include "parsing.hpp"

class	IToken {

	private:
		IToken(void);
		IToken &operator=(const IToken &rhs);

	protected:
		std::string _lit;
		token_type	_type;

	public:
		IToken(std::string str, token_type type);
		IToken(const IToken &rhs);
		virtual ~IToken();

		//methods
		virtual std::string to_string() const = 0;
		token_type			get_type(void) const;
};

#endif