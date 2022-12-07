#include <stdio.h>

int is_there(int num, int dig) {
	while (num != 0) {
		if (num % 10 == dig) {
			return 1;
		}
		num = num / 10;
	}
	return 0;
}

int get_reversed(int num) {
	int reversed_num = 0;
	while (num > 0) {
		reversed_num = reversed_num * 10 + num % 10;
		num = num / 10;
	}
	return reversed_num;
}

int get_unique(int num) {
	num = get_reversed(num);
	int unique = 0;
	while (num > 0) {
		if (!is_there(unique, num % 10)) {
			unique = unique * 10 + num % 10;
		}
		num = num / 10;
	}
	return unique;
}

int main() {
	int num;
	int sign = 0;
	scanf("%d", &num);	
	if (num < 0) {
		num = num * -1;
		sign = 1;
	}

	int new_num = get_unique(num);

	if (sign) {
		new_num = new_num * -1;
	}

	printf("%d\n", new_num);
	return 0;
}
