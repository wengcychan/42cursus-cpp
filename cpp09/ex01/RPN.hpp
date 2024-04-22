#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {

	private:

		std::stack<float> _stack;
		std::string	_input;
 
		RPN();

		void handleDigit(std::string::iterator it);
		void handleOperation(char &sign);

	public:

		class RpnErrorException: public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		RPN(std::string input);
		RPN(RPN const &src);
		RPN &operator=(RPN const &rhs);
		~RPN();

		float calculate();

};

#endif