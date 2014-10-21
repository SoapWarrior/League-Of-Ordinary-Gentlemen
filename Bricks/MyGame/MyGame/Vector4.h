#pragma once

class vec4
{

public:
	float x, y, z, w;
	//constructors
	vec4();
	vec4(float X, float Y,float Z,float W);
	//overloaded operators
	//= + - * / 
	vec4 &operator=(const vec4 &other);
	vec4 operator+(const vec4 &other) const;
	vec4 operator-(const vec4 &other) const;
	vec4 operator*(float scalar) const;
	vec4 operator/(float scalar) const;

	vec4 operator-() const;
	bool operator == (const vec4 &other) const;
	//-
	//==
	vec4 operator+=(const vec4 &other);
	vec4 operator-=(const vec4 &other);
	vec4 operator/=(const vec4 &other);
	vec4 operator*=(const vec4 &other);
	// +=
	// -=
	// /=
	// */

	float Dot(const vec4 &other) const;

	void Normalize();
	vec4 Direction() const;

	float Length() const;
	float LengthSquared() const;
	//basic operations
	//dot
	//normalize
	//get length

	//static functions
	static vec4 Unit()
	{
		return vec4(1.0f, 1.0f,1.0f,1.0f);
	}
	static vec4 Zero()
	{
		return vec4(0.0f, 0.0f,0.0f,0.0f);
	}
};




