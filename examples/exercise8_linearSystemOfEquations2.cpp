#include <iostream>;


using namespace std;

void exercise8_linearSystemOfEquations2() {
	//Jacobi method
	float array[3][3] = { {3.0f,1.0f,0.0f},{1.0f,3.0f,1.0f},{0.0f,1.0f,3.0f} };

	float array2[3] = { 1.0f,5.0f,7.0f };//b
	float x[3] = { 0.0f,0.0f,0.0f };//x
	float xOld[3] = { 0.0f };

	int round = 1;
	float error = 1.0;
	float sum=0.0f;
	float epsilon=0.01f;

	int size=3;

	cout << "Jacobi:"<<endl;

	while(error>epsilon) {
		error = 0;
		cout << round<<".round: ";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i != j) {
					sum += array[i][j] * xOld[j];
				}
			}
			x[i] = 1 / array[i][i] * (array2[i] - sum);
			sum = 0;
			std::cout << "x" << i+1 << "=" << x[i] << ", ";
		}
		std::cout << "\n";
		for (int i = 0; i < size; i++)
		{
			error+=abs(xOld[i]-x[i]);
			xOld[i] = x[i];
		}
		round++;
	}
	
	cout << "\n\n";

	cout << "Gauss-Seidel:" << endl;

	//Gauss-Seidel method


	float b[3] = { 1.0f,5.0f,7.0f };//b
	float x1[3] = { 0.0f,0.0f,0.0f };//x

	round = 1;
	error = 1;
	sum = 0.0f;
	epsilon = 0.01f;

	while (error > epsilon) {
		error = 0.0;
		std::cout << round << ".round: ";

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i != j) {
					sum += array[i][j] * x1[j];
				}
			}
			x1[i] = 1 / array[i][i] * (b[i] - sum);//overwrite x
			std::cout << "x" << i + 1 << "=" << x1[i] << ", ";
			sum = 0;
		}
		std::cout << "\n";
		for (int i = 0; i < size; i++)
		{
			error += abs((x1[i] - xOld[i])/x1[i]);
			xOld[i] = x1[i];
		}
		round++;
	}
	cout << "\n\n";
}


