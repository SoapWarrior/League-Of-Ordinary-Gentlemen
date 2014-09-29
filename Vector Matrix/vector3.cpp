#include "Vector3.h"
#include <math.h>

vec3::vec3()
{

	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(float X, float Y,float Z)
{
	x = X;
	y = Y;
	z = Z;
}


vec3 vec3::Direction() const
{
	vec3 temp(*this);
	temp.Normalize();
	return temp;

}

void vec3::Normalize()
{
	float length = Length();
	x /= length;
	y /= length;
	z /= length;
}


float vec3::Dot(const vec3 &other) const
{
	return x* other.x + y *other.y + z* other.z;


}

float vec3::Length() const
{
	return sqrt(x*x + y*y + z*z);

}

float vec3::LengthSquared() const
{
	return x*x + y*y + z*z;

}



vec3 &vec3::operator=(const vec3 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return vec3(x, y, z);
}




vec3 vec3::operator+(const vec3 &other) const
{
	return vec3(x + other.x, y + other.y, z+other.z);
}


vec3 vec3::operator-(const vec3 &other) const
{
	return vec3(x - other.x, y - other.y, z - other.z);
}


vec3 vec3::operator*(float scalar) const
{
	return vec3(x*scalar, y*scalar,z*scalar);
}


vec3 vec3::operator/(float scalar) const
{
	return vec3(x / scalar, y / scalar,z/scalar);
}

vec3 vec3::operator-() const
{
	return vec3(-x, -y,-z);
}
bool vec3::operator == (const vec3 &other) const
{
	return x == other.x && y == other.y && z == other.z;
}

