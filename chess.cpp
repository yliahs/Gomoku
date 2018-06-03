#include"chess.h"
chess::chess(int a, int b, int c)
{
	x = a;
	y = b;
	player = c;
}
void chess::input(int a, int b, int board[15][15])
{
	x = a;
	y = b;
	board[x][y] = player;
}
int chess::judgewin(int board[15][15])
{
	int i, j, c = 0, flag = 0;
	//横
	for (i = -1;; i--)
	{
		if (y + i <= 14 && y + i >= 0)
		{
			if (player == board[x][y + i])
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
			if (player == board[x][y + i])
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

	//竖
	for (i = -1;; i--)
	{
		if (x + i <= 14 && x + i >= 0)
		{
			if (player == board[x + i][y])
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
			if (player == board[x + i][y])
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
	//左上到右下
	for (i = -1, j = -1;; i--, j--)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (player == board[x + i][y + j])
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
			if (player == board[x + i][y + j])
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
	//右上到左下
	for (i = 1, j = -1;; i++, j--)
	{
		if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
		{
			if (player == board[x + i][y + j])
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
			if (player == board[x + i][y + j])
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
void chess::show(int board[15][15])
{
	int i, j;
	system("cls");
	printf("   ");
	for (i = 0; i <= 14; i++)
	{
		printf("%2d ", i + 1);
	}
	printf("\n");
	for (i = 0; i <= 14; i++)
	{
		printf("%2d ", i + 1);
		for (j = 0; j <= 14; j++)
		{
			if (board[i][j] == 0)
				printf("＋ ");
			else if (board[i][j] == 1)
				printf("● ");
			else if (board[i][j] == -1)
				printf("○ ");
		}
		printf("\n");
	}
}