#ifndef EXCEPTION_CLASSES_HPP
# define EXCEPTION_CLASSES_HPP

#include <exception>

class	ForbiddenCharacter : public std::exception
{
	public:
		virtual const char	*what(void) const throw()
		{
			return("Forbidden Character");
		}
};

#endif