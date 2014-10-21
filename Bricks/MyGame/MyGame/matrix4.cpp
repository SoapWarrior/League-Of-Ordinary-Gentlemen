#include "Matrix.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>

mat4::mat4()
{
	data[Rx] = 1.0f, data[Ux] = 0.0f, data[Fx] = 0.0f, data[Px] = 0.0f;
	data[Ry] = 0.0f, data[Uy] = 1.0f, data[Fy] = 0.0f, data[Py] = 0.0f;
	data[Rz] = 0.0f, data[Uz] = 0.0f, data[Fz] = 1.0f, data[Fz] = 0.0f;
	data[Rw] = 0.0f, data[Uw] = 0.0f, data[Fw] = 0.0f, data[Fw] = 1.0f;
	
}

mat4::mat4(float rx, float ux, float fx, float px,
	float ry, float uy, float fy, float py,
	float rz, float uz, float fz, float pz,
	float rw, float uw, float fw, float pw)
{
	data[Rx] = rx, data[Ux] = ux, data[Fx] = fx, data[Px] = px;
	data[Ry] = ry, data[Uy] = uy, data[Fy] = fy, data[Py] = py;
	data[Rz] = rz, data[Uz] = uz, data[Fz] = fz, data[Pz] = pz;
	data[Rw] = rw, data[Uw] = uw, data[Fw] = fw, data[Pw] = pw;
}

void mat4::LoadIdentity()
{

	data[Rx] = 1.0f, data[Ux] = 0.0f, data[Fx] = 0.0f, data[Px] = 0.0f;
	data[Ry] = 0.0f, data[Uy] = 1.0f, data[Fy] = 0.0f, data[Py] = 0.0f;
	data[Rz] = 0.0f, data[Uz] = 0.0f, data[Fz] = 1.0f, data[Fz] = 0.0f;
	data[Rw] = 0.0f, data[Uw] = 0.0f, data[Fw] = 0.0f, data[Fw] = 1.0f;

}

void mat4::Translate(float x, float y, float z,float w)
{

	data[Px] = data[Rx] * x + data[Ux] * x + data[Fx] * x + data[Px] * w;
	data[Py] = data[Ry] * y + data[Uy] * y + data[Fy] * y + data[Py] * w;
	data[Pz] = data[Rz] * z + data[Uz] * z + data[Fz] * z + data[Pz] * w;
	data[Pw] = data[Rw] * w + data[Uw] * w + data[Fw] * w + data[Pw] * w;

}

void mat4::Translate(const vec4 &vec)
{
	data[Px] = data[Rx] * vec.x + data[Ux] * vec.x + data[Fx] * vec.x + data[Px] * vec.w;
	data[Py] = data[Ry] * vec.y + data[Uy] * vec.y + data[Fy] * vec.y + data[Py] * vec.w;
	data[Pz] = data[Rz] * vec.z + data[Uz] * vec.z + data[Fz] * vec.z + data[Pz] * vec.w;
	data[Pw] = data[Rw] * vec.w + data[Uw] * vec.w + data[Fw] * vec.w + data[Pw] * vec.w;

}

mat4 mat4::operator*(const vec4 &vec)
{

	data[Px] = data[Rx] * vec.x + data[Ux] * vec.x + data[Fx] * vec.x + data[Px] * vec.w;
	data[Py] = data[Ry] * vec.y + data[Uy] * vec.y + data[Fy] * vec.y + data[Py] * vec.w;
	data[Pz] = data[Rz] * vec.z + data[Uz] * vec.z + data[Fz] * vec.z + data[Pz] * vec.w;
	data[Pw] = data[Rw] * vec.w + data[Uw] * vec.w + data[Fw] * vec.w + data[Pw] * vec.w;

}

mat4 mat4::operator*(float scalar) 
{

	return 	mat4
		(data[Rx] = data[Rx] * scalar, data[Ux] = data[Ux] * scalar, data[Fx] = data[Fx] * scalar, data[Px] = data[Px] * scalar,
		data[Ry] = data[Ry] * scalar, data[Uy] = data[Uy] * scalar, data[Fy] = data[Fy] * scalar, data[Py] = data[Py] * scalar,
		data[Rx] = data[Rz] * scalar, data[Uz] = data[Uz] * scalar, data[Fz] = data[Fz] * scalar, data[Pz] = data[Pz] * scalar,
		data[Rw] = data[Rw] * scalar, data[Uw] = data[Uw] * scalar, data[Fw] = data[Fw] * scalar, data[Pw] = data[Pw] * scalar);
}
//operator*

mat4 mat4::operator+(const mat4 &other) 
{

	return 	mat4
		(data[Rx] = data[Rx] + other.data[Rx], data[Ux] = data[Ux] + other.data[Ux], data[Fx] = data[Fx] + other.data[Fx], data[Px] = data[Px] +other.data[Px],
		data[Ry] = data[Ry] + other.data[Ry], data[Uy] = data[Uy] + other.data[Uy], data[Fy] = data[Fy] + other.data[Fy], data[Py] = data[Py] + other.data[Py],
		data[Rz] = data[Rz] + other.data[Rz], data[Uz] = data[Uz] + other.data[Uz], data[Fz] = data[Fz] + other.data[Fz], data[Pz] = data[Pz] + other.data[Pz],
		data[Rw] = data[Rw] + other.data[Rw], data[Uw] = data[Uw] + other.data[Uw], data[Fw] = data[Fw] + other.data[Fw], data[Pw] = data[Pw] + other.data[Pw]);

}
//operator +

mat4 mat4::operator-(const mat4 &other)
{

	return 	mat4
		(data[Rx] = data[Rx] - other.data[Rx], data[Ux] = data[Ux] - other.data[Ux], data[Fx] = data[Fx] - other.data[Fx], data[Px] = data[Px] - other.data[Px],
		data[Ry] = data[Ry] - other.data[Ry], data[Uy] = data[Uy] - other.data[Uy], data[Fy] = data[Fy] - other.data[Fy], data[Py] = data[Py] - other.data[Py],
		data[Rz] = data[Rz] - other.data[Rz], data[Uz] = data[Uz] - other.data[Uz], data[Fz] = data[Fz] - other.data[Fz], data[Pz] = data[Pz] - other.data[Pz],
		data[Rw] = data[Rw] - other.data[Rw], data[Uw] = data[Uw] - other.data[Uw], data[Fw] = data[Fw] - other.data[Fw], data[Pw] = data[Pw] - other.data[Pw]);

}
//operator -

mat4 mat4::operator*(const mat4 &other)
{
	return mat4(
		data[Rx] = data[Rx] * other.data[Rx] + data[Ux] * other.data[Ry] + data[Fx] * other.data[Rz] + data[Px] * other.data[Rw],
		data[Ux] = data[Rx] * other.data[Ux] + data[Ux] * other.data[Uy] + data[Fx] * other.data[Uz] + data[Px] * other.data[Uw],
		data[Fx] = data[Rx] * other.data[Fx] + data[Ux] * other.data[Fy] + data[Fx] * other.data[Fz] + data[Px] * other.data[Fw],
		data[Px] = data[Rx] * other.data[Px] + data[Ux] * other.data[Py] + data[Fx] * other.data[Pz] + data[Px] * other.data[Pw],

		data[Ry] = data[Ry] * other.data[Rx] + data[Uy] * other.data[Ry] + data[Fy] * other.data[Ry] + data[Py] * other.data[Rw],
		data[Uy] = data[Ry] * other.data[Ux] + data[Uy] * other.data[Uy] + data[Fy] * other.data[Uz] + data[Py] * other.data[Uw],
		data[Fy] = data[Ry] * other.data[Fx] + data[Uy] * other.data[Fy] + data[Fy] * other.data[Fz] + data[Py] * other.data[Fw],
		data[Py] = data[Ry] * other.data[Px] + data[Uy] * other.data[Py] + data[Fy] * other.data[Pz] + data[Py] * other.data[Pw],

		data[Rz] = data[Rz] * other.data[Rx] + data[Uz] * other.data[Ry] + data[Fz] * other.data[Ry] + data[Pz] * other.data[Rw],
		data[Uz] = data[Rz] * other.data[Ux] + data[Uz] * other.data[Uy] + data[Fz] * other.data[Uz] + data[Pz] * other.data[Uw],
		data[Fz] = data[Rz] * other.data[Fx] + data[Uz] * other.data[Fy] + data[Fz] * other.data[Fz] + data[Pz] * other.data[Fw],
		data[Pz] = data[Rz] * other.data[Px] + data[Uz] * other.data[Py] + data[Fz] * other.data[Pz] + data[Pz] * other.data[Pw],

		data[Rw] = data[Rw] * other.data[Rx] + data[Uw] * other.data[Ry] + data[Fw] * other.data[Ry] + data[Pw] * other.data[Rw],
		data[Uw] = data[Rw] * other.data[Ux] + data[Uw] * other.data[Uy] + data[Fw] * other.data[Uz] + data[Pw] * other.data[Uw],
		data[Fw] = data[Rw] * other.data[Fx] + data[Uw] * other.data[Fy] + data[Fw] * other.data[Fz] + data[Pw] * other.data[Fw],
		data[Pw] = data[Rw] * other.data[Px] + data[Uw] * other.data[Py] + data[Fw] * other.data[Pz] + data[Pw] * other.data[Pw]);

}
//operator *(mat4)

mat4 mat4::operator-()
{

	return mat4(
		-data[Rx], -data[Ux], -data[Fx], -data[Px],
		-data[Ry], -data[Uy], -data[Fy], -data[Py],
		-data[Rz], -data[Uz], -data[Fz], -data[Pz],
		-data[Rw], -data[Uw], -data[Fw], -data[Pw]);

}
//unary