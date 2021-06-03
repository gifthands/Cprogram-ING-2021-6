//注意
	//1:该程序每次运行的时间必须小于10秒，否则会超时,程序超时将不会测试剩余的测试集
	//2:该程序每次运行使用的内存不能超过1M，否则会返回错误
	//3:该程序每次运行输出的结果最多显示1000个字符(多余的不显示),每行末尾的所有空格用□表示
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
	//获取参数方式 scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);

	//结果输出使用prinf
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