#include "assn5.h"

int money;
int money_start;
int money_bet;
int card_use_cnt;
bool card_used[52];
CARD card[52];
SET set_player, set_dealer;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (argc == 1)
		money = 5000;
	else
		money = atoi(argv[1]);

	money_start = money;
	Setting_Deck(card);

	Init(&set_player,&set_dealer);

	while (1)
	{
		if (money >= money_start * 100)
		{
			printf("����� $%d���� $%d�� �������ϴ�. 100�� �̻� �������Ƿ� ������ �����մϴ�.", money_start, money);
			break;
		}
		else if (money == 0)
		{
			printf("�������� $0�� �Ǿ����ϴ�. ������ �����մϴ�.\n������ �����մϴ�.");
			break;
		}

		money_bet=Bet(&money);
		
		if (money_bet == 0)
		{
			printf("����� $%d�� ����� $%d�� ���ܿԽ��ϴ�.", money_start, money);
			break;
		}
		money -= money_bet;

		Shuffle_Deck(card_used, &card_use_cnt);
		Distri_First_Card(card,card_used, &card_use_cnt,&set_player,&set_dealer);
	}

	return 0;
}