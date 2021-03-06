#include "manager.h"

int selectMenu() {
	int menu;
	printf("\n*** mini project ***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품명검색\n");
	printf("7. 제품가격검색\n");
	printf("8. 제품별점검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}

int main() {

#ifdef DEBUG
	printf("=> DEBUGMODE\n");
#endif

	Product *p[100];
	int count = 0, index = 0;
	int menu;
	count = loadFile(p);
	index = count;

	while(1) {
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1 || menu == 3 || menu == 4) {
			if(count == 0) {
				printf("정보가 존재하지 않습니다.\n");
				continue;
			}
		}
		if(menu == 1) {
			listProduct(p, index);
		}
		else if(menu == 2) {
			p[index] = (Product *)malloc(sizeof(Product));
			count += addProduct(p[index++]);
			if(count > 0) printf("추가됨!\n");
		}
		else if(menu == 3) {
			int no = selectDataNo(p, index);
			if(no > 0) {
				int isupdate = updateProduct(p[no - 1]);
				if(isupdate == 1)
					printf("수정성공!\n");
			}
			else
				printf("취소됨!\n");
		}
		else if(menu == 4) {
			int no = selectDataNo(p, index);
			if(no > 0) {
				printf("정말로 삭제하시겠습니까? (삭제 : 1) ");
				int delok;
				scanf("%d", &delok);
				if(delok == 1) {
					free(p[no - 1]);
					p[no - 1] = NULL;
					count --;
					printf("삭제성공!\n");
				}
				else
					printf("취소됨!\n");
			}
		}
		else if(menu == 5) {
			if(count == 0)
				printf("데이터가 없습니다!\n");
			else
				saveFile(p, count);
		}
		else if(menu == 6) {
			searchName(p, count);
		}
		else if(menu == 7) {
			searchPrice(p, count);
		}
		else if(menu == 8) {
			searchStar(p, count);
		}
		else
			printf("없는 메뉴입니다...\n");
	}
	printf("종료됨!\n");
	return 0;
}
