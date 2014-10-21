#pragma once

class vec3
{

public:
	float x, y, z;
	//constructors
	vec3();
	vec3(float X, float Y, float Z);
	//overloaded operators
	//= + - * / 
	vec3 &operator=(const vec3 &other);
	vec3 operator+(const vec3 &other) const;
	vec3 operator-(const vec3 &other) const;
	vec3 operator*(float scalar) const;
	vec3 operator/(float scalar) const;

	vec3 operator-() const;
	bool operator == (const vec3 &other) const;
	//-
	//==
	vec3 operator+=(const vec3 &other);
	vec3 operator-=(const vec3 &other);
	vec3 operator/=(const vec3 &other);
	vec3 operator*=(const vec3 &other);
	// +=
	// -=
	// /=
	// */

	float Dot(const vec3 &other) const;

	void Normalize();
	vec3 Direction() const;

	float Length() const;
	float LengthSquared() const;
	//basic operations
	//dot
	//normalize
	//get length

	//static functions
	static vec3 Unit()
	{
		return vec3(1.0f, 1.0f,1.0f);
	}
	static vec3 Zero()
	{
		return vec3(0.0f, 0.0f,0.0f);
	}
};




