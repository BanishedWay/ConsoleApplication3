#include"stack.h"
#include <stdio.h>

void InitStack(sqstack& s) {
	s.top = -1;//设置栈顶指针为-1.表示栈空
}

Status Push(sqstack& s, Elemtype x)
{
	if (s.top >= MAXN - 1) {
		return Error;
	}
	else {
		s.top++;
		s.stack[s.top] = x;
		return OK;
	}
}
Status Pop(sqstack& s, Elemtype& e)
{
	if (s.top < 0) {
		return Error;
	}
	else {
		e = s.stack[s.top];
		s.top--;
		return OK;

	}
}
Elemtype GetTop(sqstack& s)
{
	if (s.top < 0) {
		return NULL;
	}
	else {
		return s.stack[s.top];
	}
}

Status Empty(sqstack s)
{
	if (s.top < 0) {
		return true;
	}
	else {
		return false;
	}
}

void conversion()
{
	sqstack s;
	int N;
	char e;
	InitStack(s);
	scanf("%d", &N);
	while (N)
	{
		Push(s, N % 8);
		N = N / 8;
	}
	while (!Empty(s)){
		Pop(s, e);
		printf("%d", e);
	}
	printf("\n");
}

Status matching()
{
	sqstack s;
	int n;
	char exp[10];

	scanf("%d", &n);
	scanf("%s", exp);
	InitStack(s);
	int flag = 1, i = 0;
	while (i < n && flag == 1) {
		switch (exp[i]) {
		case '(':
			Push(s, exp[i]);
			i++;
			break;
		case ')':
			if (!Empty(s) && GetTop(s) == '(') {
				char e;
				Pop(s, e);
				i++;
			}
			else {
				flag = 0;

			}
			break;
		default:
			flag = 0;
			break;
		}
	}
	if (Empty(s) && flag) {
		return OK;
	}
	else {
		return Error;
	}
}

void ClearStack(sqstack& s)
{
	s.top = -1;
}
