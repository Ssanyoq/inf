#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int get_input_n() {
	// assures that input is int and > 0
	unsigned int n;
	char t;
	int out = scanf("%u%c", &n, &t);
	while (out != 2 || t != '\n') {
        if (out == -1) {
            printf("EOF detected, program exited\n");
            exit(1);
        }
		scanf("%*[^\n]");
		printf("Bad input, try again: ");
		out = scanf("%u%c", &n, &t);
	}
	return n;
}

double get_input_x() {
	// assures that input is double
	double x;
	char t;
	int out = scanf("%lf%c", &x, &t);
	while (out != 2 || t != '\n') {
        if (out == -1) {
            printf("EOF detected, program exited\n");
            exit(1);
        }
		scanf("%*[^\n]");
		printf("Bad input, try again: ");
		out = scanf("%lf%c", &x, &t);
	}
	return x;
}


double sin3(double x, int n) {
	double a = 9; 
    double x_sqr = x * x; 
	double mult = x_sqr * x / 6.0;
	double s = (a - 1) * mult;
   
	for (int i = 2; i <= n; ++i) {	
		mult = mult * -x_sqr / (2 * i * (2 * i + 1));
		a = a * 9;
		s += (a - 1) * mult;
	}
	s = s * 3 / 4;
	return s;
	
}

int main() {
	double x;
	printf("Input any number x: ");
	x = get_input_x();
	x = fmod(x, (2 * M_PI));
	printf("Input any integer number n that is greater than 0: ");
	int n = get_input_n();
	double out = sin3(x, n);
	double math_out = pow(sin(x), 3);
	printf("func: %.*lf; math.h: %.*lf", 15, out, 15, math_out);
	return 0;    
}
