#include "assn5.h"

int money;
int money_start;
int money_bet;

int main(int argc, char* argv[])
{
	if (argc == 1)
		money = 5000;
	else
		money = atoi(argv[1]);

	money_start = money;

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
	}

	return 0;
}