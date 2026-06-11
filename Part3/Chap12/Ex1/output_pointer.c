#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool create_array(int **arr_ptr, size_t size){
	if(arr_ptr == NULL){
		return false;
	}
	
	*arr_ptr = (int*)malloc(sizeof(int));
	
	if(*arr_ptr == NULL){
		return false;
	}
	
	for(size_t i = 0; i < size; i++){
		(*arr_ptr)[i] = 0;
	}
	return true;
}

int main(){
	int *my_array = NULL;
	size_t size = 10;
	printf("----THAO TAC DOUBLE POINTER----\n\n");
	printf("Truoc khi goi ham, my_array = %p (NULL)\n", (void *)my_array);
	
	if(create_array(&my_array, size)){
		printf("Cap phat thanh cong!\n");
		printf("Sau khi goi ham, my_array = %p (Dia chi hop le tren HEAP)\n\n", (void *)my_array);
		printf("Cac phan tu trong mang: ");
		for(size_t i = 0; i < size; i++){
			printf("%d ", my_array[i]);
		}
		printf("\n\n");
		free(my_array);
		my_array = NULL;
		printf("Da giai phong bo nho HEAP.\n");
	}else{
		printf("Cap phat that bai!\n");
	}
	return 0;
}
