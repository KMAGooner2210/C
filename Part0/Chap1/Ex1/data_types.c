#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(){
	//1. Kich thuoc kieu du lieu (LP64)
	printf("----KICH THUOC KIEU DU LIEU----\n");
	printf("Kich thuoc cua int 	: %zu bytes\n", sizeof(int));
	printf("Kich thuoc cua long	: %zu bytes\n", sizeof(long));
	printf("Kich thuoc cua long long: %zu bytes\n", sizeof(long long));
	printf("Kich thuoc cua void *   : %zu bytes\n", sizeof(void *));
	

	//2. Hien tuong tran so
	printf("----HIEN TUONG TRAN SO----\n");
	uint8_t a = 255;
	printf("Gia tri ban dau cua a:		%u\n", a);
	
	a = a + 1;
	printf("Gia tri cua a luc sau:	%u\n\n", a);
	
	//3. Gioi han so hoc
	printf("----GIOI HAN SO HOC----");
	printf("Max cua int (INT_MAX):		%d\n", 	INT_MAX);
	printf("Max cua uint32_t (UINT32_MAX):  %u\n", 	UINT32_MAX);
	return 0;
}
