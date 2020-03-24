#include<cstdlib>

#define OK 1
#define Error 0
typedef int Status;
typedef int Elemtype;
typedef struct node{
	Elemtype data;
	struct node* next;
}Node,*LinkStack;

Status Push(LinkStack top, Elemtype x);

Status Pop(LinkStack top, Elemtype& e);
