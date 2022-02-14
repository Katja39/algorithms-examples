#include <iostream>;
#include "exercise1_root.h";
#include "exercise2_primes.h";
#include "exercise3_pi.h";
#include "exercise4_integral.h";
#include "exercise5_linearRegression.h";
#include "exercise6_differentialEquation.h";
#include "exercise7_linearSystemOfEquations.h";
#include "exercise8_linearSystemOfEquations2.h";

int main() {
	int n;
	int e=0;

	while (e == 0) {
	std::cout << "Choose algorithm:\n"
			  <<"1: Root (Herons method)\n"
			  <<"2: Primes (Sieve of Eratosthenes)\n"
			  <<"3: Pi (test roundoff error)\n"
		      <<"4: Integral\n" 
			  <<"5: Linear Regression\n"
			  <<"6: Differential Equation\n"
			  <<"7: Linear System of Equations (TODO, but correct result)\n"
			  <<"8: Linear System of Equations (Jacobi, Gauss-Seidel)\n"
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
	case 4: exercise4_integral();
		break;
	case 5:exercise5_linearRegression();
		break;
	case 6:exercise6_differentialEquation();
		break;
	case 7:exercise7_linearSystemOfEquations();//TODO
		break;
	case 8:exercise8_linearSystemOfEquations2();
		break;
	case 9:e = 1;
		break;
	}
	}
	return 0;
}