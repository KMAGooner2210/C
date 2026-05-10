#include<stdio.h>
#include<string.h>

int main(){
	char str[] = "Linux C Programming";
	printf("--- DAO NGUOC CHUOI TAI CHO ---\n");
	printf("Chuoi ban dau: [%s]\n", str);
	for(int i = 0, j = strlen(str) - 1; i < j; i++, j--){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	printf("Chuoi luc sau: [%s]\n", str);
	return 0;
}
