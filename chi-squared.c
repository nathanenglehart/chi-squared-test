/* Nathan Englehart, (Summer, 2022) */

#include <stdio.h>
#include <math.h>

const int length = 3;
const int width = 3;

double chi_squared_test(double cross_tabs[length][width]) {

	/* Returns chi-squared value using given inputs. */

	double chi_squared = 0;

	for(int i = 0; i < length-1; i++)
	{
		for(int j = 0; j < width-1; j++)
		{
			double e = cross_tabs[i][width-1] * (cross_tabs[length-1][j] / cross_tabs[length-1][width-1]);
			chi_squared += (pow(cross_tabs[i][j] - e, 2)) / e;
		}
	}

	return chi_squared;
}

int main() {

	double cross_tabs [3][3] = {
		{163, 101, 264},
		{309, 395, 704},
		{472, 496, 968}
	};

	double chi_squared = chi_squared_test(cross_tabs);

	printf("chi_squared = %f.\n",chi_squared);
	printf("df = %d.\n",(length - 2)* (width - 2));	

	return 0;
}
