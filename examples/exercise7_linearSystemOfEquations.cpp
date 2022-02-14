#include <iostream>;

void exercise7_linearSystemOfEquations() {

	int L[3][3]= { {1,0,0},{0,1,0},{0,0,1} };;
	int A[3][3]={ {3,2,1},{6,6,3},{9,10,6} };
	int b[3]= {2,3,5};
	int numberOfRows = 3;

	//1) LR-decomposition
	for (int round = 0; round < numberOfRows; round++)//round
	{
		for (int j = round+1; j < numberOfRows;j++)//Column
		{
			L[j][round] = A[j][round] / A[round][round];
			for (int k = 0; k < numberOfRows; k++)//Row
			{
				A[j][k] = A[j][k] - L[j][round] * A[round][k];

			}

		}
	}
	std::cout << "Left matrix";
	for (int m = 0; m < 3; m++)
	{
		std::cout << "\n";
		for (int n = 0; n < 3; n++)
		{
			std::cout<<L[m][n];

		}
	}
	std::cout << "\nRight matrix";
	for (int m = 0; m < 3; m++)
	{
		std::cout << "\n";
		for (int n = 0; n < 3; n++)
		{
			std::cout << A[m][n];

		}
	}

	//2) forward substitution
	//L*y=2
	int y1 = 0;
	int y2 = 0;
	int y3 = 0;
	int temp=1;

	
	for (int j = 0; j < numberOfRows; j++)
	{
		for (int k = 0; k < numberOfRows; k++)
		{
			if(L[j][k]!=0){
			 temp = temp*L[j][k];
			}
		}
		if (j==0) {
			y1 = b[j];
		}
		else if (j == 1) {
			y2 = b[j] - temp * y1;
		}
		else {
			y3 = b[j] - temp - y1 * y2;
		}
		temp = 1;
	}
	std::cout << "\ny1 = " << y1 << "\ny2 = " << y2 << "\ny3 = " << y3;
	
	//2) backward substitution //TODO
	int y[3] = {y1,y2,y3};
	//A*X=y
	int x1 = 0;
	int x2 = 0;
	int x3 = 0;
	int LNew[3][3];
	int test=0;
	
	for (int j = 2; j >= 0; j--)//2,1,0
	{
		for (int k = 0; k < 3; k++)//0,1,2
		{
			LNew[test][k] = L[j][k];
		}
		test++;
	}
	
	for (int j = numberOfRows-1; j >= 0; j--)
	{
		for (int k = numberOfRows-1; k >= 0; k--)
		{
			
			if (L[j][k] != 0) {
				
				temp = temp * L[j][k];
			}

		}
		if (j == 2) {
			x3 = y[j];
		}
		else if (j == 1) {
			x2 = -((x3-y[j])/temp);
		}
		else if (j == 0) {
			x1 = -((y[j]*x2+1*x3-2)/3);
		}
		temp = 1;
	}

	std::cout << "\nx1 = " << x1 << "\nx2 = " << x2 << "\nx3 = " << x3<<std::endl;
}