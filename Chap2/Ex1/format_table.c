#include <stdio.h>
int main(){
	
	// --- Du lieu mau ---
	int stt1 = 1, stt2 = 2, stt3 = 15;
	int ma_sp1 = 0x1A2B, ma_sp2 = 0xFF, ma_sp3 = 0x1234ABCD;
	double gia_tien1 = 1250.5, gia_tien2 = 99.99, gia_tien3 = 243.122;
	
	
   	 printf("+-----+------------+--------------+\n");
   	 printf("| %-3s | %-10s | %-12s |\n", "STT", "Ma SP", "Gia tien");
    	 printf("+-----+------------+--------------+\n");		

	 printf("| %03d | %-10X | %12.2f |\n", stt1, ma_sp1, gia_tien1);
    	 printf("| %03d | %-#10X | %12.2f |\n", stt2, ma_sp2, gia_tien2);
    	 printf("| %03d | %-#10X | %12.2f |\n", stt3, ma_sp3, gia_tien3);
 	 printf("+-----+------------+--------------+\n");

         return 0;
}
