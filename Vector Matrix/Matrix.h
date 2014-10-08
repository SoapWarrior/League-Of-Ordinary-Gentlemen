#pragma once
#include "Vector4.h"

enum matIndex
{
	Rx, Ux, Fx, Px,
	Ry, Uy, Fy, Py,
	Rz, Uz, Fz, Pz,
	Rw, Uw, Fw, Pw

};

class mat4
{
public:

	//Perspective projections
	//Orthographic projections
	mat4();
	mat4(float rx, float ux, float fx, float px,
		float ry, float uy, float fy, float py,
		float rz, float zx, float fz, float pz,
		float rw, float uw, float fw, float pw);

	//void Frustum();
	//void Orthographic();

	mat4 operator+(const mat4 &other);
	//operator +

	mat4 operator-(const mat4 &other);
	//operator -

	mat4 operator*(float scaler);
	//operator *(float)




	mat4 operator-();
	//opertator -(unary)

	mat4 operator*(const mat4 &other);
	//operator *(mat4)

	



	void Translate(float x, float y, float z,float w);
	void Translate(const vec4 &vec);

<<<<<<< HEAD
	mat4 &operator*(const vec4 &other);
	//operator * (vec4)

=======
	vec4 operator*(const vec4 &other);
//	operator * (vec4)
>>>>>>> origin/master

	//transpose
	//inverse
	//flood
	//scale x,y,z
	//scale v3
//	void RotateX(float degrees);
//	void RotateY(float degrees);
//	void RotateZ(float degrees);
//	void Rotate(float x, float y, float z, float degrees);
	//void Rotate(const vec3 &vec, float degrees);

	//set data to identity
	void LoadIdentity();

	float data[16];


};