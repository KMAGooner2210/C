#include <stdio.h>

#define SQUARE_MACRO(x) ((x) * (x))

static inline int square_inline(int x){
	return x * x;
}

int main(){
	int a = 5;
	int b = 5;
	
	int res1 = SQUARE_MACRO(a++);
	printf("[Macro] Ket qua SQUARE_MACRO(a++) = %d\n", res1);
	printf("[Macro] Gia tri cua a sau do = %d\n\n", a);

	int res2 = square_inline(b++);
	printf("[Inline] Ket qua cua square_inline(b++) = %d\n", res2);
	printf("[Inline] Gia tri cua b sau do = %d\n", b);
	return 0;
}
