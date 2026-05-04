#include <stdio.h>
int generate_id(){
	static int counter = 0;
	counter++;
	return counter;
}
int main(){
	printf("----KIEM TRA BIEN STATIC----\n");
	printf("Goi lan 1: ID = %d\n", generate_id());
	printf("Goi lan 2: ID = %d\n", generate_id());
	printf("Goi lan 3: ID = %d\n", generate_id());
	return 0;
}
