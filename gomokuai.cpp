#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define random(x) (rand()%x)
using namespace std;
/*This Program was written by HeHong Wu     AI Version*/
int board[15][15] = { 0 };
int  judgewin(int x, int y, int n, int board[15][15]);
void  ai(int &x, int &y, int board[15][15], int n);
void  value(int board[15][15], int valueboard[15][15], int n);
void sort(int a[], int n);
void iboard(int board[15][15]);
int score(int c, int die);
int main()
{
	int x, y, round = 1;
	char input;
	cout << "请选择先手还是后手(b or w)：" << endl;
	cin >> input;

	for (;;)
	{
		if (input == 'b')
		{
			iboard(board);
			cout << "您是黑子，请输入棋子的坐标：" << endl;
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
						cout << "输入错误！不能下在已有的棋子的位置" << endl;
				else
					cout << "输入错误！输入的坐标超过棋盘格" << endl;
			}
			iboard(board);
			if (judgewin(x, y, round, board) == 1)
			{
				cout << "黑棋赢了！" << endl;
				break;
			}

			ai(x, y, board, -round);
			board[x - 1][y - 1] = -round;

			iboard(board);
			if (judgewin(x, y, -round, board) == 1)
			{
				cout << "白棋赢了！" << endl;
				break;
			}

		}

		if (input == 'w')
		{
			ai(x, y, board, -round);
			board[x - 1][y - 1] = -round;
			iboard(board);
			if (judgewin(x, y, -round, board) == 1)
			{
				cout << "白棋赢了！" << endl;
				break;
			}
			cout << "您是白子，请输入棋子的坐标：" << endl;
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
						cout << "输入错误！不能下在已有的棋子的位置" << endl;
				else
					cout << "输入错误！输入的坐标超过棋盘格" << endl;
			}
			iboard(board);
			if (judgewin(x, y, round, board) == 1)
			{
				cout << "黑棋赢了！" << endl;
				break;
			}
		}
	}
}

int judgewin(int x, int y, int n, int board[15][15])
{
	int i, j, c = 0, flag = 0;
	x = x - 1;
	y = y - 1;
	//横
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

	//竖
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
	//左上到右下
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
	//右上到左下
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

void  ai(int &x, int &y, int board[15][15], int n)
{
	int i, j, m = 0, c = 0, z = 0, r;
	int wvalueboard[15][15] = { 0 }, bvalueboard[15][15] = { 0 }, valueboard[15][15] = { 0 };
	int **temp;
	value(board, wvalueboard, -1);
	value(board, bvalueboard, 1);
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
		{
			if (bvalueboard[i][j] == -10 && wvalueboard[i][j] == -10)
				valueboard[i][j] = -100;
			else
				valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j];
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

void  value(int board[15][15], int valueboard[15][15], int n)
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
						if (n == board[x][y + i])
							c[0]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x][y + i] == -n)
					die[0]++;
				for (i = 1;; i++)
				{
					if (y + i <= 14 && y + i >= 0)
					{
						if (n == board[x][y + i])
							c[1]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x][y + i] == -n)
					die[1]++;
				max[0] = score(c[0] + c[1], die[0] + die[1]);

				//竖
				for (i = -1;; i--)
				{
					if (x + i <= 14 && x + i >= 0)
					{
						if (n == board[x + i][y])
							c[2]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y] == -n)
					die[2]++;
				for (i = 1;; i++)
				{
					if (x + i <= 14 && x + i >= 0)
					{
						if (n == board[x + i][y])
							c[3]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y] == -n)
					die[3]++;
				max[1] = score(c[2] + c[3], die[2] + die[3]);

				//左上到右下
				for (i = -1, j = -1;; i--, j--)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (n == board[x + i][y + j])
							c[4]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -n)
					die[4]++;
				for (i = 1, j = 1;; i++, j++)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (n == board[x + i][y + j])
							c[5]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -n)
					die[5]++;
				max[2] = score(c[4] + c[5], die[4] + die[5]);

				//右上到左下
				for (i = 1, j = -1;; i++, j--)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (n == board[x + i][y + j])
							c[6]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -n)
					die[6]++;
				for (i = -1, j = 1;; i--, j++)
				{
					if (x + i <= 14 && x + i >= 0 && y + j <= 14 && y + j >= 0)
					{
						if (n == board[x + i][y + j])
							c[7]++;
						else
							break;
					}
					else
						break;
				}
				if (board[x + i][y + j] == -n)
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

void sort(int a[], int n)
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
void iboard(int board[15][15])
{
	int i, j;
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
				printf("＋ ");
			else if (board[i][j] == 1)
				printf("● ");
			else if (board[i][j] == -1)
				printf("○ ");
		}
		cout << endl;
	}
}
int score(int c, int die)
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
