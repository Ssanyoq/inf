#include <stdio.h>

int get_len(int num) {
	int len = 0;
	while (num != 0) {
		len = len + 1;
		num /= 10;
	}
	return len;
}

int is_there(int num, int dig) {
	while (num > 0) {
		if (num % 10 == dig) {
			return 1;
		}
		num = num / 10;
	}
	return 0;
}

int pow(int num, int exp) {
	if (exp == 0) {
		return 1;
	}
	int new_num = num;
	for (int i=1; i < exp; i++) {
		new_num *= num;
	}
	return new_num;
}

int main(){
	int num, new_num = 0;
	int sign = 0;

	scanf("%d", &num);
	if (num < 0){
		num = num * -1;
		sign = 1;
	}
	int num_len = get_len(num);
	while (num != 0) {
		int cur_dig = num / pow(10, num_len);
		if(!is_there(new_num, cur_dig)){
			new_num = new_num * 10 + cur_dig;
		}
		num = num % pow(10, num_len);
		num_len -= 1;
	}
	if (sign) {
		new_num = new_num * -1;
	}
	printf("%d\n", new_num);
	return 0;
}
	
