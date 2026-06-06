#include <stdio.h>
#include <stddef.h>

int main(){
	int arr[] = {10, 20, 30, 40, 50};
	int *p = arr;

	printf("Mang ban dau: {10, 20, 30, 40, 50}\n");
	printf("Con tro 'p' ban dau tro toi dia chi cua arr[0].\n\n");

	printf("Case 1 : *p++ ---\n");
	p = arr;
	printf("Gia tri cua bieu thuc '*p++' la: %d\n", *p++);
	printf("Gia tri ma 'p' tro toi sau do la: %d\n\n", *p);

	printf("Case 2 : (*p)++ --\n");
	p = arr;
	printf("Gia tri cua bieu thuc '(*p)++' la: %d\n", (*p)++);
	printf("Gia tri cua arr[0] sau do bi thay doi thanh: %d\n", arr[0]);
	printf("Gia tri ma 'p' tro toi la: %d\n\n", *p);

	printf("Case 3 : end - start ---\n");
	int *start = &arr[0];
	int *end = &arr[4];
	ptrdiff_t distance = end - start;
	printf("Khoang cach (so luong phan tu) giua end va start la: %td\n", distance);

	return 0;
}
 
