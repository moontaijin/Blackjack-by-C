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
	srand((unsigned)time(NULL));

	if (argc == 1)
		money = 5000;
	else
		money = atoi(argv[1]);

	money_start = money;
	Setting_Deck(card);

	Init(&set_player,&set_dealer);
	char tmp;

	while (1)
	{
		if (money >= money_start * 100)
		{
			system("cls");
			printf("당신은 $%d으로 $%d를 벌었습니다. 100배 이상 벌었으므로 게임을 종료합니다.", money_start, money);
			break;
		}
		else if (money == 0)
		{
			system("cls");
			printf("소지금이 $0이 되었습니다. 도박은 위험합니다.\n게임을 종료합니다.");
			break;
		}

		money_bet=Bet(&money);
		
		if (money_bet == 0)
		{
			system("cls");
			printf("당신은 $%d을 들고가서 $%d를 남겨왔습니다.", money_start, money);
			break;
		}
		money -= money_bet;

		Shuffle_Deck(card_used, &card_use_cnt);
		Distri_First_Card(card,card_used, &card_use_cnt,&set_player,&set_dealer);

		printf("\n카드를 새롭게 섞습니다...");

		getchar();
		tmp = getchar();

		Print_Game(true,&money,&money_bet,&set_player,&set_dealer);

	}

	return 0;
}