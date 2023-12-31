#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {

	private:

		unsigned int _maxLen;
		std::vector<int> _v;
		Span(void);
	

	public:

		class MaxLenException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		Span(unsigned int maxLen);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span(void);

		std::vector<int> const &getSpan(void) const;

		void addNumber(int number);
		void addManyNumbers(int array[], int size);
		int	shortestSpan(void);
		int	longestSpan(void);


};

#endif