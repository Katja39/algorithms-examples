#include <iostream>;

void exercise2_primes() {
	int maxNumber; //max Number

	std::cout << "Enter the maximum limit of the prime number ";
	std::cin >> maxNumber;
	int *prim = new int[maxNumber];

	for (int i = 0; i < maxNumber; i++)
	{
		prim[i] = i;
	}

	for (int i = 2; i < sqrt(maxNumber); i++)
	{
		for (int k = 2; k < (maxNumber/i)+1; k++)
		{
			if(i*k<maxNumber){
			prim[i * k] = -1;
			}
		}
	}
	
	std::cout << "All primes up to "<<maxNumber<<" :\n";
	for (int i = 2; i < maxNumber; i++)
	{
		if(prim[i]!=-1){
		std::cout << prim[i]<<" ";
		}
	}
	std::cout << "\n";
}