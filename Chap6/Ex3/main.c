#include <stdio.h>

extern int system_pin;
extern void login();

int main(){
	printf("--- HE THONG CHUA BAO MAT ---\n");
	printf("Ma PIN doc duoc: %d\n", system_pin);
	system_pin = 9999;
	printf("Can thiep trai phep! PIN da bi doi thanh: %d\n\n", system_pin);
	login();
	return 0;
}
