#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define T_ACC 15

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

double get_input_acc() {
	// assures that input is double
	double acc;
	char t;
	int out = scanf("%lf%c", &acc, &t);
	while (out != 2 || t != '\n' || acc <= 0) {
		if (out == -1) {
            printf("EOF detected, program ended\n");
            exit(1);
        }
        scanf("%*[^\n]");
		printf("Bad input, try again: ");
		out = scanf("%lf%c", &acc, &t);
	}
	return acc;
}

int get_fractional_amt(double acc) {
//	int amt = 0;
//	double comparing_num = 1.;
//	while (acc < comparing_num) { 
//		comparing_num *= 0.1;
//		amt++;
//	}	
//	return amt;
    int amt = T_ACC;
    double comparing_num = 0.000000000000001; // 15 знаков после запятой
    while (acc > comparing_num && comparing_num > 0) {
        comparing_num *= 10;
        amt--;
    }
    return amt;
}

double sin3(double x, double acc, int *steps) {
	double a = 9 ; 
    double x_sqr = x * x; 
	double mult = x_sqr * x / 6.0 * 3 / 4;
    double term = (a - 1) * mult; //
    double s = term;

	int i = 1;
	while (fabs(term) > acc) {
		i++;
		mult = mult * -x_sqr / (2 * i * (2 * i + 1));
		a = a * 9;
		term = (a - 1) * mult;
        s += term;
	}
	*steps = i;
	return s;	
}

int main() {
	double x;
	printf("Input any number x: ");
	x = get_input_x();
	
	printf("Input desired accuracy(any number greater than 0): ");
	double acc = get_input_acc();
	
	x = fmod(x, 2 * M_PI);
	int steps;
	double out = sin3(x, acc, &steps);
	int symb_amt = get_fractional_amt(acc);
	double math_out = pow(sin(x), 3);
	printf("func: %.*lf, n = %d; math.h: %.*lf", symb_amt,
		       	out, steps, symb_amt, math_out);
	return 0;
}
