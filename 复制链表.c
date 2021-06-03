#include <stdio.h>
//#include <iostream>
//using namespace std;

struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;

void Append(Node *list, Node *p)
{
	Node *t=list;
	while(t->next)
	{
		t = t->next;
	}
	t->next = p;	
}
int main()
{
	Node *x = (Node*)malloc(sizeof(Node));
	x->data=1;
	x->next = NULL;
	Node *y = (Node*)malloc(sizeof(Node));
	y->data=2;
	y->next = NULL;
	Append(x,y);
	printf("%d%",x->next->data);
	return 0;
}

