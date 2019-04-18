#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct CARD{
	int number;
	int idx;
	char shape;
	struct CARD* next;
	struct CARD* pre;
}CARD;

typedef struct SET {
	CARD* head;
	CARD* tail;
	int cnt;
}SET;

//process.cpp func header
int Bet(int* money);
void Setting_Deck(CARD card[]);
void Shuffle_Deck(bool card_used[], int* card_use_cnt);
void Distri_First_Card(CARD card[],bool card_used[], int* card_use_cnt,SET* set_player,SET* set_dealer);

//funcions.cpp func header
int Min(int a, int b);
void Init(SET* set_player, SET* set_dealer);
