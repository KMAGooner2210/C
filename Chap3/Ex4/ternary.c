#include <stdio.h>

int main(){
	int a = 45;
	int b = 82;
	int c = 12;
	printf("--- TOAN TU 3 NGOI ---\n\n");
	printf("Ba so hien tai: a = %d, b = %d, c = %d\n", a, b, c);
	
	int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

	printf("So lon nhat la: %d\n\n", max);
	printf("Kiem tra bien a: So %d la so %s\n", a, (a >= 0) ? "Duong" : "Am");
	
	a = -15;
	printf("Kiem tra bien a: So %d la so %s\n", a, (a >= 0) ? "Duong" : "Am");
	return 0;
}
