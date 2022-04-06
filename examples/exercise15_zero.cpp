#include <iostream>;

using namespace std;
#include <math.h> 

double function(double x) {
	return sin(x) - 0.5 * x;
}

void Zero() {
	//zero of a function

	double xOld=3;
	double xCurrent=1;
	double xNew=1;
	double epsilon=0.01;
	int round = 0;

	while (abs(xNew - xOld) >= epsilon){
		round++;
		xNew = xCurrent - (xCurrent - xOld) / (function(xCurrent)- function(xOld))* function(xCurrent);
		xOld = xCurrent;
		xCurrent = xNew;
	}
	cout << xNew<<"\nAfter "<<round<<" rounds" << "\n\n";
}