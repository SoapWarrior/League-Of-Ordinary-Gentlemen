#pragma once

float LERP(float data1, float data2, float u)
{


	return data1* (1.0f - u) + data2*u; //u represents the mid point value i.e data point 0 =5 data point 1=10, data point 0.5 = 7.5

}//end float



float Catmull(float data0, float data1, float data2, float data3, float u)
{
	return 0.5f*(
		u* u * u*(-data0+3.0f*data1 - 3.0f *data2+data3) + 
		u*u*(2.0f * data0 - 5.0f *data1 +4.0f *data2 - data3) + 
		u*(-data0 + data2) + 
		(2.0f * data1));

}

float Bezier(float data0, float data1, float data2, float data3, float u)
{
	return 0.5f*(
		u*u*u*(-data0 + 3.0f*data1 - 3.0f*data2 + data3) +
		u*u*(2.0f*data0 - 6.0f*data1 + 3.0f*data2) +
		u*(-3.0f*data0 + 3.0f*data1) +
		(data0 + 2.0f*data1));


}


bool Boundingbox(int x, int y, model* Other, int playerX, int playerY)
{
	if (((playerX + x) > Other->positionX) && (playerX < Other->positionX) &&
		((playerY + y) > Other->positionY) && (playerY< Other->positionY))
	{


		return (true);
	}
	return false;
}

//playerX,playerY is the origin for the model
//x and y is the additional size

//Other is the incoming box