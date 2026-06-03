#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

class bigint
{
	private:
		 std::string _digits;
	public:
		bigint();
		~bigint();
		bigint( unsigned long long num );
		bigint(bigint const &other);
		bigint &operator=(bigint const &other);

		//Adding
		void _addRecursive(int posA, int posB, int carry, bigint const &other);
		bigint operator+(bigint const &other) const;
		bigint &operator++( void );
		bigint operator++( int );
		bigint &operator+=(bigint const &other);

		//Bit shift
		bigint operator<<( bigint const &other ) const;
		bigint operator>>( bigint const &other ) const;
		bigint &operator>>=( bigint const &other );
		bigint &operator<<=( bigint const &other );

		//Comparison
		bool operator>( bigint const &other ) const;
		bool operator<( bigint const &other ) const;
		bool operator<=( bigint const &other ) const;
		bool operator>=( bigint const &other ) const;
		bool operator!=( bigint const &other ) const;
		bool operator==( bigint const &other ) const;

};

std::ostream &operator<<(std::ostream &out, bigint const &num);

#endif