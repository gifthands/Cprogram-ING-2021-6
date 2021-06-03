//注意
	//1:该程序每次运行的时间必须小于10秒，否则会超时,程序超时将不会测试剩余的测试集
	//2:该程序每次运行使用的内存不能超过1M，否则会返回错误
	//3:该程序每次运行输出的结果最多显示1000个字符(多余的不显示),每行末尾的所有空格用□表示
#include <stdio.h>


struct Term
{
	int coeff;     //系数 
	int pow;          //幂次 
	struct Term* next;
};
typedef struct Term term;
term* insertSort(term* h, term* t);   //按顺序插入结点的函数 
int getpow(int x, int pow);

int main()
{
	//获取参数方式 scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);
	 //结果输出使用prinf
	//printf("%d",x);
	int x,a[100], pow, i = 0,j;
	char c;
	term* head = NULL;
	while ((c = getchar()) != '\n')
	{
		if (isdigit(c))
		{
			ungetc(c, stdin);//将c送回输入流
			scanf_s("%d", &a[i++]);
		}
	}
	for (j = 0; j < i / 2; j++)
	{
		term* t = (term*)malloc(sizeof(term));
		t->coeff = a[j*2];
		t->pow = a[j*2+1];
		t->next = NULL;
		head = insertSort(head, t);
	}
	x = a[i - 1];
	term* p = head;
	printf("f(x)=");
	int sum = 0;
	while (p)
	{
		if (p->pow == 1)
		{
			if(p->coeff == 1)
				printf("x+");
			if(p->coeff != 1)
				printf("%dx+", p->coeff);
		}
		else if (p->pow == 0)
			printf("%d=", p->coeff);
		else
			printf("%dx^%d+", p->coeff, p->pow);
		sum += getpow(x, p->pow) * p->coeff;
		p = p->next;
	}
	printf("%d", sum);
	return 0;
}

//按幂次的大小顺序插入结点的函数 
term* insertSort(term* head, term* t)
{
	term *p=NULL, * q=head;
	if (head == NULL)
	{
		head = t;
		return head;
	}
	while (q && q->pow > t->pow)
	{
		p = q;            // 两个指针并行后移
		q = q->next;
	}
	if (p == NULL)
	{
		t->next = head;    //插在表头 
		return t;
	}
	if (q == NULL)
	{
		p->next = t;       //插在表尾 
		t->next = NULL;
		return head;
	}
	t->next = q;
	p->next = t;
	return head;
}

int getpow(int x, int pow)
{
	int sum = 1, i;
	int n = pow / 1;
	for (i = 0; i < n; i++)
	{
		sum *= x;
	}
	return sum;
}
