#include <stdio.h>
#include <stddef.h>
// void process_array(int arr[]){
//	printf("Sizeof cua bien 'arr' nhan duoc trong ham: %zu bytes\n", sizeof(arr));
// }

void process_array(const int *arr, size_t size){
	printf("Kich thuoc mang nhan duoc: %zu phan tu\n", size);
	printf("Cac phan tu trong mang la: ");
	for(size_t i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main(){
	int my_data[10] = {1, 2, 3, 4, 5};
	size_t size = sizeof(my_data) / sizeof(my_data[0]);
	printf("Sizeof cua mang 'my_data' trong main: %zu bytes\n\n", sizeof(my_data));
	printf("So phan tu tinh duoc tu main : %zu phan tu\n\n", size);
	process_array(my_data, size);
//	process_array(my_data);
	return 0;
}
