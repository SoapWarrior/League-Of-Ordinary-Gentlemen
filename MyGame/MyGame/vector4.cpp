#include "Vector4.h"
#include <math.h>

vec4::vec4()
{

	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

vec4::vec4(float X, float Y, float Z, float W)
{
	x = X;
	y = Y;
	z = Z;
	w = W;
}


vec4 vec4::Direction() const
{
	vec4 temp(*this);
	temp.Normalize();
	return temp;

}

void vec4::Normalize()
{
	float length = Length();
	x /= length;
	y /= length;
	z /= length;
	w /= length;
}


float vec4::Dot(const vec4 &other) const
{
	return x* other.x + y *other.y + z* other.z + w*other.w;


}

float vec4::Length() const
{
	return sqrt(x*x + y*y + z*z + w*w);

}

float vec4::LengthSquared() const
{
	return x*x + y*y + z*z + w*w;

}



vec4 &vec4::operator=(const vec4 &other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return vec4(x, y, z, w);
}




vec4 vec4::operator+(const vec4 &other) const
{
	return vec4(x + other.x, y + other.y, z + other.z, w+other.w);
}


vec4 vec4::operator-(const vec4 &other) const
{
	return vec4(x - other.x, y - other.y, z - other.z,w-other.w);
}


vec4 vec4::operator*(float scalar) const
{
	return vec4(x*scalar, y*scalar, z*scalar, w*scalar);
}


vec4 vec4::operator/(float scalar) const
{
	return vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}

vec4 vec4::operator-() const
{
	return vec4(-x, -y, -z, -w);
}
bool vec4::operator == (const vec4 &other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

