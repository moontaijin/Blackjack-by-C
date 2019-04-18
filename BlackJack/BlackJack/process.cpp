#include "assn5.h"
/*���äѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
int Bet(int* money)
{
	while (1)
	{
		printf("[���� ������ : $%d] ���� �ݾ��� �����ϼ���! <0 for Exit> ", *money);
		int bet_money;
		scanf("%d", &bet_money);

		if (bet_money == 0)
			return 0;
		else if (bet_money < 0 || bet_money>*money)
			printf("��ȿ�� ���� �ݾ��� �������ּ���!\n");
		else
			return bet_money;
	}
}

/*�� ����ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Shuffle_Deck(bool card_used[],int* card_use_cnt)
{
	printf("\nī�带 ���Ӱ� �����ϴ�...\n");
	for (int i = 0; i < 52; i++)
	{
		card_used[i] = false;
	}

	*card_use_cnt = 0;

	getchar();
	return;
}

/*���� �ܰ迡�� ī�� �����ֱ�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
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
			memcpy(set_dealer->head, card_tmp, sizeof(CARD));
			set_dealer->tail = set_dealer->head;
			(set_dealer->cnt)++;
		}
		else
		{
			memcpy(set_player->head, card_tmp, sizeof(CARD));
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
		if (i % 2)
		{
			card_tmp->pre = set_dealer->tail;
			set_dealer->tail->next = (CARD*)malloc(sizeof(CARD));
			memcpy(set_dealer->tail->next, card_tmp, sizeof(CARD));
			set_dealer->tail = set_dealer->tail->next;
			(set_dealer->cnt)++;
		}
		else
		{
			card_tmp->pre = set_player->tail;
			set_player->tail->next = (CARD*)malloc(sizeof(CARD));
			memcpy(set_player->tail->next, card_tmp, sizeof(CARD));
			set_player->tail = set_player->tail->next;
			(set_player->cnt)++;
		}

		free(card_tmp);
	}

	return;
}

/*ī�� �����ֱ�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Distri_Card(CARD card[], bool card_used[], int* card_use_cnt, SET* set)
{
	CARD* card_tmp = (CARD*)malloc(sizeof(CARD));
	int idx;

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
	
	card_tmp->pre = set->tail;
	set->tail->next = (CARD*)malloc(sizeof(CARD));
	memcpy(set->tail->next, card_tmp, sizeof(CARD));
	set->tail = set->tail->next;
	(set->cnt)++;
	

	free(card_tmp);
}

/*���� ��� Ȯ�ΤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
int Chk_Game(SET* set_player,SET* set_dealer,bool game_end)
{
	int score_player, score_dealer;
	score_player = Calc_Score(set_player);
	score_dealer = Calc_Score(set_dealer);

	if (score_player == 21 && set_player->cnt == 2)
	{
		printf("----------------------------------\n");
		printf("��B��L��A��C��K��J��A��C��K��\n");
		return 1;
	}
	else if (score_player > 21 && game_end)
		return 2;
	else if (score_dealer == 21 && set_dealer->cnt == 2 && game_end)
	{
		printf("----------------------------------\n");
		printf("������ ��B��L��A��C��K��J��A��C��K��\n");
		return 3;
	}
	else if (score_dealer > 21 && game_end)
		return 4;
	else if (score_player >= score_dealer && game_end)
		return 4;
	else if (score_player < score_dealer && game_end)
		return 5;
	else
		return 0;
}

/*���� ��� ��¤ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Print_Game_Result(int result,int* money,int* money_bet)
{
	if (result == 1)
	{
		printf("������ �ݾ��� 3�迡 �ش��ϴ� $%d�� ȹ���߽��ϴ�!\n", (*money_bet) * 3);
		(*money) += (*money_bet) * 3;
	}
	else if (result == 2)
	{
		printf("����Ʈ! �÷��̾ �����ϴ�. ����� ���� �Ҿ����ϴ�.");
	}
	else if (result == 3)
	{
		printf("������ ���� �Ҿ����ϴ�.");
	}
	else if (result == 4)
	{
		printf("�÷��̾ �̰���ϴ�! $%d�� ȹ���߽��ϴ�.", (*money_bet) * 2);
		(*money) += (*money_bet) * 2;
	}
	else if (result == 5)
	{
		printf("�÷��̰Ű� �����ϴ�. ������ ���� �Ҿ����ϴ�.");
	}

}