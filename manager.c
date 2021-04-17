// manager.c
#include "manager.h"

int selectDataNo(Product *p[], int count) {
	listProduct(p, count);
	int no;
	printf("\n번호는 (취소 : 0)? ");
	scanf("%d", &no);
	return no;
}
