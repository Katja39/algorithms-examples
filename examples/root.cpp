#include <iostream>;

void root() {

	int a; //positive number
	std::cout << "Positive Zahl: "<< std::endl;
	std::cin >> a;
	int n;
	std::cout << "\nWurzel: " << std::endl;
	std::cin >> n;

	if (a > 0 && n>0) {
	double xNew = 10;
	double xOld = 1;

	double abbruch = 0.00001;

	while (abs(xOld - xNew) > abbruch) //abs = Betrag
	{
		xOld = xNew;
		xNew = ((n - 1) * pow(xOld, n) + a) / (n * pow(xOld, n - 1)); //pow = potenzieren
	}

	std::cout <<"\n" << n << ". Wurzel von " << a << " = " << xNew <<"\n" << std::endl;
	}
	else {
		std::cout << "Falsche Eingabe";
	}

}