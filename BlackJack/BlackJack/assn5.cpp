#include "assn5.h"

int money;
int money_start;
int money_bet;
int card_use_cnt;
int result;
int score;
int round;

bool game_end;
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

	while (1)
	{
		game_end = false;
		round++;
		system("cls");
		if (money >= money_start * 100)
		{
			printf("당신은 $%d으로 $%d를 벌었습니다. 100배 이상 벌었으므로 게임을 종료합니다.\n", money_start, money);
			break;
		}
		else if (money == 0)
		{
			printf("소지금이 $0이 되었습니다. 도박은 위험합니다.\n게임을 종료합니다.\n");
			break;
		}

		money_bet=Bet(&money);
		
		if (money_bet == 0)
		{
			system("cls");
			printf("당신은 $%d을 들고가서 $%d를 남겨왔습니다.\n", money_start, money);
			break;
		}
		money -= money_bet;

		//덱에서 26장이상 사용했을 시 새로운 덱 셔플
		if (card_use_cnt >= 26 || round==1)
			Shuffle_Deck(card_used, &card_use_cnt);

		//Set 초기화
		Init_Set(&set_player, &set_dealer);

		//카드 분배
		Distri_First_Card(card,card_used, &card_use_cnt,&set_player,&set_dealer);

		getchar();

		//Player 차례 진행
		while (1)
		{
			score = Calc_Score(&set_player);

			if (score > 21)
				break;

			Print_Game(true, &money, &money_bet, &set_player, &set_dealer);
			result=Chk_Game(&set_player,&set_dealer,game_end);
			
			if (result == 1)
			{
				Print_Game_Result(result,&money,&money_bet);
				break;
			}

			char order[30];

			printf("Hit or Stay? ");
			scanf("%s", order);
			strlwr(order);

			if (!strcmp(order, "hit"))
				Distri_Card(card, card_used, &card_use_cnt, &set_player);
			else if (!strcmp(order, "stay"))
				break;
			else
			{
				printf("유효한 명령어를 입력해주세요.\n");
				getchar();
			}
		}

		getchar();
		//Dealer 차례 진행
		while (1)
		{
			if (result == 1)
				break;

			score = Calc_Score(&set_dealer);
			Print_Game(false, &money, &money_bet, &set_player, &set_dealer);

			if (score >= 17)
			{
				printf("딜러가 Stay합니다.");
				break;
			}
			else
			{
				printf("딜러가 Hit합니다.....");
				getchar();
				Distri_Card(card, card_used, &card_use_cnt, &set_dealer);
			}
		}

		if (result != 1)
		{
			printf("\n----------------------------------\n");
			game_end = true;
			result = Chk_Game(&set_player, &set_dealer, game_end);
			Print_Game_Result(result, &money, &money_bet);
		}

		Destroy_Set(&set_player);
		Destroy_Set(&set_dealer);

		getchar();
	}

	return 0;
}