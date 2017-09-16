// Take input of 3 numbers, return true or false if input 
// is capable of making a tringle

#include <stdio.h>
#include <stdlib.h>

int valid_triangle(float a, float b, float c);

int main(int argc, char *argv[])
{
	
	float a;
	float b;
	float c;

	if (argc == 4) {

		a = atof(argv[1]); 
		b = atof(argv[2]);
		c = atof(argv[3]);
		printf("%f, %f, %f\n", a, b, c);
	} else {
		printf("Input requires three sides\n");
		exit(1);
	}
	if (valid_triangle(a, b, c)) {
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}

int valid_triangle(float a, float b, float c)
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return 0;
	}
	if (a + b <= c || a + c <= b || b + c <= a) {
		return 0;
	}
	return 1;
}
