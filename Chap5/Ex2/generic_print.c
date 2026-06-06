#include<stdio.h>

void print_any(void *data, char type_code){
	printf("Gia tri la: ");
	switch(type_code){
		case 'i':
			printf("%d\n", *((int *)data));
			break;
		case 'f':
			printf("%f\n", *((float *)data));
			break;
		case 'c':
			printf("%c\n", *((char *)data));
			break;

	default:
		printf("Kieu du lieu khong hop le!\n");
		break;		
	}
}

int main(){
	int my_int = 32;
	float my_float = 3.14159;
	char my_char = 'A';

	printf("Goi ham kieu INT: ");
	print_any(&my_int, 'i');

	printf("Goi ham kieu FLOAT: ");
	print_any(&my_float, 'f');

	printf("Goi ham kieu CHAR: ");
	print_any(&my_char, 'c');
	return 0;
}
