#ifndef DATA_HPP
# define DATA_HPP

class Data {

	private:

		int	_value;
		Data(void);

	public:
 
		Data(int value);
		Data(const Data &src);
		Data & operator=(const Data &rhs);
		~Data(void);

		const int &getValue(void) const;

};

#endif