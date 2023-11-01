#ifndef BRAIN_HPP
# define BRAIN_HPP

# define NB_IDEA 100

#include <string>

class Brain {

	private:

		std::string	_ideas[NB_IDEA];
		int			_countIdea;


	public:

		Brain( void );
		Brain( Brain const & src );
		Brain & operator=( Brain const & rhs );
		~Brain ( void );

		void	setIdea( std::string idea );
		void	printIdea( void );
};

#endif
