#include <iostream>;

using namespace std;

void exercise9_nonlinearOptimization() {

	cout << "Gradient descent for f(x,y)=x^2+y^2\n";

	double x[2] = { 0, 0 };
	double xOld[2] = { 1,1 };
	double d[2] = { -2, -2 };

	double s = 0.3;
	int size=1;

	int i=0;
	double h = 0.0001;
	bool run = true;
	int n = 0;

	double epsilon = 0.01;

	do {
		n++;
		cout << "Round " << n << ":";

		for (int j = 0; j <= size; j++)
		{
		for (int i = 0; i <= size; i++)
		{
			x[i] += xOld[i] + s * (d[i] * xOld[i]);
		}
		if (abs(xOld[j] - x[j]) < epsilon) {
			run=false;
		}
		xOld[j] = x[j];
		x[j] = 0;
		}
		cout << " "<< xOld[0]<<"; "<< xOld[0]<<endl;
	} while (run);
		

	//cout << "\nDownhillSimplex for f(x,y)=x^2+y^2\n";

	// 1) Determine indices s, a, b
	double A[2] = { 1,1 };		// 4
	double B[2] = { 1,2 };		// 5
	double C[2] = { 3,1 };		// 10

	double xS = 10; //worst point
	double xA = 5; 
	double xB = 4; //best point

	size = 3;
	double e=0;
	int beta=2;
	double k=0;
	epsilon = 0.05;
	i = 0;

	// 2) Calculate the center of the best points
	double z = (1 / size) * (xA + xB);
	double r = z + (z - xS);
	

	// 3) Set up the new Simplex
	do{
	if (xB <= r <= xA) {
		xS = r;
	}
	if (r <= xB) {
		e = z + beta * (z - xS);
		if (e < r) {
			xS = e;
		}
		else {
			xS = r;
		}
	}
	if (r > xA) {
		if (r > xS) {
			k = z + 1 / 2 * (xS - z);
		}
		else {
			k = z + 1 / 2 * (z - xS);
		}
		if (k < xS) {
			xS = k;
		}
		else {
			xS = (xS+xB)/2;
			xA = (xA + xB)/2;
			xB = (xB + xB)/2;
		}
	}
	i++;
	} while (i<10);//TODO Abbruch
}