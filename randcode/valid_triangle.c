// Take input of 3 numbers, return true or false if input 
// is capable of making a tringle

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int valid_triangle(float a, float b, float c);
float display_area(float a, float b, float c);

int main(int argc, char *argv[])
{
	
	float a;
	float b;
	float c;

	// if 3 arguments given, assigns them to a, b, c and converts them to floats
	if (argc == 4) {

		a = atof(argv[1]); 
		b = atof(argv[2]);
		c = atof(argv[3]);
		printf("%f, %f, %f\n", a, b, c);
	} else {
		// if 3 args not given, returns an error and exits
		printf("Input requires three sides\n");
		exit(1);
	}
	// If the three sides make a valid triangle, prints 'true' and the triangle's area
	if (valid_triangle(a, b, c)) {
		float area = display_area(a, b, c);
		printf("true\n");
		printf("Area of this triangle = %.5f\n", area);

	} else {
		printf("false\n");
	}
	return 0;
}

int valid_triangle(float a, float b, float c)
{
	// checks triangle sides are greater than 0
	if (a <= 0 || b <= 0 || c <= 0) {
		return 0;
	}
	// checks that each side is longer than the addition of the other sides
	// this is a prerequisite for being a triangle
	if (a + b <= c || a + c <= b || b + c <= a) {
		return 0;
	}
	return 1;
}

float display_area(float a, float b, float c)
{
	// Uses Heron's formula to determine area of the triangle
	float s = (a + b + c) / 2; // find semi-perimeter of triangle
	float area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}


