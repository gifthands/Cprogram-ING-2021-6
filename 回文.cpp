//ע��
	//1:�ó���ÿ�����е�ʱ�����С��10�룬����ᳬʱ,����ʱ���������ʣ��Ĳ��Լ�
	//2:�ó���ÿ������ʹ�õ��ڴ治�ܳ���1M������᷵�ش���
	//3:�ó���ÿ����������Ľ�������ʾ1000���ַ�(����Ĳ���ʾ),ÿ��ĩβ�����пո��á���ʾ
#include <stdio.h>
struct node
{
	int data;
	node* next;
};
void print(node* h);
node* insertTail(node* h, node* t);
void reverse(node* h);


int main()
{
	//��ȡ������ʽ scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);

	//������ʹ��prinf
	//printf("%d",x);
	node* head=NULL;
	int x;
	do {
		scanf("%d", &x);
		node* t = new node;
		t->data = x;
		t->next = NULL;
		head = insertTail(head, t);
	} while (getchar() != '\n');
	reverse(head);
	print(head);
	return 0;
}


node* insertTail(node* h, node* t)
{
	node* p;
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

void reverse(node* h)
{
	int len = 1, i = 0, j;
	node* p = h;
	while (p->next != NULL)
	{
		len++;
		p = p->next;
	}
	p = h;
	while (i < len - 1)
	{
		for (j = 0; j < len - 1 - i;j++)
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
void print(node* h)
{
	node* p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
