#pragma once
#ifndef POLYN_EQUATION_HPP
# define POLYN_EQUATION_HPP

#include <string>
#include <map>
#include <exception>
#include <iostream>
#include <algorithm>
#include "string_function.hpp"
#include "math_utility.hpp"

//Color off
#define Color_Off "\033[0m"       // Text Reset

// Regular Colors
#define Black "\033[0;30m"        // Black
#define Red "\033[0;31m"          // Red
#define Green "\033[0;32m"        // Green
#define Yellow "\033[0;33m"       // Yellow
#define Blue "\033[0;34m"         // Blue
#define Purple "\033[0;35m"       // Purple
#define Cyan "\033[0;36m"         // Cyan
#define White "\033[0;37m"        // White

// Underline
#define UBlack "\033[4;30m"       // Black
#define URed "\033[4;31m"         // Red
#define UGreen "\033[4;32m"       // Green
#define UYellow "\033[4;33m"      // Yellow
#define UBlue "\033[4;34m"        // Blue
#define UPurple "\033[4;35m"      // Purple
#define UCyan "\033[4;36m"        // Cyan
#define UWhite "\033[4;37m"       // White

class Polyn_Equation{
	private:
		//forbidden coplien functions
		Polyn_Equation(void);
		Polyn_Equation &operator=(const Polyn_Equation &rhs);

		//variables
		//size_t : degree of the polynm, double : value at this degree
		//example : 2.5 * X ^ 3 => size_t : 3, double : 2.5
		std::map<size_t, double> _left_side;
		std::map<size_t, double> _right_side;
		size_t max_degree = 0;
		bool _is_reduce = false;

		//private members use by other
		size_t	is_an_equation(std::string const &str_equation) const;
		void	parse_side(bool is_right_side, std::string str_side);
		void	parse_term(bool is_right_side, std::string str_term);
		void	send_to_struct(bool str_side, double coefficient, size_t degree);

	public:
		Polyn_Equation(std::string);
		~Polyn_Equation(void);
		void reduce_it();
		void solve_it() const;
		std::string	convert_string(void) const;
		size_t	get_max_degree(void) const;

		/**
		 * Exceptions
		 */
		class NotAnEquation : virtual public std::exception
		{
			private:
				std::string _message;
			public:
				virtual const char *what(void) const noexcept override
				{ return (_message.c_str()); }
				NotAnEquation(void) : _message{"Not an equation"} {}
				NotAnEquation(std::string message) : _message{"Not an equation : " + message}{}
		};

		class InvalidSide : virtual public std::exception
		{
			protected:
				std::string	_side;
				std::string	_message;
			public:
				virtual const char *what(void) const noexcept override
				{ return(_message.c_str()); }
				InvalidSide(void) : _message{"Invalid Side"} {}
				InvalidSide(std::string message) : _message{message} {}
				InvalidSide(bool is_right_side, std::string message) :
					_side{(!is_right_side) ? "left" : "right"},
					_message{"Invalid " + _side + " side" + " : " + message}
				{}
		};

		class InvalidTerm : virtual public std::exception
		{
			private:
				std::string _side;
				std::string _message;

			public:
				virtual const char *what(void) const noexcept override
				{ return(_message.c_str()); }
			InvalidTerm(void) : _message{"Invalid Term"} {}
			InvalidTerm(bool is_right_side, std::string message) :
				_side{(!is_right_side) ? "left" : "right"},
				_message{"Invalid term on " + _side + " side : " + message}
			{}
		};
};

std::ostream	&operator<<(std::ostream &o, Polyn_Equation const &rhs);

#endif