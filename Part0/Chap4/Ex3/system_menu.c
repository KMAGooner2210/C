#include <stdio.h>
#include <stdlib.h>

void clear_stdin_buffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF){}
}

void print_menu(){
	printf("\n====================\n");
	printf("HE THONG GIAM SAT LINUX\n");
	printf("1. Hien thi thong tin phien ban\n");
	printf("2. Liet ke tep tin thu muc hientai\n");
	printf("3. Thoat\n");
	printf("----------------------\n");
	printf("Chon chuc nang: ");
}

int main(){
	int choice = 0;
	do {
		print_menu();
		int scan_result = scanf("%d", &choice);
		clear_stdin_buffer();
		
		if(scan_result != 1){
			printf("\n[LOI] Nhap lai!\n");
			choice = 0;
			continue;
		}
		switch(choice){
		case 1:
			printf("\n---Linux version---\n");
			system("uname -a");
			break;
		case 2:
			printf("\n--- File list ---\n");
			system("ls -l");
			break;
		case 3:
			printf("\nEND!\n");
			break;
		default:
			printf("\n[LOI] Chuc nang %d khong hop le, nhap lai!\n", choice);
			break;
		}
	}while (choice != 3);
	return 0;
}
