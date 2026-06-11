#include <stdio.h>
#include <stdbool.h>

bool is_even(int n){
	return (n % 2 == 0);
}

bool is_positive(int n){
	return (n > 0);
}

bool is_prime(int n){
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}

void process_array(const int arr[], size_t size, bool (*check_func)(int)){
	if(check_func == NULL){
		printf("Loi: Con tro ham bi NULL!\n");
		return;
	}
	for(size_t i = 0; i < size; i++){
		if(check_func(arr[i])){
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

int main(){
	int data[] = {3, -5, 9, 8, 10};
	size_t size = sizeof(data)/sizeof(data[0]);
	printf("---CALLBACK VOI CON TRO HAM---");
	printf("\nMang du lieu goc: ");
	for(size_t i = 0; i < size; i++){
		printf("%d ", data[i]);
	}
	printf("\n\n");
	
	printf("Cac so chan trong mang:               ");
	process_array(data, size, is_even);
	printf("Cac so duong trong mang:              ");
	process_array(data, size, is_positive);
	printf("Cac so nguyen to trong mang:          ");
	process_array(data, size, is_prime);
	return 0;
}
