#include <stdio.h>

int system_pin = 1234;

void login(){
	printf("Dang kiem tra PIN: %d\n", system_pin);
	if (system_pin == 1234){
		printf("==> LOGIN SUCCESS! Quyen truy cap duoc cap.\n");
	}else{
		printf("==> LOGIN FAILED! Truy cap bi tu choi.\n");
	}
}
