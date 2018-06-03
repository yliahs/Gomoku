#include<iostream>
#include<cstdio>
#include<cstdlib>
class chess
{
	int x, y, player;
public:
	chess(int a = 0, int b = 0, int c = 1);
	int judgewin(int board[15][15]);
	void chess::input(int a, int b, int board[15][15]);
	void show(int board[15][15]);
};