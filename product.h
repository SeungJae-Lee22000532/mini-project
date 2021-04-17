#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50]; // 제품명
    double kg; // 제품 중량(kg)
    int gram; // 제품 중량(g)
    int price; // 제품 가격
    int review_star; // 제품 별점
    int review_amount; // 제품 리뷰수
} Product;

int addProduct(Product *p); // 제품을 추가하는 함수
void readProduct(Product p); // 하나의 제품 출력 함수
void listProduct(Product *p[], int count); // 전체 등록된 제품 리스트 출력
int updateProduct(Product *p); // 하나의 제품 정보를 수정하는 함수
int deleteProduct(Product *p); // 하나의 제품 정보를 삭제하는 함수
void saveFile(Product *p[], int count); // 현재 저장된 제품 정보를 파일에 저장하는 함수
int loadFile(Product *p[]); // 파일로부터 제품 정보를 불러오는 함수
void searchName(Product *p[], int count); // 제품명으로 제품 정보를 검색하는 함수
void searchPrice(Product *p[], int count); // 제품 가격으로 제품 정보를 검색하는 함수
void searchStar(Product *p[], int count); // 제품 별점으로 제품 정보를 검색하는 함수
