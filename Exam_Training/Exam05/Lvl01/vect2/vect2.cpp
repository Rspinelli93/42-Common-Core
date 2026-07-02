#include "vect2.hpp"

//*
vect2::vect2()
{
	_data[0] = 0;
	_data[1] = 0;
}

//*
vect2::vect2(int x, int y)
{
	_data[0] = x;
	_data[1] = y;
}

//*
vect2::vect2(vect2 const &other)
{
	_data[0] = other._data[0];
	_data[1] = other._data[1];
}

//*
vect2 &vect2::operator=(vect2 const &other)
{
	if (this != &other)
	{
		_data[0] = other._data[0];
		_data[1] = other._data[1];
	}
	return (*this);
}

//*
vect2::~vect2()
{

}

//*
int &vect2::operator[](int index)
{
	return (_data[index]);
}

//*
int const &vect2::operator[](int index) const
{
	return (_data[index]);
}

//*
vect2 &vect2::operator+=(vect2 const &other)
{
	_data[0] += other._data[0];
	_data[1] += other._data[1];
	return (*this);
}

//*
vect2 &vect2::operator-=(vect2 const &other)
{
	_data[0] -= other._data[0];
	_data[1] -= other._data[1];
	return (*this);
}

//*
vect2 &vect2::operator*=(int scalar)
{
	_data[0] *= scalar;
	_data[1] *= scalar;
	return (*this);
}

//*
vect2 vect2::operator+(vect2 const &other) const
{
	vect2 ret(*this);
	ret += other;
	return (ret);
}

//*
vect2 vect2::operator-(vect2 const &other) const
{
	vect2 ret(*this);
	ret -= other;
	return (ret);
}

//*
vect2 vect2::operator*(int scalar) const
{
	vect2 ret(*this);
	ret *= scalar;
	return (ret);
}

//*
vect2 vect2::operator-(void) const
{
	return (vect2(-_data[0], -_data[1]));
}

//*
vect2 &vect2::operator++(void)
{
	_data[0]++;
	_data[1]++;
	return (*this);
}

//*
vect2 vect2::operator++(int)
{
	vect2 copy(*this);
	++(*this);
	return (copy);
}

//*
vect2 &vect2::operator--(void)
{
	_data[0]--;
	_data[1]--;
	return (*this);
}

//*
vect2 vect2::operator--(int)
{
	vect2 copy(*this);
	--(*this);
	return (copy);
}

//*
bool vect2::operator==(vect2 const &other) const
{
	return (_data[0] == other._data[0] && _data[1] == other._data[1]);
}

//*
bool vect2::operator!=(vect2 const &other) const
{
	return !(*this == other);
}

//*
vect2 operator*(int scalar, vect2 const &v)
{
	return (v * scalar);
}

//*
std::ostream &operator<<(std::ostream &out, vect2 const &v)
{
	out << "{" << v[0] << ", " << v[1] << "}";
	return (out);
}
