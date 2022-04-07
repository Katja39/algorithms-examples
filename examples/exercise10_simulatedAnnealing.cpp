#include <iostream>;

void shuffleArray(int route[6]) {
	int start = rand() % 6;
	int end = rand() % 6;

	if (start == end)
		shuffleArray(route);
	else {
		int original[6];

		for (int i = 0; i < 6; i++)
			original[i] = route[i];

		if (start > end) {
			int holder = end;
			end = start;
			start = holder;
		}

		for (int i = 0; i <= (end - start); i++) {
			route[start + i] = original[end - i];
		}
	}
}

using namespace std;
void exercise10_simulatedAnnealing(){

	int A[6][6] = {
	9999, 3, 5, 6, 7, 4,
	3, 9999, 6, 1, 4, 9,
	5, 6, 9999, 4, 10, 8,
	6, 1, 4, 9999, 7, 3,
	7, 4, 10, 7, 9999, 5,
	4, 9, 8, 3, 5, 9999
	};

	double p = 0;			// Boltzmann distribution
	double t = 100;			// Current Temperature

	// Delta E = Current distance - best distance
	int AR[6] = { 0,1,2,3,4,5 };
	int BR[6] = { 0,1,2,3,4,5 };

	int AD = 0;
	int BD = 100;

	double deltaE = 0;

	double r = 0;
	double epsilon = 0.0001;

	srand((unsigned)time(NULL));

	int round = 1;

	for (int i = 0; i < 100; i++)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "Round: " << round << endl<<endl;

		cout << "Current route: ";
		for (int i = 0; i < 6; i++)
		{
			cout << AR[i] << ", ";
		}
		cout << endl;

		int total = 0;
		for (int i = 0; i < 6; i++)
		{
			int node = AR[i];
			int targetNode = i >= 5 ? AR[0] : AR[i + 1];

			AD += A[node][targetNode];
		}

		AD += A[AR[5]][AR[0]];

		cout << "Current distance: " << AD << endl;

		deltaE = abs(AD - BD) / t;
		cout << "DeltaE: " << deltaE << endl;

		p = exp(-deltaE);
		cout << "P: " << p << endl;

		r = ((double)rand() / (RAND_MAX));

		if (AD < BD||r<p)
		{
			for (int i = 0; i < 6; i++)
			{
				BR[i] = AR[i];
			}
			BD = AD;
		}

		cout << "Best route: ";
		for (int i = 0; i < 6; i++)
		{
			cout << BR[i] << ", ";
		}
		cout << endl;

		if (t <= epsilon)
		{
			return;
		}

		t = t / 2;
		cout << "T: " << t << endl;

		AD = 0;

		round++;

		shuffleArray(AR);
	}
}