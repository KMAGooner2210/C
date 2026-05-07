#include <stdio.h>

int get_days(int month, int year){
	int days = 0;
	switch(month){
		case 1: [[fallthrough]];
		case 3: [[fallthrough]];
		case 5: [[fallthrough]];
		case 7:	[[fallthrough]];
		case 8: [[fallthrough]];
		case 10: [[fallthrough]];
		case 12:
			days = 31;
			break;
		case 4: [[fallthrough]];
		case 6: [[fallthrough]];
		case 9: [[fallthrough]];
		case 11: 
			days = 30;
			break;
		
		case 2:
			if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
				days = 29;
			}else{
				days = 28;
			}
			break;
		
		default:
			days = -1;
			break;
	}
	return days;
}

int main(){
	printf("Thang 1/2026 co: %d ngay\n", get_days(1, 2026));
	printf("Thang 4/2026 co: %d ngay\n", get_days(4, 2026));
	printf("Thang 2/2024 co: %d ngay\n", get_days(2, 2024));
	printf("Thang 2/2026 co: %d ngay\n", get_days(2, 2026));
	printf("Thang 15/2026 co: %d ngay (Loi)\n", get_days(15, 2026));
	return 0;
}
