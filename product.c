#include "product.h"

int addProduct(Product *p) {
	getchar();
	printf("제품명은? ");
	fgets(p->name, 50, stdin);
	p->name[strlen(p->name) - 1] = 0;
	printf("제품중량은? ");
	scanf("%d", &p->gram);
	if(p->gram >= 1000)
		p->kg = (double) p->gram / 1000;
	printf("제품가격은? ");
	scanf("%d", &p->price);
	printf("제품별점은(1 ~ 5 사이의 숫자 입력)? ");
	scanf("%d", &p->review_star);
	printf("제품리뷰수는? ");
	scanf("%d", &p->review_amount);
	return 1;
}

void readProduct(Product p) {
		if(p.gram >= 1000)
			printf("제품명: %s, 제품중량: %.1f\n제품가격: %d\n별점: %d\n리뷰수: %d\n", p.name, p.kg, p.price, p.review_star, p.review_amount);
		else
			printf("제품명: %s, 제품중량: %d\n제품가격: %d\n별점: %d\n리뷰수: %d\n", p.name, p.gram, p.price, p.review_star, p.review_amount);
}

void listProduct(Product *p[], int count) {
	int i;
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		printf("%2d ", i + 1);
		readProduct(*p[i]);
	}
}

int updateProduct(Product *p) {
	getchar();
	printf("제품명은? ");
	fgets(p->name, 50, stdin);
	p->name[strlen(p->name) - 1] = 0;
	printf("제품중량은? ");
	scanf("%d", &p->gram);
	if(p->gram >= 1000)
		p->kg = (double) p->gram / 1000;
	printf("제품가격은? ");
	scanf("%d", &p->price);
	printf("제품별점은(1 ~ 5 사이의 숫자 입력)? ");
	scanf("%d", &p->review_star);
	printf("제품리뷰수는? ");
	scanf("%d", &p->review_amount);
	return 1;	
}

int deleteProduct(Product *p) {
	p->price = -1;
	return 1;
}
