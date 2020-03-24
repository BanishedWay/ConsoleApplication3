#include "stack1.h"
#include<stdio.h>

Status InitStack(Sqstack& s)
{
	s.base = (Elemtype*)malloc(MAXN * sizeof(Elemtype));
	if (!s.base) {
		exit(0);
	}
	s.top = s.base;
	s.stacksize = MAXN;
	return OK;
}

Status Push(Sqstack& s, Elemtype e)
{
	if (s.top - s.base >= s.stacksize) {
		s.base = (Elemtype*)realloc(s.base, (s.stacksize
			+ TEMP) * sizeof(Elemtype));
		if (!s.base) {
			exit(0);
		}
		s.top = s.base + s.stacksize;
		s.stacksize += TEMP;
	}
	*s.top = e;
	s.top++;
	return OK;
}

Status Pop(Sqstack& s, Elemtype& e)
{
	if (s.top == s.base) {
		return Error;
	}
	s.top--;
	e = *s.top;
	return OK;
}

Elemtype GetTop(Sqstack& s)
{
	Elemtype e;
	if (s.top == s.base) {
		exit(0);
	}
	else {
		e = *(s.top - 1);
	}
	return e;
}

Status DestroyStack(Sqstack& s)
{
	free(s.base);
	s.base = NULL;
	s.top = NULL;
	s.stacksize = 0;
	if (!s.base) {
		printf("OK\n");
	}
	return OK;
}

Status Empty(Sqstack& s)
{
	if (s.top == s.base) {
		return true;
	}
	else {
		return false;
	}
}

Status ClearStack(Sqstack& s)
{
	if (s.base == s.top) {
		return OK;
	}
	while (s.top > s.base) {
		s.top--;
	}
	if (s.top == s.base) {
		return OK;
	}
	return Error;
}

void Print(Sqstack& s)
{
	Elemtype* p;
	p = s.top;
	while (s.base < p) {
		printf("%d ", *(p--));
	}
}

void LineDelete()
{
	Sqstack s;
	InitStack(s);
	char ch;
	ch = getchar();
	while (ch != EOF) {
		while (ch != EOF && ch != '\n') {
			switch (ch)
			{
			case '#':
				if (!Empty(s)) {
					Pop(s, ch);
					break;
				}
			case '@':
				ClearStack(s);
				break;
			default:
				Push(s, ch);
				break;
			}
			ch = getchar();
		}
		Print(s);
		ClearStack(s);
		if (ch != EOF) {
			ch = getchar();
		}
	}

	DestroyStack(s);
}

void hanoi(int n, char x, char y, char z)
{
	if (n == 1) {
		move(x, 1, z);
	}
	else {
		hanoi(n - 1, x, z, y);
		move(x, n, z);
		hanoi(n - 1, y, x, z);
	}
}

void move(int x, int y, int z)
{
	printf("%d: %d->%d\n", y, x, z);
}
