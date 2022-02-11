#include <iostream>
#include <vector>

using namespace std;

void exercise5_linearRegression(){

        vector<vector<double> > vector{ {1905,1915,1925,1935,1945,1955,1965,1975,1985,1995,2005},{7.7,8.0,7.9,8.1,8.3,8.1,7.9,8.3,8.5,9.0,9.2} };
        
        cout << "Number of values: " << vector[0].size() << endl;

        double meanX = 0;
        double meanY = 0;
        int n = vector[0].size();
        double sumXiYi = 0;
        double sumXiSqr = 0;
        double b = 0;
        double a = 0;

        for (int i = 0; i < n; i++)
        {
            meanX += vector[0][i];
        }
        meanX = meanX / n;

        for (int i = 0; i < n; i++)
        {
            meanY += vector[1][i];
        }
        meanY = meanY / n;

        cout << "Ox: " << meanX << endl;
        cout << "Oy: " << meanY << endl;

        for (int j = 0; j < n; j++)
        {
            sumXiYi += vector[0][j] * vector[1][j];
        }

        for (int j = 0; j < n; j++)
        {
            sumXiSqr += pow(vector[0][j], 2);
        }

        b = (sumXiYi - (n * meanX * meanY)) / (sumXiSqr - (n * pow(meanX, 2)));
        cout << "b: " << b << endl;

        a = meanY - b * meanX;
        cout << "a: " << a << endl;

        cout << "Regression line: y=" << a << "+" << b << "x\n\n";
}