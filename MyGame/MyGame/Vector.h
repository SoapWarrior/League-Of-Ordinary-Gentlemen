#pragma once

class vec2
{

public:
	float x, y;
	//constructors
	vec2();
	vec2(float X, float Y);
	//overloaded operators
	//= + - * / 
	vec2 &operator=(const vec2 &other);
	vec2 operator+(const vec2 &other) const;
	vec2 operator-(const vec2 &other) const;
	vec2 operator*(float scalar) const;
	vec2 operator/(float scalar) const;

	vec2 operator-() const;
	bool operator == (const vec2 &other) const;
	//-
	//==
	vec2 operator+=(const vec2 &other);
	vec2 operator-=(const vec2 &other);
	vec2 operator/=(const vec2 &other);
	vec2 operator*=(const vec2 &other);
	// +=
	// -=
	// /=
	// */

	float Dot(const vec2 &other) const;

	void Normalize();
	vec2 Direction() const;

	float Length() const;
	float LengthSquared() const;
	//basic operations
	//dot
	//normalize
	//get length

	//static functions
	static vec2 Unit() 
	{
		return vec2(1.0f, 1.0f);
	}
	static vec2 Zero()
	{
		return vec2(0.0f, 0.0f);
	}
};




