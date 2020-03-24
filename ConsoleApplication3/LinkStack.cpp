#include "LinkStack.h"
#include<cstdio>

Status Push(LinkStack top, Elemtype x)
{
	LinkStack temp = (LinkStack)malloc(sizeof(Node));
	if (temp == NULL) {
		return Error;
	}
	else {
		temp->data = x;
		temp->next = top;
		top = temp;
		return OK;
	}
}

Status Pop(LinkStack top, Elemtype& e)
{
	if (top == NULL) {
		return Error;
	}
	else {
		LinkStack p = top;
		top = top->next;
		e = p->data;
		free(p);
		return OK;
	}
}

