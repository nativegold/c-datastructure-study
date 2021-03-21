#ifndef __BANK_SYSTEM_H__
#define __BANK_SYSTEM_H__
#define TRUE 1
#define FALSE 0
#define END 0
#define MENU1 1
#define MENU2 2
#define ERROR -1

typedef struct account_ {
	char id[20];
	int money;
} account;

void deposit(account *acc);		// 입금

void withdraw(account *acc);	// 출금

int menu(account *acc);			// 메뉴

#endif