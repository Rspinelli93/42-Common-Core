#include "bigint.hpp"

bigint::bigint() : _num("0")
{

}

bigint::~bigint()
{

}

bigint::bigint( unsigned long long num ) : _num(std::to_string(num))
{

}

bigint::bigint( std::string num ) : _num(num)
{

}

bigint::bigint( bigint const &other ) : _num(other._num)
{

}

bigint &bigint::operator=(bigint const &other)
{
	if (this != &other)
		this->_num = other._num;
	return ( *this );
}

std::string bigint::getNum( void ) const
{
	return (this->_num);
}

bool	bigint::operator==( bigint const &x ) const
{
	return (this->_num == x._num);
}

bool	bigint::operator!=( bigint const &x ) const
{
	return !(*this == x);
}

bool	bigint::operator<( bigint const &x ) const
{
	if (this->_num.length() != x._num.length())
		return (this->_num.length() < x._num.length());
	return (this->_num.compare(x._num) < 0);
}

bool	bigint::operator>( bigint const &x ) const
{
	return (x < *this);
}

bool	bigint::operator<=( bigint const &x ) const
{
	return !(x < *this);
}

bool	bigint::operator>=( bigint const &x ) const
{
	return !(*this < x);
}

static std::string sumSchool(std::string x, std::string y)
{
	int i = x.size() - 1;
	int j = y.size() - 1;
	int carry = 0;
	std::string ret;

	while (i >= 0 || j >= 0 || carry > 0)
	{
		int digitX = (i >= 0) ? x[i] - '0' : 0;
		int digitY = (j >= 0) ? y[j] - '0' : 0;
		int sum = digitX + digitY + carry;

		ret.insert(ret.begin(), (sum % 10) + '0');
		carry = sum / 10;
		i--;
		j--;
	}
	return (ret);
}

bigint	&bigint::operator+=( bigint const &x )
{
	this->_num = sumSchool(this->_num, x._num);
	return (*this);
}

bigint	bigint::operator+( bigint const &x ) const
{
	bigint ret(*this);
	ret += x;
	return (ret);
}

bigint	&bigint::operator++( void )
{
	*this += bigint(1);
	return (*this);
}

bigint	bigint::operator++( int )
{
	bigint copy(*this);
	++(*this);
	return (copy);
}

bigint	&bigint::operator<<=( bigint const &n )
{
	if (this->_num != "0")
	{
		size_t shift = std::stoul(n._num);
		this->_num.append(shift, '0');
	}
	return (*this);
}

bigint	bigint::operator<<( bigint const &n ) const
{
	bigint ret(*this);
	ret <<= n;
	return (ret);
}

bigint	&bigint::operator>>=( bigint const &n )
{
	size_t shift = std::stoul(n._num);
	if (shift >= this->_num.size())
		this->_num = "0";
	else
		this->_num.erase(this->_num.size() - shift);
	return (*this);
}

bigint	bigint::operator>>( bigint const &n ) const
{
	bigint ret(*this);
	ret >>= n;
	return (ret);
}

std::ostream &operator<<(std::ostream &out, bigint const &number)
{
	out << number.getNum();
	return (out);
}
