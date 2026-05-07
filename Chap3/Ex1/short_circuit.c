#include<stdio.h>

int is_even(const int *ptr){
	if(ptr != NULL && *ptr % 2 == 0){
		return 1;
	}
	return 0;
}

int main(){
	int num = 4;
	int *null_ptr = NULL;
	
	//Lan 1: Truyen con tro hop le
	printf("Kiem tra voi con tro hop le (num = 4):\n");
	if(is_even(&num)){
		printf("La so chan.\n\n");
	}else{
		printf("Khong phai la so chan.\n\n");
	}

	//Lan 2: Truyen con tro NULL
	printf("Kiem tra voi con tro NULL...\n");
	if(is_even(null_ptr)){
		printf("La so chan.\n");
	}else{
		printf("Khong phai la so chan (hoac do con tro bi NULL).\n");
	}
	printf("\nChuong trinh khong bi sap.\n");
	return 0;
}
