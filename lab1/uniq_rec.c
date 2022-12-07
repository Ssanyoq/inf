#include <stdio.h>

int is_there(int num, int dig) {
	while (num > 0) {
		if (num % 10 == dig) {
			return 1;
		}
		num = num / 10;
	}
	return 0;
}

int get_unique(int num) {
	if (num < 10) {
		return num;
	}
	int cur_dig = num % 10;
	num = get_unique(num / 10);
	if (!is_there(num, cur_dig)) {
		num = num * 10 + cur_dig;
	}
	return num;
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
