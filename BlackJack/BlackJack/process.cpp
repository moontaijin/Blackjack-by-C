#include "assn5.h"

int Bet(int* money)
{
	while (1)
	{
		printf("[���� ������ : $%d] ���� �ݾ��� �����ϼ���! <0 for Exit>", *money);
		int bet_money;
		scanf("%d", &bet_money);

		if (bet_money == 0)
			return 0;
		else if (bet_money < 0 || bet_money>*money)
			printf("��ȿ�� ���� �ݾ��� �������ּ���!");
		else
			return bet_money;
	}
}

