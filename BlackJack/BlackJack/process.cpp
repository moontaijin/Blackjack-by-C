#include "assn5.h"

int Bet(int* money)
{
	while (1)
	{
		printf("[현재 소지금 : $%d] 배팅 금액을 설정하세요! <0 for Exit>", *money);
		int bet_money;
		scanf("%d", &bet_money);

		if (bet_money == 0)
			return 0;
		else if (bet_money < 0 || bet_money>*money)
			printf("유효한 배팅 금액을 설정해주세요!");
		else
			return bet_money;
	}
}

