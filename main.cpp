#include<iostream>
#include<cstdio>
#include<string>
#include <windows.h>
#include"ai.h"
#include"chess.h"
using namespace std;
int board[15][15] = { 0 };
int draw(int board[15][15]);
int main()
{
	int x, y;
	chess black(0, 0, 1), white(0, 0, -1);
	ai bbot(1), wbot(-1);
	string model, round;
	cout << "请选择模式(pvp or pve)：" << endl;
	cin >> model;
	if (model == "pve")
	{
		cout << "请选择你要使用的棋子(b or w)：" << endl;
		cin >> round;
	}
	for (;;)
	{
		if (model == "pvp")
		{
			black.show(board);
			cout << "请输入坐标：" << endl;
			for (;;)
			{
				cin >> x >> y;
				if (x <= 15 && y <= 15)
					if (board[x - 1][y - 1] == 0)
					{
						black.input(x - 1, y - 1, board);
						break;
					}
					else
						cout << "输入错误！不能下在已有的棋子的位置" << endl;
				else
					cout << "输入错误！输入的坐标超过棋盘格" << endl;
			}
			black.show(board);
			if (black.judgewin(board) == 1)
			{
				cout << "黑棋赢了！";
				break;
			}
			if (draw(board) == 1)
			{
				cout << "平局！";
				break;
			}
			white.show(board);
			cout << "请输入坐标：" << endl;
			for (;;)
			{
				cin >> x >> y;
				if (x <= 15 && y <= 15)
					if (board[x - 1][y - 1] == 0)
					{
						white.input(x - 1, y - 1, board);
						break;
					}
					else
						cout << "输入错误！不能下在已有的棋子的位置" << endl;
				else
					cout << "输入错误！输入的坐标超过棋盘格" << endl;
			}
			white.show(board);
			if (white.judgewin(board) == 1)
			{
				cout << "白棋赢了！";
				break;
			}
			if (draw(board) == 1)
			{
				cout << "平局！";
				break;
			}
		}
		else if (model == "pve")
		{
			if (round == "b")
			{
				black.show(board);
				cout << "请输入坐标：" << endl;
				for (;;)
				{
					cin >> x >> y;
					if (x <= 15 && y <= 15)
						if (board[x - 1][y - 1] == 0)
						{
							black.input(x - 1, y - 1, board);
							break;
						}
						else
							cout << "输入错误！不能下在已有的棋子的位置" << endl;
					else
						cout << "输入错误！输入的坐标超过棋盘格" << endl;
				}
				black.show(board);
				if (black.judgewin(board) == 1)
				{
					cout << "黑棋赢了！";
					break;
				}
				if (draw(board) == 1)
				{
					cout << "平局！";
					break;
				}
				white.show(board);
				wbot.robot(x, y, board);
				white.input(x - 1, y - 1, board);
				white.show(board);
				if (white.judgewin(board) == 1)
				{
					cout << "白棋赢了！";
					break;
				}
				if (draw(board) == 1)
				{
					cout << "平局！";
					break;
				}
			}
			if (round == "w")
			{
				black.show(board);
				bbot.robot(x, y, board);
				black.input(x - 1, y - 1, board);
				black.show(board);
				if (black.judgewin(board) == 1)
				{
					cout << "黑棋赢了！";
					break;
				}
				if (draw(board) == 1)
				{
					cout << "平局！";
					break;
				}
				white.show(board);
				cout << "请输入坐标：" << endl;
				for (;;)
				{
					cin >> x >> y;
					if (x <= 15 && y <= 15)
						if (board[x - 1][y - 1] == 0)
						{
							white.input(x - 1, y - 1, board);
							break;
						}
						else
							cout << "输入错误！不能下在已有的棋子的位置" << endl;
					else
						cout << "输入错误！输入的坐标超过棋盘格" << endl;
				}
				white.show(board);
				if (white.judgewin(board) == 1)
				{
					cout << "白棋赢了！";
					break;
				}
				if (draw(board) == 1)
				{
					cout << "平局！";
					break;
				}
			}
		}
		else if (model == "ai")
		{
			black.show(board);
			bbot.robot(x, y, board);
			black.input(x - 1, y - 1, board);
			black.show(board);
			if (black.judgewin(board) == 1)
			{
				cout << "黑棋赢了！";
				break;
			}
			if (draw(board) == 1)
			{
				cout << "平局！";
				break;
			}
			
			white.show(board);
			wbot.robot(x, y, board);
			white.input(x - 1, y - 1, board);
			white.show(board);
			if (black.judgewin(board) == 1)
			{
				cout << "白棋赢了！";
				break;
			}
			if (draw(board) == 1)
			{
				cout << "平局！";
				break;
			}
		}
	}
}
int draw(int board[15][15])
{
	int i, j, c = 0;
	for (i = 0; i <= 14; i++)
		for (j = 0; j <= 14; j++)
			if (board[i][j] != 0)
				c++;
	if (c >= 225)
		return 1;
	else
		return 0;
}