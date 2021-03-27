#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

#define LIST_LENGTH		3

int main() {
	List list;
	NameCard *nc;
	char name[NAME_LEN];
	char phone[NAME_LEN];
	int i;
	
	ListInit(&list);
	
	for(i=0; i<LIST_LENGTH; i++) {
		printf("이름을 입력하세요: ");
		scanf("%s", name);
		printf("전화번호를 입력하세요: ");
		scanf("%s", phone);
		nc = MakeNameCard(name, phone);
		
		LInsert(&list, nc);
	}
	printf("\n");
	
	printf("정보를 출력할 사람의 이름을 입력하세요: ");
	scanf("%s", name);
	if(LFirst(&list, &nc)) {
		if(!NameCompare(nc, name)) {
			ShowNameCardInfo(nc);
		} else {
			while(LNext(&list, &nc)) {
				if(!NameCompare(nc, name)) {
					ShowNameCardInfo(nc);
					break;
				}
			}
		}
	}
	printf("\n");
	
	printf("전화번호를 변경할 사람의 이름을 입력하세요: ");
	scanf("%s", name);
	printf("전화번호를 입력하세요: ");
	scanf("%s", phone);
	if(LFirst(&list, &nc)) {
		if(!NameCompare(nc, name)) {
			ChangePhoneNum(nc, phone);
		} else {
			while(LNext(&list, &nc)) {
				if(!NameCompare(nc, name)) {
					ChangePhoneNum(nc, phone);
					break;
				}
			}
		}
	}
	printf("\n");
	
	printf("정보를 삭제할 사람의 이름을 입력하세요: ");
	scanf("%s", name);
	if(LFirst(&list, &nc)) {
		if(!NameCompare(nc, name)) {
			nc = LRemove(&list);
			free(nc);
		} else {
			while(LNext(&list, &nc)) {
				if(!NameCompare(nc, name)) {
					nc = LRemove(&list);
					free(nc);
					break;
				}
			}
		}
	}
	printf("\n");
	
	printf("[데이터 목록]");
	if(LFirst(&list, &nc)) {
		ShowNameCardInfo(nc);
		nc = LRemove(&list);
		free(nc);
		while(LNext(&list, &nc)) {
			ShowNameCardInfo(nc);
			nc = LRemove(&list);
			free(nc);
		}
	}
	
	free(nc);
}