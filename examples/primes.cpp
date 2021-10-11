#include <iostream>;

void primes() {
	int n; //max Number

	std::cout << "Enter the Maximum limit of the prime number ";
	std::cin >> n;
	int *prim = new int[n];

	for (int i = 0; i < n; i++)
	{
		prim[i] = i;
	}

	for (int i = 2; i < sqrt(n); i++)
	{
		for (int k = 2; k < (n/i)+1; k++)
		{
			if(i*k<n){
			prim[i * k] = -1;
			}
		}
	}
	
	std::cout << "All primes up to "<<n<<" :\n";
	for (int i = 2; i < n; i++)
	{
		if(prim[i]!=-1){
		std::cout << prim[i]<<" ";
		}
	}
	std::cout << "\n";
}