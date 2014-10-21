#include "Vector.h"
#include <math.h>

vec2::vec2()
{

	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(float X, float Y)
{
	x = X;
	y = Y;
}


vec2 vec2::Direction() const
{
	vec2 temp(*this);
	temp.Normalize();
	return temp;

}

void vec2::Normalize()
{
	float length = Length();
	x /= length;
	y /= length;
}


float vec2::Dot(const vec2 &other) const
{
	return x* other.x + y *other.y;


}

float vec2::Length() const
{
	return sqrt(x*x + y*y);

}

float vec2::LengthSquared() const
{
	return x*x + y*y;

}



vec2 &vec2::operator=(const vec2 &other)
{
	x = other.x;
	y = other.y;
	return vec2(x, y);
}




vec2 vec2::operator+(const vec2 &other) const
{
	return vec2(x + other.x, y + other.y);
}


vec2 vec2::operator-(const vec2 &other) const
{
	return vec2(x - other.x, y - other.y);
}


vec2 vec2::operator*(float scalar) const
{
	return vec2(x*scalar, y*scalar);
}


vec2 vec2::operator/(float scalar) const
{
	return vec2(x/scalar, y/scalar);
}

vec2 vec2::operator-() const
{
	return vec2(-x, -y);
}
bool vec2::operator == (const vec2 &other) const
{
	return x == other.x && y == other.y;
}

vec2 vec2::operator+=(const vec2 &other)
{

	return vec2(x=x + other.x, y=  y + other.y);

}

vec2 vec2::operator-=(const vec2 &other)
{

	return vec2(x = x - other.x, y = y - other.y);

}


/*vec2 vec2::operator/=(const vec2 &other)
{

}
vec2 vec2::operator*=(const vec2 &other)
{

}*/