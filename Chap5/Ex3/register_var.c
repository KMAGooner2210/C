#include <stdio.h>

int main(){
	register int fast_counter = 100;
	int  *ptr = &fast_counter;
	printf("Dia chi cua bien thanh ghi la: %p\n", ptr);
	printf("Gia tri cua bien la: %d\n", fast_counter);
	return 0;
}

