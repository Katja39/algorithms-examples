#include <iostream>;
#include <cmath>

void exercise1_root() {
	int number; //positive number
	std::cout << "Positive Zahl: "<< std::endl;
	std::cin >> number;
	int wurzel;
	std::cout << "\nWurzel: " << std::endl;
	std::cin >> wurzel;

	if (number > 0 && wurzel>0) {
	double xNew = 10;
	double xOld = 1;

	double abbruch = 0.0001;

	while (abs(xOld - xNew) > abbruch) //abs = Betrag
	{
		xOld = xNew;
		xNew = ((wurzel - 1) * pow(xOld, wurzel) + number) / (wurzel * pow(xOld, wurzel - 1));
	}

	std::cout <<"\n" << wurzel << ". Wurzel von " << number << " = " << xNew <<"\n" << std::endl;
	}
	else {
		std::cout << "Falsche Eingabe";
	}

}