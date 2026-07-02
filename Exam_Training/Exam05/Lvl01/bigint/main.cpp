/*
Assignment name : bigint
Expected files : bigint.hpp, bigint.cpp
--------------------------------------------------------------------------------
In computer science a bignum is an object representing an arbitrary precision
number, this is useful when you want to store a number bigger than SIZE_MAX
without any loss of precision. This is often achieved by storing an array or a
string containing the different "parts" of the number.
Create a class called bigint that will store an arbitrary precision unsigned
integer.
Your class must support addition, comparison and "digitshift" (like bitshift but
instead of shifting the bits you will shift the digits in base 10, e.g.:
(42 << 3 == 42000) and (1337 >> 2 == 13)).
Your bigint must be printable with the << operator (in base 10) and the output
should not contain any leading zeros.
You will find a main in this directory that must work with your class
*/
#include "bigint.hpp"

int main(void)
{
	const bigint a(42);
	bigint b(21), c, d(1337), e(d);

	// base test
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + c = " << a + c << std::endl;
	std::cout << "(c += a) = " << (c += a) << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "++b = " << ++b << std::endl;
	std::cout << "b++ = " << b++ << std::endl;

	// b = 23, b << 10 -> 23000000000 + 42 = 23000000042
	std::cout << "(b << 10) + 42 = " << ((b << 10) + 42) << std::endl;
	std::cout << "(d <<= 4) = " << (d <<= 4) << ", d: " << d << std::endl;
	std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << ", d: " << d << std::endl;

	std::cout << "a = " << a << std::endl; // a = 42
	std::cout << "d = " << d << std::endl; // d = 5348

	std::cout << "(d < a) = " << (d < a) << std::endl; // (d < a) = 0
	std::cout << "(d > a) = " << (d > a) << std::endl; // (d > a) = 1
	std::cout << "(d == d) = " << (d == d) << std::endl; // (d == d) = 1
	std::cout << "(d != a) = " << (d != a) << std::endl; // (d != a) = 1
	std::cout << "(d <= a) = " << (d <= a) << std::endl; // (d <= a) = 0
	std::cout << "(d >= a) = " << (d >= a) << std::endl; // (d >= a) = 1
	// extra
	bigint x(12345678); bigint y(5);
	std::cout << "(x << y) = " << (x << y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >>= y) = " << (x >>= y) << ", x: " << x << ", y: " << y << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	std::cout << "x= " << (x <<= 5) << ", y= " << (y <<= 12) << std::endl;
	std::cout << "(x >= y) = " << (x >= y) << ", x: " << x << ", y: " << y << std::endl;

	return (0);
}

// Objective: implement arbitrary-precision unsigned int using 
// string/vector as storage instead of a fixed-size int.
// Design decisions you need to make:

// Storage: std::string of digits (easiest for base-10 shift/print) 
// or std::vector<int> of digits. String is simpler for this subject 
// since shift/print are base-10 native operations.
// Store digits most significant first (normal reading order) — 
// makes <</>> and print trivial. Reversed storage only helps addition, 
// and addition isn't that much harder either way.

// Operators needed:

// operator+ — pure, const, returns new bigint. Classic manual addition: 
// iterate from least significant digit, carry.
// operator==, <, etc. — compare length first, then lexicographic if 
// same length (works because no leading zeros).
// operator<<(int n) — append n zeros.
// operator>>(int n) — drop last n digits (chars), if n >= length result is "0".
// operator<<(ostream&, bigint const&) — free function, print the string.

// Critical trap #1: leading zeros. "007" must never exist internally, 
// or comparisons/printing break. Normalize in constructor and after 
// every operation (strip leading zeros, but keep at least one digit "0").

// Critical trap #2: constructing from string — validate digits, 
// handle "0" specifically.

// Critical trap #3: comparisons only work by length-then-lex-compare because 
// you guarantee no leading zeros. If you skip normalization, comparison 
// logic is wrong.

// Canonical form: constructor, copy ctor, operator=, destructor — all 
// needed, all should be trivial since you likely just hold a std::string.