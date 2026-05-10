#include <stdio.h>
int main(){
	int x = 50;
	int y = 10;
	int data[1000] = {0};
//	printf("---CHUA TOI UU---\n");
//	for(int i = 0; i < 1000; i++){
//		for(int j = 0; j < 1000; j++){
//			int complex_cal = (x * y) + (x / y) + 100;
//			data[i] += complex_cal * j;
//		}
//	}


	printf("\n---DA TOI UU---\n");
	int complex_calc_optimized = (x * y) + (x / y) + 100;
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			data[i] += complex_calc_optimized * j;
		}
	}	
	printf("Done");
	return 0;
}
