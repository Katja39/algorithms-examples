#include <iostream>;
#include <cmath>

//Herons method
void exercise1_root() {

	int number; //positive number
	std::cout << "Positive number: "<< std::endl;
	std::cin >> number;
	int root;
	std::cout << "\Root: " << std::endl;
	std::cin >> root;

	if (number>0 && root>0) {
	double xNew = 10;
	double xOld = 1;

	double stop = 0.0001;

	while (abs(xOld - xNew) > stop)
	{
		xOld = xNew;
		xNew = ((root - 1.0) * pow(xOld, root) + number) / (root * pow(xOld, root - 1));
	}

	std::cout <<"\n" << root << ". root of " << number << " = " << xNew <<"\n" << std::endl;
	}
	else {
		std::cout << "Incorrect input";
	}

}