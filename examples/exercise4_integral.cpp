#include <cmath>
#include <iostream>;

void exercise4_integral() {
	//1. Rectangle method

	std::cout << "Rectangle method for f(x)=x^2" << "\n";
	float stripWidth=0.5f;
	float start=0.0;
	float end=0.0;
	float width=2;
	float lowerSum = 0.0f;
	float upperSum = 0.0f;
	float mean=0.0f;

	std::cout << "Input strip width (the smaller, the more accurate result)\n";
	std::cin >> stripWidth;
	std::cout << "Start\n";
	std::cin >> start;
	std::cout << "End\n";
	std::cin >> end;
	width = end - start;
	std::cout << "Number of strips "<<width/stripWidth<<" \n";

	for (float i = 0; i < width; i+=stripWidth)
	{
		lowerSum += pow(i, 2)*stripWidth;
		upperSum += pow(i+stripWidth,2);
	}
	upperSum = upperSum * stripWidth;
	std::cout <<"Lower sum: " << lowerSum << "\n";
	std::cout << "Upper sum: " << upperSum << "\n";
	mean = (lowerSum + upperSum) / 2;
	std::cout << "Mean value (result): " << mean << "\n\n";

	//2. Trapezoidal method
	float result = 0.0f;

	std::cout << "Trapezoidal method for f(x)=x^2" << "\n";

	for (float i = 0; i < width; i += stripWidth)
	{
		result += pow(i, 2) + pow(i + stripWidth, 2);
	}
	result *= stripWidth / 2;
	std::cout << "result: " << result << "\n\n";

	//3. Simpson's rule
	result = 0.0;
	float i = start;
	std::cout << "Simpson's rule for f(x)=x^2" << "\n";

	result += pow(start, 2);

	do {
		i += stripWidth;
		result += 4 * pow(i, 2);
		if (end-stripWidth >= i) {
			i += stripWidth;
			result += 2 * pow(i, 2);
		}
		else {
			break;
		}
	} while (end - stripWidth >= i);
	result+= pow(end, 2);

	result *= stripWidth / 3;
	std::cout << "result: " << result<<"\n\n";
}