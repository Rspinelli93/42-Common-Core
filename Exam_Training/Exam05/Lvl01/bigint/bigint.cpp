#include "bigint.hpp"

bigint::bigint() : _digits("0") {}

bigint::~bigint() {}

bigint::bigint( unsigned long long num ) : _digits(std::to_string(num)) {};

bigint::bigint(bigint const &other) : _digits(other._digits) {}

bigint &bigint::operator=(bigint const &other)
{
	if (this != &other)
		this->_digits = other._digits;
	return (*this);
}

//-----------

void bigint::_addRecursive(int posA, int posB, int carry, bigint const &other)
{
	if (posA < 0 && posB < 0 && carry == 0)
		return ;

	int digitA;
	int digitB;
	if (posA >= 0)
		digitA = _digits[posA] + '0';
	else
		digitA = 0;
	if (posB >= 0)
		digitB = _digits[posB] + '0';
	else
		digitB = 0;
	
	int sum = digitA + digitB + carry;

	_addRecursive(posA - 1, posB -1, sum / 10, other);

	if (posA >= 0)
		_digits[posA] = (sum % 10) + '0';
	else
		_digits = char((sum % 10) + '0') + _digits;
}

bigint bigint::operator+( bigint const &other ) const
{
	bigint copy(*this);
	copy += other;
	return (copy);
}

bigint &bigint::operator++(void) { *this += (bigint)1; return (*this); }

bigint bigint::operator++(int) 
{
	bigint copy(*this);
	*this += (bigint)1;
	return (copy);
}

bigint &bigint::operator+=( bigint const &other )
{
	_addRecursive(_digits.size() - 1, other._digits.size() -1, 0, other);
	return (*this);
}