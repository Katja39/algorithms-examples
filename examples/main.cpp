#include <iostream>;
#include "root.h";
#include "primes.h";


int main() {
	int n;
	int e=0;

	while (e == 0) {
	std::cout << "Choose algorithm:\n"
			  <<"1: Root\n"
			  <<"2: Primes\n" 
		      <<"3: Exit" << std::endl;
	std::cin >> n;
	
	switch (n)
	{
	case 1:root();
		break;
	case 2: primes();
		break;
	case 3:e = 1;
		break;
	}
	}
	return 0;
}