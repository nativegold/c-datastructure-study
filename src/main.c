#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankSystem.h"

int main() {
	int operation;
	account *acc;	
	
	acc = (account*)malloc(sizeof(account));	// 계좌 동적으로 생성
	strcpy(acc->id, "012345679");	// 계좌번호 임의로 설정
	
	while(TRUE) {
		operation = menu(acc);		// 계좌 관리 메뉴 실행
		if(operation == END)		// 작동 끝내기
			break;
	}
	
	return 0;
}