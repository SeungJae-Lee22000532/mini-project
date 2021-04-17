// manager.c
#include "manager.h"

int selectDataNo(Product *p[], int count) {
	listProduct(p, count);
	int no;
	printf("\n번호는 (취소 : 0)? ");
	scanf("%d", &no);
	return no;
}

void saveFile(Product *p[], int count) {
	FILE *fp;
	int i;
	fp = fopen("product.txt", "wt");
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		fprintf(fp, "%s %d %d %d %d\n", p[i]->name, p[i]->gram, p[i]->price, p[i]->review_star, p[i]->review_amount);
	}
	if(fp != NULL)
		printf("=> 저장됨!\n");
	fclose(fp);
}

int loadFile(Product *p[]) {
	FILE *fp;
	int count = 0;
	fp = fopen("product.txt", "rt");
	if(fp == NULL) {
		printf("=> 파일 없음\n");
		return 0;
	} else {
		for(; ; count++) {
			p[count] = (Product *)malloc(sizeof(Product));
			fscanf(fp, "%s", p[count]->name);
			if(feof(fp)) break;
			fscanf(fp, "%d %d %d %d", &p[count]->gram, &p[count]->price, &p[count]->review_star, &p[count]->review_amount);
		}
	}
	fclose(fp);
	printf("=> 로딩 성공!\n");
	return count;
}

void searchName(Product *p[], int count) {
	int pcount = 0;
	char name[50];
	int i;
	printf("검색할 이름은? ");
	scanf("%s", name);
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		if(strstr(p[i]->name, name)) {
			printf("%2d ", i + 1);
			readProduct(*p[i]);
			pcount++;
		}
	}
	if(pcount == 0)
		printf("=> 검색된 데이터 없음!\n");
}

void searchPrice(Product *p[], int count) {
	int pcount = 0;
	int price1 = 0;
	int price2 = 0;
	int i;
	printf("검색할 가격은(? ~ ?)? ");
	scanf("%d %d", &price1, &price2);
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		if(p[i]->price >= price1 && p[i]->price <= price2) {
			printf("%2d ", i + 1);
			readProduct(*p[i]);
			pcount++;
		}
	}
	if(pcount == 0)
		printf("=> 검색된 데이터 없음!\n");
}

void searchStar(Product *p[], int count) {
	int pcount = 0;
	int star = 0;
	int i;
	printf("검색할 별점은? ");
	scanf("%d", &star);
	for(i = 0; i < count; i++) {
		if(p[i] == NULL) continue;
		if(p[i]->review_star == star) {
			printf("%2d ", i + 1);
			readProduct(*p[i]);
			pcount++;
		}
	}
	if(pcount == 0)
		printf("=> 검색된 데이터 없음!\n");
}
