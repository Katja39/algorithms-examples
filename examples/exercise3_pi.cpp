#include <iostream>

//test roundoff error using calculation of pi
void exercise3_pi() {
	int n = 2;
	long max_n = 536870912;
	double pi = 0.0;
	double s2n = 0.0;
	double s = 2.0;

	std::cout << "\nAlgorithm not stable: "<<std::endl;

	while (n <= max_n)
	{
		s2n = sqrt(2 - 2 * sqrt(1 - (pow(s, 2) / 4)));
		pi = n * s2n;

		std::cout << "n = " << n << ", s2n = " << s2n << " Pi = " << pi << std::endl;

		s = s2n;
		n += n;
	}

	std::cout << "\nAlgorithm stable: " << std::endl;

	pi = 0.0;
	n = 2;
	s2n = 0.0;
	s = 2;

	while (n <= max_n)
	{
		s2n = sqrt(pow(s,2) / (2 + 2 * sqrt(1 - (pow(s,2) / 4))));

		pi = n * s2n;
		std::cout << "n = " << n << ", s2n = " << s2n << ", Pi = " << pi << std::endl;

		n = n * 2;
		s = s2n;
	}
}