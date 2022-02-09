#include <iostream>;

//Sieve of Eratosthenes
void exercise2_primes() {
	int maxNumber;

	std::cout << "Enter the maximum limit of the prime number ";
	std::cin >> maxNumber;
	int *prime = new int[maxNumber];

	for (int i = 0; i < maxNumber; i++)
	{
		prime[i] = i;
	}

	for (int i = 2; i < sqrt(maxNumber); i++)
	{
		for (int k = 2; k < (maxNumber/i)+1; k++)
		{
			if(i*k<maxNumber){
			prime[i * k] = -1;
			}
		}
	}
	
	std::cout << "All primes up to "<<maxNumber<<" :\n";
	for (int i = 2; i < maxNumber; i++)
	{
		if(prime[i]!=-1){
		std::cout << prime[i]<<" ";
		}
	}
	std::cout << "\n";
}