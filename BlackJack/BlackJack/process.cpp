#include "assn5.h"

int Bet(int* money)
{
	while (1)
	{
		printf("[현재 소지금 : $%d] 배팅 금액을 설정하세요! <0 for Exit> ", *money);
		int bet_money;
		scanf("%d", &bet_money);

		if (bet_money == 0)
			return 0;
		else if (bet_money < 0 || bet_money>*money)
			printf("유효한 배팅 금액을 설정해주세요!\n");
		else
			return bet_money;
	}
}

void Shuffle_Deck(bool card_used[],int* card_use_cnt)
{
	if (*card_use_cnt >= 26)
	{
		for (int i = 0; i < 52; i++)
		{
			card_used[i] = false;
		}
		*card_use_cnt = 0;
	}

	return;
}

void Distri_First_Card(CARD card[],bool card_used[],int* card_use_cnt,SET* set_player,SET* set_dealer)
{
	int idx;
	
	for (int i = 0; i < 2; i++)
	{
		CARD* card_tmp = (CARD*)malloc(sizeof(CARD));

		while (1)
		{
			idx = rand() % 52;
			
			if (!card_used[idx])
			{
				card_used[idx] = true;
				(*card_use_cnt)++;
				break;
			}
		}

		(*card_tmp)=card[idx];
		card_tmp->next = NULL;
		if (i % 2)
		{
			set_dealer->head = card_tmp;
			set_dealer->tail = set_dealer->head;
			(set_dealer->cnt)++;
		}
		else
		{
			set_player->head = card_tmp;
			set_player->tail = set_player->head;
			(set_player->cnt)++;
		}
		free(card_tmp);
	}

	for (int i = 0; i < 2; i++)
	{
		CARD* card_tmp = (CARD*)malloc(sizeof(CARD));

		while (1)
		{
			idx = rand() % 52;

			if (!card_used[idx])
			{
				card_used[idx] = true;
				(*card_use_cnt)++;
				break;
			}
		}

		(*card_tmp) = card[idx];
		card_tmp->next = NULL;
		card_tmp->pre = NULL;
		if (i % 2)
		{
			set_dealer->tail->next = card_tmp;
			card_tmp->pre = set_dealer->tail;
			set_dealer->tail = set_dealer->tail->next;
			(set_dealer->cnt)++;
		}
		else
		{
			set_player->tail->next = card_tmp;
			card_tmp->pre = set_player->tail;
			set_player->tail = set_player->tail->next;
			(set_player->cnt)++;
		}

		free(card_tmp);
	}

	return;
}
