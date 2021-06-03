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
Node* insertTail(Node* h, Node* t);


int main()
{
	//获取参数方式 scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);
	//结果输出使用prinf
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

