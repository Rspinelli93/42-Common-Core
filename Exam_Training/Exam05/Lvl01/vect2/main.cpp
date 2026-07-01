/*
*	Assignement name: vect2
*	Expected files: vect2.cpp, vect2.hpp
*	--------------------------------------------------------
*
*	Create a class vect2 representing a mathematical vector
*	of dimension 2 containing ints.
*
*	It must support addition, substraction and multiplication
*	by a scalar, such as the expression:
*	(vect2(2,2) * 2 == vect2(4,4)) is true.
*
*	The operator [] can be used to access the component
*	of your vector (with 0 and 1), no bound checking is required.
*
*	Your function must be printable with the << operator such as:
*		std::cout << v << std::endl;
*	Produce the same output as:
*		std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
*
*	You will find a main in this directory that must work
*	with your class.
*
*	--------------------------------------------------------
*/

#include "vect2.hpp"

int main()
{
	vect2 v1;			// 0, 0
	vect2 v2(1, 2);		// 1, 2
	const vect2 v3(v2);	// 1, 2
	vect2 v4 = v2;		// 1, 2

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v3: " << v3 << std::endl;
	std::cout << "v4: " << v4 << std::endl;
	std::cout << v4++ << std::endl;	// == 2, 3 (displays: 1, 2)
	std::cout << ++v4 << std::endl;	// == 3, 4 (displays: 3, 4)
	std::cout << v4-- << std::endl;	// == 2, 3 (displays: 3, 4)
	std::cout << --v4 << std::endl;	// == 1, 2 (displays: 1, 2)

	v2 += v3;			// 2, 4
	v1 -= v2;			// -2, -4
	v2 = v3 + v3 * 2;	// 3, 6
	v2 = 3 * v2;		// 9, 18
	v2 += v2 += v3;		// 20, 40
	v1 *= 42;			// -84, -168
	v1 = v1 - v1 + v1;

	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "-v2: " << -v2 << std::endl;
	std::cout << "v1[1]: " << v1[1] << std::endl;
	v1[1] = 12;
	std::cout << "v1[1]: " << v1[1] << std::endl;
	std::cout << "v3[1]: " << v3[1] << std::endl;
	std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
	std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
	std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
	std::cout << "v1 != v1: " << (v1 != v1) << std::endl;

	return (0);
}

// Core rule: match the real-world semantics.
// For any operator, ask: "does this create a new value, or mutate an existing one?"

// Creates new value (+, -, *, /, unary -, comparisons) → don't touch *this, build a local object, return it by value, mark const.
// Mutates (+=, -=, *=, ++, -- prefix) → modify *this, return *this by reference.
// Postfix ++/-- → save a copy first, mutate *this, return the old copy by value (can't return reference to a local).

// Const-ness rule of thumb:
// If the operator doesn't need to modify the object it's called on, mark it const. This matters because const vect2 v3 can only call const methods. If you forget const on operator+, code like v3 + v3 won't compile. Exam gotcha #1.
// Reference vs value:

// Return by value when you're returning something newly built (it dies with the function otherwise → dangling reference).
// Return by reference when you're returning *this or an existing member (operator[], operator+=).
// Take parameters const & unless you need to modify the argument (almost never).

// Symmetry check (3 * v2):
// Member functions only work when the object is on the left (v2 * 3). If the left operand isn't your class (int * vect2), it must be a free function outside the class — this can't be an int.
// Chaining (v2 += v2 += v3):
// Only works if += returns a reference to a real object (*this), not a copy. If you return by value, chaining still compiles but loses the "same object" semantics and can silently misbehave.
// Cast-to-bool traps (i == 0/==1 in operator[]):
// No exhaustive if/else with guaranteed return = compiler warning/UB. Always make sure every path returns.
// One-line self-test before writing any operator:

// Does it need to read only, or modify?
// What type do I return — value or reference?
// Should this be const?
// Is the left-hand operand always going to be my class? If not → free function.