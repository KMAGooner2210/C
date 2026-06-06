#include <stdio.h>

int get_next_id(void){
	static int current_id = 1000;
	current_id++;
	return current_id;
}

void call_tracker(void){
	static int count = 0;
	count++;
	printf("Ham 'call_tracker' duoc goi [%d] lan\n", count);
}

int main(){
	printf("Yeu cau cap ID lan 1: %d\n", get_next_id());
	printf("Yeu cau cap ID lan 2: %d\n", get_next_id());
	printf("Yeu cau cap ID lan 3: %d\n", get_next_id());
	
	call_tracker();
	call_tracker();
	call_tracker();
	
	return 0;
}
