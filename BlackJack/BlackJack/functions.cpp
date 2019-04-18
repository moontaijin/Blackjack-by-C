#include "assn5.h"

char shape[4] = {'S','H','D','C'};
char num[13] = { 'A','2','3','4','5','6','7','8','9','10','J','Q','K' };

int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

void Setting_Deck(CARD card[])
{
	int cnt = 0;
	CARD tmp;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			tmp.shape = shape[i];
			tmp.number = j;
			tmp.idx = cnt;
			card[cnt++] = tmp;
		}
	}
	
	return;
}

void Init(SET* set_player, SET* set_dealer)
{
	set_player->head = (CARD*)malloc(sizeof(CARD));
	set_player->tail = set_player->head;
	set_player->cnt = 0;

	set_dealer->head = (CARD*)malloc(sizeof(CARD));
	set_dealer->tail = set_player->head;
	set_dealer->cnt = 0;

	return;
}

void Print_Game(bool player_turn,int* money,int* money_bet,SET* set_player,SET* set_dealer)
{
	system("cls");

	printf("[소지금 : %d] [배팅금액 : %d]\n", *money, *money_bet);
	printf("----------------------------------\n");

	if (player_turn)
		printf("<Dealer> [????] ");
	else
		printf("<Dealer> ");

	int sum_dealer=0,sum_player=0;
	int ace_dealer = 0, ace_player = 0;

	CARD* p;

	//Dealer score calc and print
	p = set_dealer->head;

	if (p->number == 1)
		ace_dealer++;

	if (!player_turn)
	{
		sum_dealer += Min(10, p->number);

		char c[10];

		switch (p->shape) {
		case 'S':
			strcpy(c, "♠");
			break;
		case 'H':
			strcpy(c, "♥");
			break;
		case 'D':
			strcpy(c, "◆");
			break;
		case 'C':
			strcpy(c, "♣");
			break;
		}

		printf("[%s %c] ", c, num[p->number - 1]);
	}

	p = p->next;

	while(p!=NULL)
	{
		if (p->number == 1)
			ace_dealer++;

		sum_dealer += Min(10, p->number);

		char c[10];

		switch (p->shape) {
		case 'S':
			strcpy(c, "♠");
			break;
		case 'H':
			strcpy(c, "♥");
			break;
		case 'D':
			strcpy(c, "◆");
			break;
		case 'C':
			strcpy(c, "♣");
			break;
		}

		printf("[%s %c] ", c, num[p->number - 1]);
		p = p->next;
	}
	
	for (int i = 0; i < ace_dealer; i++)
	{
		if (sum_dealer - 1 + 11 <= 21)
			sum_dealer += 10;
		else
			break;
	}
	printf(", Sum = %d\n", sum_dealer);


	//Player score calc and print
	printf("<Player> ");
	p = set_player->head;

	while (p != NULL)
	{
		if (p->number == 1)
			ace_player++;

		sum_player += Min(10, p->number);

		char c[10];
		
		switch (p->shape){
			case 'S' :
				strcpy(c, "♠");
				break;
			case 'H' :
				strcpy(c, "♥");
				break;
			case 'D' :
				strcpy(c, "◆");
				break;
			case 'C' :
				strcpy(c, "♣");
				break;
		}

		printf("[%s %c] ", c, num[p->number - 1]);
		p = p->next;

	}

	for (int i = 0; i < ace_player; i++)
	{
		if (sum_player - 1 + 11 <= 21)
			sum_player += 10;
		else
			break;
	}
	printf(", Sum = %d\n\n", sum_player);
}