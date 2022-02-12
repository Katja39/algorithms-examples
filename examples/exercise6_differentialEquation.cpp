#include <iostream>;

using namespace std;

void exercise6_differentialEquation() {
	//Euler Cauchy/Euler method for y(x)=2*y*x

	float y = 1.0f;
	float yNew = 1.0f;
	float x = 0.0f;
	float xNew = 0.0f;
	float m = 2.0f; //fixed value, because of 2 in y(x)=2*y*x

	float deltaX = 0.001;
	float gesucht = 4.0f;

	
	cout << "Enter deltaX: ";
	cin >> deltaX;
	cout << "\nInput value y(x)";
	cin >> gesucht;

	for (float i = 0.0; i < gesucht; i+=deltaX)
	{
		yNew = m * y * x * deltaX + y;
		y = yNew;
		xNew = x + deltaX;
		x = xNew;
	}
	cout <<"Euler method:\nRuns: "<<gesucht/deltaX << "\nx= " << x << "\ny=" << y<<"\n";

	//Runge-Kutta second-order
	 y = 1.0;
	 yNew = 1.0;
	 x = 0.0;
	 xNew = 0.0;

	 float k1i = 0.0f;
	 float k2i = 0.0f;
	 float deltaY=0.0f;

	 float s = deltaX;

	for (float i = 0.0; i < gesucht; i += s)
	{
		k1i = m * y * x;
		k2i = m * ((x + s) * (y + s * k1i));
		deltaY = s / 2 * (k1i + k2i);
		xNew = x + s;
		yNew = y + deltaY;
		x = xNew;
		y = yNew;
	}
	cout << "Runge Kutta second-order: \nRuns " << gesucht / s << "\nx = " << x << "\ny = " << y << "\n";

	//Runge-Kutta fourth-order

	y = 1.0;
	yNew = 1.0;
	x = 0.0;
	xNew = 0.0;

	k1i = 0.0;
	k2i = 0.0;
	float k3i = 0.0f;
	float k4i = 0.0f;
	deltaY = 0.0;

	for (float i = 0.0; i < gesucht; i += s)
	{
		k1i = m * y * x;
		k2i = m * ((x + s/2) * (y + s * k1i/2));
		k3i = m * ((x + s/2) * (y + s * k2i / 2));
		k4i = m * ((x + s) * (y + s * k3i));

		deltaY = s / 6 * (k1i + 2*k2i+2*k3i+k4i);
		xNew = x + s;
		yNew = y + deltaY;
		x = xNew;
		y = yNew;
	}
	cout << "Runge Kutta fourth-order: \nRuns " << gesucht / s << "\nx= " << x << "\ny=" << y << "\n\n";

}