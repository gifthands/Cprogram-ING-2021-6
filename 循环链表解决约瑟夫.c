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
Node* insertTail(Node* h, Node* t);


int main()
{
	//��ȡ������ʽ scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);
	//������ʹ��prinf
	//printf("%d",x);
	int i;
	Node* head = NULL, * rear;
	for (i = 0; i < 10; i++)
	{
		rear = (Node*)malloc(sizeof(Node));
		rear->next = NULL;
		rear->data = i + 1;
		head = insertTail(head, rear);
	}
	rear->next = head;
	int count = 0, n;
	scanf_s("%d", &n);
	while (count < 11 - n)
	{
		for (i = 0; i < n-1; i++)
		{
			rear = head;
			head = head->next;
		}
		printf("%d ", head->data);
		rear->next = head->next;
		head = head->next;
		count++;
	}
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

