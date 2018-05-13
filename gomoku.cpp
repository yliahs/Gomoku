#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*This Program was written by HeHong Wu*/
int board[15][15] = { 0 };
int  judgewin(int x, int y, int n, int board[15][15]);
int main()
{
	int i, j;
	int x, y, round = 1, flag = 0;

	for (;;)
	{
		system("cls");
		printf("   ");
		for (i = 0; i <= 14; i++)
		{
			printf("%2d ", i + 1);
		}
		cout << endl;
		for (i = 0; i <= 14; i++)
		{
			printf("%2d ", i + 1);
			for (j = 0; j <= 14; j++)
			{
				if (board[i][j] == 0)
					printf("�� ");
				else if (board[i][j] == 1)
					printf("�� ");
				else if (board[i][j] == -1)
					printf("�� ");
			}
			cout << endl;
		}

		if (flag == 1)
		{
			cout << "����Ӯ�ˣ�" << endl;
			break;
		}
		else if (flag == -1)
		{
			cout << "����Ӯ�ˣ�" << endl;
			break;
		}

		cout << "���������ӵ����꣺" << endl;
		for (;;)
		{
			cin >> x >> y;
			if (x <= 15 && y <= 15)
				if (board[x - 1][y - 1] == 0)
				{
					board[x - 1][y - 1] = round;
					break;
				}
				else
					cout << "������󣡲����������е����ӵ�λ��" << endl;
			else
				cout << "���������������곬�����̸�" << endl;
		}

		if (judgewin(x, y, round, board) == 1)
		{
			if (round == 1)
				flag = 1;
			else if (round == -1)
				flag = -1;
		}

		round = -round;

	}
}
int judgewin(int x, int y, int n, int board[15][15])
{
	int i, j, c = 0, flag = 0;
	x = x - 1;
	y = y - 1;
	//��
	for (i = -1;; i--)
	{
		if (y + i <= 14 && y + i >= 0)
		{
			if (n == board[x][y + i])
				c++;
			else
				break;
		}
		else
			break;
	}
	for (i = 1;; i++)
	{
		if (y + i <= 14 && y + i >= 0)
		{
			if (n == board[x][y + i])
				c++;
			else
				break;
		}
		else
			break;
	}
	if (c >= 4)
		flag++;
	c = 0;

	//��
	for (i = -1;; i--)
	{
		if (x + i <= 14 && x + i >= 0)
		{
			if (n == board[x + i][y])
				c++;
			else
				break;
		}
		else
			break;
	}
	for (i = 1;; i++)
	{
		if (x + i <= 14 && x + i >= 0)
		{
			if (n == board[x + i][y])
				c++;
			else
				break;
		}
		else
			break;
	}
	if (c >= 4)
		flag++;
	c = 0;
	//���ϵ�����
	for (i = -1, j = -1;; i--, j--)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (n == board[x + i][y + j])
				c++;
			else
				break;
		}
		else
			break;
	}
	for (i = 1, j = 1;; i++, j++)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (n == board[x + i][y + j])
				c++;
			else
				break;
		}
		else
			break;
	}
	if (c >= 4)
		flag++;
	c = 0;
	//���ϵ�����
	for (i = 1, j = -1;; i++, j--)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (n == board[x + i][y + j])
				c++;
			else
				break;
		}
		else
			break;
	}
	for (i = -1, j = 1;; i--, j++)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (n == board[x + i][y + j])
				c++;
			else
				break;
		}
		else
			break;
	}
	if (c >= 4)
		flag++;
	c = 0;
	if (flag > 0)
		return 1;
	else
		return 0;
}