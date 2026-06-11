#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void handle_start(void){
	printf("[SYSTEM] Dang khoi dong he thong...[OK]\n");
}

void handle_stop(void){
	printf("[SYSTEM] Dang tat he thong an...[OK]\n");
}
void handle_restart(void){
	printf("[SYSTEM] Dang khoi dong lai he thong...[OK]\n");
}

typedef struct {
	const char *command_name;
	void (*handler_func)(void);
} Command;

int main(){
	
	Command dispatch_table[] = {
		{"START", handle_start},
		{"STOP", handle_stop},
		{"RESTART", handle_restart}
	};
	
	size_t table_size = sizeof(dispatch_table) / sizeof(dispatch_table[0]);
	char input[50] = {0};
	printf("====BANG LENH====\n\n");
	printf("Cac lenh hop le: [start][stop][restart]!\n");
	printf("Nhap lenh: ");

	if(fgets(input, sizeof(input), stdin)){
		input[strcspn(input, "\n")] = '\0';
		bool is_found = false;
		for(size_t i = 0; i < table_size; i++){
			if(strcmp(input, dispatch_table[i].command_name) == 0){
				dispatch_table[i].handler_func();
				is_found = true;
				break;
			}
		}
		
		if(!is_found){
			printf("[LOI] Lenh '%s' khong ton tai trong he thong!\n", input);
		}
	}
	return 0;
}
