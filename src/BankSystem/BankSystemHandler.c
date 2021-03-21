#include <stdio.h>
#include <ctype.h>
#include "BankSystem.h"

void deposit(account *acc) {	// 입금
	int money = 0;
	
	printf("--------------------------------- \n");
	printf("입금할 금액을 입력하세요: ");
	scanf("%d", &money);
	acc->money += money;
	printf("계좌 [ %s ]에 [ %d ]원을 정상적으로 입금하였습니다. \n", acc->id, money);
	printf("남은 잔액은 [ %d ]원 입니다. \n", acc->money);
	printf("--------------------------------- \n");
}

void withdraw(account *acc) {	// 출금
	int money = 0;
	
	printf("--------------------------------- \n");
	printf("출금할 금액을 입력하세요: ");
	scanf("%d", &money);
	
	if(acc->money < money) {
		printf("잔액이 부족하여 출금할 수 없습니다. \n");
	} else {
		acc->money -= money;
		printf("계좌 [ %s ]에서 [ %d ]원을 정상적으로 출금하였습니다. \n", acc->id, money);
		printf("남은 잔액은 [ %d ]원 입니다. \n", acc->money);
	}
	printf("--------------------------------- \n");
}

int menu(account *acc) {	// 메뉴
	char menu_num;
	
	while(TRUE) {
		printf("[ %s ]님 오늘도 좋은 하루되세요! \n", acc->id);
		printf("--------------------------------- \n");
		printf("[1] 입금 \n");
		printf("[2] 출금 \n");
		printf("[0] 끝내기 \n");
		printf("--------------------------------- \n");
	
		printf("사용할 기능의 번호를 입력하세요: ");
		scanf("%c", &menu_num);
		
		switch(menu_num) {
			case '0':
				return END;
				break;
			case '1':
				deposit(acc);
				break;
			case '2':
				withdraw(acc);
				break;
			default:
				printf("잘못된 값을 입력하셨습니다. \n");
				printf("다시 입력하세요. \n");
		}
	}
	
	return END;
}