#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include "Vector3.h"
#include "Vector4.h"


int main()
{
	vec2 myVector2(1, 2);
	vec2 otherVector2(1, 2);
	vec2 TransformedVector2(0, 0);
	mat4 myMatrix(1,0,0,10,0,1,0,0,0,0,1,0,0,0,0,1);

	TransformedVector2 = myVector2 + otherVector2;
	myMatrix.Translate(4, 2, 2,1);
	std::cout<<"hi,"<<myMatrix.data[Px];
	

}