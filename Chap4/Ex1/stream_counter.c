#include <stdio.h>

int main(){
	int ch;
	int char_count = 0;
	int line_count = 0;
	
	printf("Nhap van ban (Nhan Enter xuong dong, nhan Ctrl + D de ket thuc):\n\n");
	while((ch = getchar()) != EOF){
		char_count++;
		if(ch == '\n'){
			line_count++;
		}
	}
	printf("\n\n--- KET QUA ---\n");
	printf("So dong (Lines): %d\n", line_count);
	printf("So ky tu (Chars_: %d\n", char_count);
	return 0;
}
