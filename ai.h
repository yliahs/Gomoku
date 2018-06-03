#include<cstdlib>
#include<ctime>
#define random(x) (rand()%x)
class ai
{
	int player;
	int wvalueboard[15][15], bvalueboard[15][15], valueboard[15][15];
public:
	ai(int a = 1);
	void  robot(int &x, int &y, int board[15][15]);
	void  value(int board[15][15], int valueboard[15][15], int player);
	void sort(int a[], int n);
	int score(int c, int die);
};