#include "ai.h"
ai::ai(int a)
{
	int i, j;
	player = a;
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			valueboard[i][j] = 0;
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			bvalueboard[i][j] = 0;
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			wvalueboard[i][j] = 0;
}
void  ai::robot(int &x, int &y, int board[15][15])
{
	int i, j, m = 0, c = 0, z = 0, r;
	int **temp;
	value(board, wvalueboard, -1);
	value(board, bvalueboard, 1);
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{	
			if (player == 1)
			{
				if (bvalueboard[i][j] == -10 && wvalueboard[i][j] == -10)
					valueboard[i][j] = -100;
				else
				{
					if (wvalueboard[i][j]<=10)
						valueboard[i][j] =bvalueboard[i][j];
					else
						valueboard[i][j] = (bvalueboard[i][j] + 10) + wvalueboard[i][j];
				}
			}
			if (player == -1)
			{
				if (bvalueboard[i][j] == -10 && wvalueboard[i][j] == -10)
					valueboard[i][j] = -100;
				else
				{
					if (bvalueboard[i][j] <= 10)
						valueboard[i][j] = wvalueboard[i][j];
					else
						valueboard[i][j] = (wvalueboard[i][j] + 10) + bvalueboard[i][j];
				}
			}
		}
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] > m)
				m = valueboard[i][j];
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] == m)
				c++;
	temp = new int *[c];
	for (i = 0; i<c; i++)
	{
		temp[i] = new int[2];
	}
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] == m)
			{
				temp[z][0] = i;
				temp[z][1] = j;
				z++;
			}

	srand((int)time(0));
	r = random(c);

	x = temp[r][0] + 1;
	y = temp[r][1] + 1;

	for (int i = 0; i<c; i++)
	{
		delete[] temp[i];
	}
	delete[] temp;
}
void  ai::value(int board[15][15], int valueboard[15][15], int player)
{
	int x, y, i, j, hs = 0, k;
	int max[4] = { 0 }, c[8] = { 0 }, die[8] = { 0 };
	for (x = 0; x <= 14; x++)
		for (y = 0; y <= 14; y++)
			if (board[x][y] == 0)
				valueboard[x][y] = 0;
			else
				valueboard[x][y] = -10;

	for (x = 0; x <= 14; x++)
		for (y = 0; y <= 14; y++)
		{
			if (valueboard[x][y] != -10)
			{
				//横
				for (i = -1;; i--)
				{
					if (y + i <= 14 && y + i >= 0)
					{
						if (player == board[x][y + i])
							c[0]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x][y + i] == -player)
					die[0]++;
				for (i = 1;; i++)
				{
					if (y + i <= 14 && y + i >= 0)
					{
						if (player == board[x][y + i])
							c[1]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x][y + i] == -player)
					die[1]++;
				max[0] = score(c[0] + c[1], die[0] + die[1]);

				//竖
				for (i = -1;; i--)
				{
					if (x + i <= 14 && x + i >= 0)
					{
						if (player == board[x + i][y])
							c[2]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y] == -player)
					die[2]++;
				for (i = 1;; i++)
				{
					if (x + i <= 14 && x + i >= 0)
					{
						if (player == board[x + i][y])
							c[3]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y] == -player)
					die[3]++;
				max[1] = score(c[2] + c[3], die[2] + die[3]);

				//左上到右下
				for (i = -1, j = -1;; i--, j--)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (player == board[x + i][y + j])
							c[4]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -player)
					die[4]++;
				for (i = 1, j = 1;; i++, j++)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (player == board[x + i][y + j])
							c[5]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -player)
					die[5]++;
				max[2] = score(c[4] + c[5], die[4] + die[5]);

				//右上到左下
				for (i = 1, j = -1;; i++, j--)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (player == board[x + i][y + j])
							c[6]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -player)
					die[6]++;
				for (i = -1, j = 1;; i--, j++)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (player == board[x + i][y + j])
							c[7]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -player)
					die[7]++;
				max[3] = score(c[6] + c[7], die[6] + die[7]);
				sort(max, 4);
				for (k = 0; k <= 7; k++)
					if (c[k] + 1 == 3)
						if (die[k] == 0)
							hs++;
				if (hs >= 2)
					valueboard[x][y] = 5000;
				else
					valueboard[x][y] = max[0];
				for (k = 0; k <= 7; k++)
					c[k] = 0;
				for (k = 0; k <= 7; k++)
					die[k] = 0;
				hs = 0;
			}
		}
}
void ai::sort(int a[], int n)
{
	int i, j, temp;
	for (j = 0; j < n - 1; j++)
		for (i = 0; i < n - 1 - j; i++)
		{
			if (a[i] < a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
}
int ai::score(int c, int die)
{
	c = c + 1;
	if (c >= 5)
		return 100000;
	else
	{
		if (die >= 2)
			return 10;
		else
		{
			if (die == 0)
			{
				if (c == 1)
					return 1;
				if (c == 2)
					return 100;
				else if (c == 3)
					return 1000;
				else if (c == 4)
					return 10000;
			}
			else if (die == 1)
			{
				if (c == 1)
					return 1;
				if (c == 2)
					return 10;
				else if (c == 3)
					return 100;
				else if (c == 4)
					return 1000;
			}
		}
	}
}