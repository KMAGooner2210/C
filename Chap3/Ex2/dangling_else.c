#include<stdio.h>

int main(){
	int is_admin = 1;
	int is_active = 1;
	
	printf("--- KIEM TRA QUYEN DANG NHAP ---\n");
	
//	if(is_admin == 1)
//		if(is_active == 1)
//			printf("Welcome Admin!\n");
//	else
//		printf("You're not Admin!\n");

	if(is_admin == 1){
		if(is_active == 1){
			printf("Welcome Admin!\n");
		}
	}
	else {
		printf("You're not Admin!\n");
	}	
	return 0;
}
