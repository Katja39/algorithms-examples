#include <iostream>;
#include "exercise1_root.h";
#include "exercise2_primes.h";
#include "exercise3_pi.h";
//#include "integral.h";
//#include "linearRegression.h";
//#include "differential.h";
//#include "linearSystemOfEquations.h";
//#include "linearSystemOfEquations2.h";

int main() {
	int n;
	int e=0;

	while (e == 0) {
	std::cout << "Choose algorithm:\n"
			  <<"1: Root\n"
			  <<"2: Primes\n"
			  <<"3: Pi\n"
		      <<"4: Integral\n" 
			  <<"5: Lineare Regression\n"
			  <<"6: Differentialgleichungen\n"
			  <<"7: Lineares Gleichungssystem\n"
			  <<"8: Lineares Gleichungssystem2\n"
			  <<"9: Exit"
			  <<std::endl;
	std::cin >> n;
	
	switch (n)
	{
	case 1:exercise1_root();
		break;
	case 2: exercise2_primes();
		break;
	case 3: exercise3_pi();
		break;
	//case 4: integral();
		break;
	//case 5:linearRegression();//TODO
		break;
	//case 6:differential();
		break;
	//case 7:linearSystemOfEquations();//TODO
		break;
	//case 8:linearSystemOfEquations2();//TODO
		break;
	case 9:e = 1;
		break;
	}
	}
	return 0;
}