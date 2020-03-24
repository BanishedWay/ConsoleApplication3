#include<cstdlib>

#define MAXN 100
#define TEMP 10
#define OK 1
#define Error 0

typedef int Status;
typedef char Elemtype;
typedef struct {
	Elemtype* base;
	Elemtype* top;
	int stacksize;
}Sqstack;

Status InitStack(Sqstack& s);

Status Push(Sqstack& s, Elemtype e);

Status Pop(Sqstack& s, Elemtype& e);

Elemtype GetTop(Sqstack& s);

Status DestroyStack(Sqstack& s);

Status Empty(Sqstack& s);

Status ClearStack(Sqstack& s);

void Print(Sqstack& s);
void hanoi(int n, char x, char y, char z);
void move(int x, int y, int z);