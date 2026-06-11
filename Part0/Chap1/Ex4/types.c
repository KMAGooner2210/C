#include <stdio.h>
void ep_kieu(){
	printf("----EP KIEU----\n");
	int a = -1;
	unsigned int b = 1;

	printf("Gia tri cua a (int) = %d\n", a);
	printf("Gia tri cua b (unsigned int) = %u\n", b);
	
	if(a < b){
	  printf("Ket qua so sanh: a < b\n\n");
	}else{
	  printf("Ket qua so sanh: a >= b\n\n");
	}
}
void short_circuit(int x){
	printf("--- x = %d ---\n", x);
	if (x != 0 && printf(" -> Ve phai cua && duoc thuc thi!\n")){

	}else{
	   printf("-> Toan bo dieu kien && la sai\n");
	}
}

int main(){
	ep_kieu();
	short_circuit(0);
	short_circuit(1);
	return 0;
}


