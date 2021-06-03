#include <stdio.h> 

struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;

void Append(Node *list, Node *p)
{
	Node *m=p->next;
	Node *k = (Node *)malloc(sizeof(Node));
	k->data = p->data;
	k->next = NULL;
	Node *head = k;
	while(m)
	{
		Node *n= (Node *)malloc(sizeof(Node));
		n->data = m->data;
		head->next = n;
		head = head->next;
		m = m->next;
	}
	Node *n = list;
	while(n->next)
	{
		n = n->next;
	}
	n->next = k;
}


int main()
{
	Node *x= (Node *)malloc(sizeof(Node));
	Node *y= (Node *)malloc(sizeof(Node));
	Node *z= (Node *)malloc(sizeof(Node));
	x->data = 1;
	x->next = NULL;
	y->data = 2;
	y->next = NULL;
	z->data = 3;
	x->next = y;
	z->next = NULL;
	Append(z,x);
	while(z)
	{
		printf("%d",z->data);
		z = z->next;
	}
	return 0;
}
