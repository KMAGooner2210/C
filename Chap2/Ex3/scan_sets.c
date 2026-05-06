#include <stdio.h>
int main(){
   char text_part[50] = {0};
   char num_part[50] = {0};
   
   printf("--- SCAN SETS ---\n");
   printf("Nhap mot chuoi gom chu, khoang trang va so:\n>");
   scanf("%49[a-zA-Z] %49[0-9]", text_part, num_part);
   printf("\n--- KET QUA BOC TACH ---\n");
   printf("Phan chu cai : [%s]\n", text_part);
   printf("Phan chu so  : [%s]\n", num_part);

   return 0;
}
