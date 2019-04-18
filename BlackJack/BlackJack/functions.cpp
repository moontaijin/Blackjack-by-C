#include "assn5.h"

char shape[4] = {'S','H','D','C'};
char num[13] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };

/*������ ��ȯ�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
int Min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
/*�� �ʱ�ȭ�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
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

/*�� �ʱ�ȭ�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Init_Set(SET* set_player, SET* set_dealer)
{
	set_player->head = (CARD*)malloc(sizeof(CARD));
	set_player->tail = set_player->head;
	set_player->cnt = 0;

	set_dealer->head = (CARD*)malloc(sizeof(CARD));
	set_dealer->tail = set_player->head;
	set_dealer->cnt = 0;

	return;
}

/*���� ���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
int Calc_Score(SET* set)
{
	CARD* p = set->head;
	int score=0;
	int ace_cnt=0;

	while(p != NULL)
	{
		score += Min(10,p->number);
		if (p->number == 1)
			ace_cnt++;

		p = p->next;
	}

	for (int i = 0; i < ace_cnt; i++)
	{
		if (score + 10 <= 21)
			score += 10;
		else
			break;
	}

	return score;
}

/*�÷��̾��� ���� ���� ���ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
int Calc_Score_Playerturn(SET* set)
{
	CARD* p = set->head->next;
	int score = 0;
	int ace_cnt = 0;

	while (p != NULL)
	{
		score += Min(10, p->number);
		if (p->number == 1)
			ace_cnt++;

		p = p->next;
	}

	for (int i = 0; i < ace_cnt; i++)
	{
		if (score + 10 <= 21)
			score += 10;
		else
			break;
	}

	return score;
}

/*���� ȭ�� ��¤ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Print_Game(bool player_turn,int* money,int* money_bet,SET* set_player,SET* set_dealer)
{
	system("cls");

	printf("[������ : %d] [���ñݾ� : %d]\n", *money, *money_bet);
	printf("----------------------------------\n");

	int score;

	if (player_turn)
		printf("<Dealer> [????] ");
	else
		printf("<Dealer> ");

	CARD* p;

	//Dealer score calc and print

	score = Calc_Score_Playerturn(set_dealer);

	p = set_dealer->head;

	if (!player_turn)
	{
		char c[10];

		switch (p->shape) {
		case 'S':
			strcpy(c, "��");
			break;
		case 'H':
			strcpy(c, "��");
			break;
		case 'D':
			strcpy(c, "��");
			break;
		case 'C':
			strcpy(c, "��");
			break;
		}

		if (p->number == 10)
			printf("[%s 10] ",c);
		else
			printf("[%s %c] ", c, num[p->number - 1]);

		score = Calc_Score(set_dealer);
	}

	p = p->next;

	while(p!=NULL)
	{
		char c[10];
		switch (p->shape) {
		case 'S':
			strcpy(c, "��");
			break;
		case 'H':
			strcpy(c, "��");
			break;
		case 'D':
			strcpy(c, "��");
			break;
		case 'C':
			strcpy(c, "��");
			break;
		}

		if (p->number == 10)
			printf("[%s 10] ", c);
		else
			printf("[%s %c] ", c, num[p->number - 1]);

		p = p->next;
	}
	
	printf(", Sum = %d\n", score);


	//Player score calc and print
	printf("<Player> ");
	p = set_player->head;

	while (p != NULL)
	{
		char c[10];
		
		switch (p->shape){
			case 'S' :
				strcpy(c, "��");
				break;
			case 'H' :
				strcpy(c, "��");
				break;
			case 'D' :
				strcpy(c, "��");
				break;
			case 'C' :
				strcpy(c, "��");
				break;
		}

		if (p->number == 10)
			printf("[%s 10] ", c);
		else
			printf("[%s %c] ", c, num[p->number - 1]);

		p = p->next;

	}

	printf(", Sum = %d\n\n", Calc_Score(set_player));
}

/*Set ������ �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�*/
void Destroy_Set(SET* set)
{
	CARD *p;

	p = set->head;

	while (p != NULL)
	{
		set->head = set->head->next;
		free(p);
		p = set->head;
	}
}