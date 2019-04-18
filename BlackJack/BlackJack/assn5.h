#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

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
void Shuffle_Deck(bool card_used[],int* card_use_cnt);
void Distri_First_Card(CARD card[],bool card_used[], int* card_use_cnt,SET* set_player,SET* set_dealer);
void Distri_Card(CARD card[], bool card_used[], int* card_use_cnt, SET* set);
int Chk_Game(SET* set_player, SET* set_dealer,bool game_end);
void Print_Game_Result(int result, int* money, int* money_bet);

//funcions.cpp func header
int Min(int a, int b);
void Init_Set(SET* set_player, SET* set_dealer);
void Print_Game(bool player_turn, int* money, int* money_bet, SET* set_player, SET* set_dealer);
int Calc_Score(SET* set);
int Calc_Score_Playerturn(SET* set);
void Destroy_Set(SET* set);