#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	private:
		int _data[2];

	public:
		vect2();
		vect2(int x, int y);
		vect2(vect2 const &other);
		vect2 &operator=(vect2 const &other);
		~vect2();

		int &operator[](int index);
		int const &operator[](int index) const;

		vect2 &operator+=(vect2 const &other);
		vect2 &operator-=(vect2 const &other);
		vect2 &operator*=(int scalar);

		vect2 operator+(vect2 const &other) const;
		vect2 operator-(vect2 const &other) const;
		vect2 operator*(int scalar) const;
		vect2 operator-(void) const;

		vect2 &operator++(void);
		vect2 operator++(int);
		vect2 &operator--(void);
		vect2 operator--(int);

		bool operator==(vect2 const &other) const;
		bool operator!=(vect2 const &other) const;
};

vect2 operator*(int scalar, vect2 const &v);
std::ostream &operator<<(std::ostream &out, vect2 const &v);

#endif
