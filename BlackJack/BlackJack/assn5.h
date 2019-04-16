#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct CARD{
	int number;
	char shape;
	struct CARD* next;
}CARD;

typedef struct SET {
	CARD* head;
	CARD* tail;
	int cnt;
}SET;

int Bet(int* money);
