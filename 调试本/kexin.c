//注意
	//1:该程序每次运行的时间必须小于10秒，否则会超时,程序超时将不会测试剩余的测试集
	//2:该程序每次运行使用的内存不能超过1M，否则会返回错误
	//3:该程序每次运行输出的结果最多显示1000个字符(多余的不显示),每行末尾的所有空格用□表示
#include <stdio.h>
#include <stdlib.h>
struct term
{
	double coeff;
	int power;
};
typedef struct term Term;
struct node
{
	Term* data;
	struct node* next;
};
typedef struct node Node;

Node* NewNode(Term* t);
Term* NewTerm(double a, int b);
Node* Append(Node* h, Node* p);
void Print(Node* h, int x);
Node* Findmaxpower(Node* h);
int Power(int x, int b);

Node* NewNode(Term* t)//创建新结点 
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = t;
	p->next = NULL;
	return p;
}

Term* NewTerm(double a, int b)//创建新term 
{
	Term* t = (Term*)malloc(sizeof(Term));
	t->coeff = a;
	t->power = b;
	return t;
}

Node* Append(Node* h, Node* p)//把p添加到以h为头的链表 
{
	Node* temp = h;
	while (temp->next)
		temp = temp->next;
	temp->next = p;
	return h;
}

Node* Findmaxpower(Node* h)//找到幂数最大的term 
{
	if (h)
	{
		Node* r = h;
		Node* p = h;
		int count = 0;
		while (p)//找到幂最大的结点 
		{
			if ((p->data->power) > (r->data->power))
			{
				r = p; count += 1;
			}
			p = p->next;
		}
		if (count > 0)
		{
			p = h;
			int count1 = 0;
			while (count1 < count)//在原链表中删除这个结点 
			{
				count1 += 1;
				p = p->next;
			}
			//此时p为该结点的前一个结点 
			Node* temp = p->next;
			p->next = temp->next;
		}
		else
			h = NULL;
		return r;
	}
	else
		return NULL;
}


int Power(int x, int b)//计算x的b次方 
{
	if (b == 1)
		return x;
	else
		return x * (Power(x, b - 1));
}

void Print(Node* h, int x)//打印函数 
{
	printf("f(x)=");
	Node* temp = (Node*)malloc(sizeof(Node));
	temp = Findmaxpower(h);
	double r = 0;
	while (temp)
	{
		if (temp->data->power != 0)
		{
			printf("%fx^%d+", temp->data->coeff, temp->data->power);
			r += temp->data->coeff * Power(x, temp->data->power);
		}
		else
		{
			printf("%f=", temp->data->coeff);
			r += temp->data->coeff;
		}
		temp = Findmaxpower(h);
	}
	printf("%f", r);
}

int main()
{
	//获取参数方式 scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);
	int b;
	double a;
	Node* h = NULL;
	do
	{
		scanf_s("%lf%d", &a, &b);
		Term* t = NewTerm(a, b);
		Node* p = NewNode(t);
		h = Append(h, p);
	} while (b != 0);
	h = h->next;
	printf("%lf", h->data->coeff);    //改了这个的格式为lf;
	int x;
	scanf_s("%d", &x);
	//  Print(h,x);

	  //结果输出使用prinf
	  //printf("%d",x);


	return 0;
}