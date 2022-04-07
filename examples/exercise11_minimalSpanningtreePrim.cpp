#include <iostream>;

using namespace std;
void exercise11_minimalSpanningtree() {
	int nodes[6][6] = {
		{1000, 3,1000,6,1000,3},
		{3,1000,2,5,5,1},
		{1000,2,1000,1,9,6},
		{6,5,1,1000,2,4},
		{1000,5,9,2,1000,1},
		{3,1,6,4,1,1000}
	};

	int spanningTree[6] = { 0 };

	// Choose any node of G as starting graph R
	spanningTree[0] = 1;	// A
	cout << "Best Route:" << endl;
	std::cout << "0";

	// As long as R doesn't yet contain all nodes of G
	for (int r = 0; r < 5; r++)
	{
		int bestRoute = 1000;
		int tmp;
		for (int i = 0; i < 6; i++)
		{
			if (spanningTree[i] == 1)
			{
				for (int j = 0; j < 6; j++)
				{
					if (nodes[i][j] < bestRoute && spanningTree[j] == 0)
					{
						tmp = j;
						bestRoute = nodes[i][j];
					}
				}
			}
		}
		cout <<tmp;
		spanningTree[tmp] = 1;
	}
	cout << endl;
}