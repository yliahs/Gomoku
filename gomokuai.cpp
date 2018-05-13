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
			if (n == 1)
			{
				if (bvalueboard[i][j] == -10 && wvalueboard[i][j] == -10)
					valueboard[i][j] = -10;
				else if (bvalueboard[i][j] == 4)
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 100;
				else if (wvalueboard[i][j] == 4)
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 50;
				else if (wvalueboard[i][j] == 3)
				{
					if ((board[i + 1][j] == 1 && board[i + 4][j] == 0) || (board[i - 1][j] == 1 && board[i - 4][j] == 0) || (board[i][j + 1] == 1 && board[i][j + 4] == 0) || (board[i][j - 1] == 1 && board[i][j - 4] == 0) || (board[i - 1][j - 1] == 1 && board[i - 4][j - 4] == 0) || (board[i + 1][j + 1] == 1 && board[i + 4][j + 4] == 0) || (board[i + 1][j - 1] == 1 && board[i + 4][j - 4] == 0) || (board[i - 1][j + 1] == 1 && board[i - 4][j + 4] == 0))
						valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 30;
					else
						valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j];
				}
				else
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j];
			}
			if (n == -1)
			{
				if (bvalueboard[i][j] == -10 && wvalueboard[i][j] == -10)
					valueboard[i][j] = -10;
				else if (wvalueboard[i][j] == 4)
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 100;
				else if (bvalueboard[i][j] == 4)
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 50;
				else if (bvalueboard[i][j] == 3)
				{
					if ((board[i + 1][j] == 1 && board[i + 4][j] == 0) || (board[i - 1][j] == 1 && board[i - 4][j] == 0) || (board[i][j + 1] == 1 && board[i][j + 4] == 0) || (board[i][j - 1] == 1 && board[i][j - 4] == 0) || (board[i - 1][j - 1] == 1 && board[i - 4][j - 4] == 0) || (board[i + 1][j + 1] == 1 && board[i + 4][j + 4] == 0) || (board[i + 1][j - 1] == 1 && board[i + 4][j - 4] == 0) || (board[i - 1][j + 1] == 1 && board[i - 4][j + 4] == 0))
						valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j] + 30;
					else
						valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j];
				}
				else
					valueboard[i][j] = bvalueboard[i][j] + wvalueboard[i][j];
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

void  value(int board[15][15], int valueboard[15][15], int n)
{
	int i, j, k, t;
	int max[5] = { 0 };
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (board[i][j] == 0)
				valueboard[i][j] = 0;
			else
				valueboard[i][j] = -10;
	//横
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] != -10)
			{
				for (k = 0; k <= 4; k++)//1
				{
					if (k == 0) continue;
					if (j + k <= 14 && j + k >= 0)
					{
						if (board[i][j + k] == -n)
						{
							max[0] = 0;
							break;
						}
						else if (board[i][j + k] == n)
							max[0]++;
					}
				}
				for (k = -1; k <= 3; k++)//2
				{
					if (k == 0) continue;
					if (j + k <= 14 && j + k >= 0)
					{
						if (board[i][j + k] == -n)
						{
							max[1] = 0;
							break;
						}
						else if (board[i][j + k] == n)
							max[1]++;
					}
				}
				for (k = -2; k <= 2; k++)//3
				{
					if (k == 0) continue;
					if (j + k <= 14 && j + k >= 0){
						if (board[i][j + k] == -n)
						{
							max[2] = 0;
							break;
						}
						else if (board[i][j + k] == n)
							max[2]++;
					}
				}
				for (k = -3; k <= 1; k++)//4
				{
					if (k == 0) continue;
					if (j + k <= 14 && j + k >= 0)
					{
						if (board[i][j + k] == -n)
						{
							max[3] = 0;
							break;
						}
						else if (board[i][j + k] == n)
							max[3]++;
					}
				}
				for (k = -4; k <= 0; k++)//5
				{
					if (k == 0) continue;
					if (j + k <= 14 && j + k >= 0)
					{
						if (board[i][j + k] == -n)
						{
							max[4] = 0;
							break;
						}
						else if (board[i][j + k] == n)
							max[4]++;
					}
				}
				sort(max, 5);
				if (max[0]>valueboard[i][j])
					valueboard[i][j] = max[0];
				for (t = 0; t < 5; t++)//归零
					max[t] = 0;
			}
	//竖
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] != -10)
			{
				for (k = 0; k <= 4; k++)//1
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0)
					{
						if (board[i + k][j] == -n)
						{
							max[0] = 0;
							break;
						}
						else if (board[i + k][j] == n)
							max[0]++;
					}
				}
				for (k = -1; k <= 3; k++)//2
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0)
					{
						if (board[i + k][j] == -n)
						{
							max[1] = 0;
							break;
						}
						else if (board[i + k][j] == n)
							max[1]++;
					}
				}
				for (k = -2; k <= 2; k++)//3
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0)
					{
						if (board[i + k][j] == -n)
						{
							max[2] = 0;
							break;
						}
						else if (board[i + k][j] == n)
							max[2]++;
					}
				}
				for (k = -3; k <= 1; k++)//4
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0)
					{
						if (board[i + k][j] == -n)
						{
							max[3] = 0;
							break;
						}
						else if (board[i + k][j] == n)
							max[3]++;
					}
				}
				for (k = -4; k <= 0; k++)//5
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0)
					{
						if (board[i + k][j] == -n)
						{
							max[4] = 0;
							break;
						}
						else if (board[i + k][j] == n)
							max[4]++;
					}
				}
				sort(max, 5);
				if (max[0]>valueboard[i][j])
					valueboard[i][j] = max[0];
				for (t = 0; t < 5; t++)//归零
					max[t] = 0;
			}
	//右上到左下
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] != -10)
			{
				for (k = 0; k <= 4; k++)//1
				{
					if (k == 0) continue;
					if (i - k <= 14 && i - k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i - k][j + k] == -n)
						{
							max[0] = 0;
							break;
						}
						else if (board[i - k][j + k] == n)
							max[0]++;
					}
				}
				for (k = -1; k <= 3; k++)//2
				{
					if (k == 0) continue;
					if (i - k <= 14 && i - k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i - k][j + k] == -n)
						{
							max[1] = 0;
							break;
						}
						else if (board[i - k][j + k] == n)
							max[1]++;
					}
				}
				for (k = -2; k <= 2; k++)//3
				{
					if (k == 0) continue;
					if (i - k <= 14 && i - k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i - k][j + k] == -n)
						{
							max[2] = 0;
							break;
						}
						else if (board[i - k][j + k] == n)
							max[2]++;
					}
				}
				for (k = -3; k <= 1; k++)//4
				{
					if (k == 0) continue;
					if (i - k <= 14 && i - k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i - k][j + k] == -n)
						{
							max[3] = 0;
							break;
						}
						else if (board[i - k][j + k] == n)
							max[3]++;
					}
				}
				for (k = -4; k <= 0; k++)//5
				{
					if (k == 0) continue;
					if (i - k <= 14 && i - k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i - k][j + k] == -n)
						{
							max[4] = 0;
							break;
						}
						else if (board[i - k][j + k] == n)
							max[4]++;
					}
				}
				sort(max, 5);
				if (max[0]>valueboard[i][j])
					valueboard[i][j] = max[0];
				for (t = 0; t < 5; t++)//归零
					max[t] = 0;
			}
	//左上到右下
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (valueboard[i][j] != -10)
			{
				for (k = 0; k <= 4; k++)//1
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i + k][j + k] == -n)
						{
							max[0] = 0;
							break;
						}
						else if (board[i + k][j + k] == n)
							max[0]++;
					}
				}
				for (k = -1; k <= 3; k++)//2
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i + k][j + k] == -n)
						{
							max[1] = 0;
							break;
						}
						else if (board[i + k][j + k] == n)
							max[1]++;
					}
				}
				for (k = -2; k <= 2; k++)//3
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i + k][j + k] == -n)
						{
							max[2] = 0;
							break;
						}
						else if (board[i + k][j + k] == n)
							max[2]++;
					}
				}
				for (k = -3; k <= 1; k++)//4
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i + k][j + k] == -n)
						{
							max[3] = 0;
							break;
						}
						else if (board[i + k][j + k] == n)
							max[3]++;
					}
				}
				for (k = -4; k <= 0; k++)//5
				{
					if (k == 0) continue;
					if (i + k <= 14 && i + k >= 0 && j + k <= 14 && j + k >= 0)
					{
						if (board[i + k][j + k] == -n)
						{
							max[4] = 0;
							break;
						}
						else if (board[i + k][j + k] == n)
							max[4]++;
					}
				}
				sort(max, 5);
				if (max[0]>valueboard[i][j])
					valueboard[i][j] = max[0];
				for (t = 0; t < 5; t++)//归零
					max[t] = 0;
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