#include <string>
#define MAXN 1000
typedef char Elemtype;
typedef int Status;
#define Error 0
#define OK 1

typedef struct {
	Elemtype stack[MAXN];
	int top;
}sqstack;

void InitStack(sqstack& s);

Status Push(sqstack& s, Elemtype x);

Status Pop(sqstack& s, Elemtype& e);

Elemtype GetTop(sqstack& s);

Status Empty(sqstack s);

void conversion();

Status matching();

void ClearStack(sqstack& s);