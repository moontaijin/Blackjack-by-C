#include "assn5.h"

char shape[4] = {'S','H','D','C'};

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
			tmp.number = Min(10, j);
			tmp.idx = cnt;
			card[cnt++] = tmp;
		}
	}
	
	return;
}

void Init(SET* set_player, SET* set_dealer)
{
	set_player->head = NULL;
	set_player->tail = set_player->head;
	set_player->cnt = 0;

	set_dealer->head = NULL;
	set_dealer->tail = set_player->head;
	set_dealer->cnt = 0;

	return;
}