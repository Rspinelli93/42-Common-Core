#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
	private:
		std::string _num;

	public:
		bigint();
		~bigint();
		bigint( unsigned long long num );
		bigint( std::string num );
		bigint( bigint const &other );
		bigint &operator=(bigint const &other);
		std::string getNum( void ) const;

		bool	operator==( bigint const &x ) const;
		bool	operator!=( bigint const &x ) const;
		bool	operator<=( bigint const &x ) const;
		bool	operator>=( bigint const &x ) const;
		bool	operator>( bigint const &x ) const;
		bool	operator<( bigint const &x ) const;

		bigint	operator+( bigint const &x ) const;
		bigint	&operator+=( bigint const &x );
		bigint	&operator++( void );
		bigint	operator++( int );

		bigint	operator<<( bigint const &n ) const;
		bigint	&operator<<=( bigint const &n );
		bigint	operator>>( bigint const &n ) const;
		bigint	&operator>>=( bigint const &n );
};

std::ostream &operator<<(std::ostream &out, bigint const &number);

#endif
