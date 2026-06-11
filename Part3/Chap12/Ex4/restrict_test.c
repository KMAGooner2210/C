#include<stdio.h>
#include<stddef.h>

void add_array(int * restrict dest, const int * restrict src, size_t size){
	for(size_t i = 0; i < size; i++){
		*dest = *dest + src[i];
	}
}

int main(){
	int sum = 0;
	int data[] = {1, 2, 3, 4, 5};
	add_array(&sum, data, 5);
	printf("Ket qua: %d\n\n", sum);
	
	printf("Test Aliasing...\n");
	add_array(&data[0], &data[1], 3);
	printf("Data[0] sau khi aliasing: %d\n", data[0]);
	return 0;
}
