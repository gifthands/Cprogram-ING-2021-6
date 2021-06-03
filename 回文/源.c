//ע��
	//1:�ó���ÿ�����е�ʱ�����С��10�룬����ᳬʱ,����ʱ���������ʣ��Ĳ��Լ�
	//2:�ó���ÿ������ʹ�õ��ڴ治�ܳ���1M������᷵�ش���
	//3:�ó���ÿ����������Ľ�������ʾ1000���ַ�(����Ĳ���ʾ),ÿ��ĩβ�����пո��á���ʾ
#include <stdio.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node Node;
void print(Node* h);
Node* insertTail(Node* h, Node* t);
void reverse(Node* h);


int main()
{
	//��ȡ������ʽ scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);

	//������ʹ��prinf
	//printf("%d",x);
	Node* head = NULL;
	int x;
	do {
		scanf_s("%d", &x);
		Node* t = (Node*)malloc(sizeof(Node));
		t->data = x;
		t->next = NULL;
		head = insertTail(head, t);
	} while (getchar() != '\n');
	reverse(head);
	print(head);
	return 0;
}


Node* insertTail(Node* h, Node* t)
{
	Node* p;
	if (h == NULL)
	{
		h = t;
		return h;
	}
	else
	{
		p = h;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = t;
		return h;
	}
}

void reverse(Node* h)
{
	int len = 1, i = 0, j;
	Node* p = h;
	while (p->next != NULL)
	{
		len++;
		p = p->next;
	}
	p = h;
	while (i < len - 1)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			int x = p->next->data;
			p->next->data = p->data;
			p->data = x;
			p = p->next;
		}
		p = h;
		i++;
	}
}
void print(Node* h)
{
	Node* p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}