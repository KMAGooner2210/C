#include <stdio.h>
#include <stdint.h>

int main(){
	uint8_t status = 0;
	printf("Gia tri ban dau:   0x%02X\n\n", status);
	
	//1. SET BIT (BAT BIT SO 3 TU 0 LEN 1)
	// REG |= (1 << n)
	status = status | (1 << 3);
	printf("Sau khi set bit 3:   0x%02X\n", status);
	
	//2. CLEAR BIT (TAT BIT SO 3 VE LAI 0)
	// REG &= ~(1<<n)
	status = status & ~(1 << 3);
	printf("Sau khi clear bit 3: 0x%02X\n\n", status);
	
	//3. TOGGLE BIT (DAO TRANG THAI BIT SO 5)
	// REG ^= (1 << 5);
	status = status ^ (1 << 5);
	printf("Sau khi toggle bit 5: 0x%02X\n", status);

	//4. CHECK BIT (KIEM TRA BIT SO 5 DANG LA 0 HAY 1)
	// if (REG & (1 << n))
	if (status & (1 << 5)){
		printf("Kiem tra: Bit thu 5 dang la 1 (ON)\n");
	}else{
		printf("Kiem tra: Bit thu 5 dang la 0 (OFF)\n");
	}
	return 0;
}

