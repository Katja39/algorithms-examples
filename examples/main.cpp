#include <iostream>;
#include "exercise1_root.h";
#include "exercise2_primes.h";
#include "exercise3_pi.h";
#include "exercise4_integral.h";
#include "exercise5_linearRegression.h";
#include "exercise6_differentialEquation.h";
#include "exercise7_linearSystemOfEquations.h";
#include "exercise8_linearSystemOfEquations2.h";
#include "exercise9_nonlinearOptimization.h";
#include "exercise15_zero.h";

int main() {
	int n;
	int e=0;

	while (e == 0) {
	std::cout << "----------------------\n"
			  << "Choose algorithm:\n"
			  <<"1: Root (Herons method)\n"
			  <<"2: Primes (Sieve of Eratosthenes)\n"
			  <<"3: Pi (test roundoff error)\n"
		      <<"4: Integral\n" 
			  <<"5: Linear Regression\n"
			  <<"6: Differential Equation\n"
			  <<"7: Linear System of Equations (TODO, but correct result)\n"
			  <<"8: Linear System of Equations (Jacobi, Gauss-Seidel)\n"
			  <<"9: Nonlinear Optimization (DownhillSimplex,Gradient descent)\n"
			  <<"10: TODO\n"
			  <<"11: TODO\n"
			  <<"12: TODO\n"
			  <<"13: TODO\n"
			  <<"14: TODO\n"
			  <<"15: Zero of a function\n"
			  <<"16: Exit\n"
			  << "----------------------"
			  <<std::endl;
	std::cin >> n;
	std::cout << "\n";

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
	case 9:exercise9_nonlinearOptimization();
		break;
	case 15: Zero();
		break;
	case 16: e = 1;
	}
	}
	return 0;
}