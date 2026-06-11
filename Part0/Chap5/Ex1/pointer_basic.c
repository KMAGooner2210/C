#include<stdio.h>
#include<stdint.h>

int main(){
	
	// 1. KHAI BAO BIEN 32 BIT (4 BYTES)

	uint32_t data = 0x11223344;
	printf("---BUOC 1: KHOI TAO DU LIEU ---\n");
	printf("Gia tri ban dau cua 'data': 0x%X\n", data);
	printf("Dia chi cua bien 'data' (&): %p\n\n", &data);
	

	// 2. TAO CON TRO 32 BIT TRO TOI DATA
	uint32_t *ptr32 = &data;
	printf("---BUOC 2: TAO CON TRO 32 BIT ---\n");
	printf("ptr32 doc duoc gia tri:		0x%X\n\n", *ptr32);
	
	// 3. EP KIEU SANG CON TRO 8 BIT
	uint8_t *ptr8 = (uint8_t *)&data;
	printf("---BUOC 3: EP KIEU ---\n");
	printf("Byte dau tien cua 'data' la: 0x%X \n\n", *ptr8);
	

	// 4. THAY DOI GIA TRI TAI BYTE DAU TIEN
	*ptr8 = 0xFF;
	printf("---BUOC 4: THAY DOI TAI BYTE DAU TIEN ---\n");
	printf("Gia tri moi cua data la: 0x%X\n", data);
	return 0;
}
