//ע��
	//1:�ó���ÿ�����е�ʱ�����С��10�룬����ᳬʱ,����ʱ���������ʣ��Ĳ��Լ�
	//2:�ó���ÿ������ʹ�õ��ڴ治�ܳ���1M������᷵�ش���
	//3:�ó���ÿ����������Ľ�������ʾ1000���ַ�(����Ĳ���ʾ),ÿ��ĩβ�����пո��á���ʾ
#include <stdio.h>


struct Term
{
	int coeff;     //ϵ�� 
	int pow;          //�ݴ� 
	struct Term* next;
};
typedef struct Term term;
term* insertSort(term* h, term* t);   //��˳�������ĺ��� 
int getpow(int x, int pow);

int main()
{
	//��ȡ������ʽ scanf
	//int x  =0;
	//int y = 0;
	//scanf("%d", &x);
	 //������ʹ��prinf
	//printf("%d",x);
	int x,a[100], pow, i = 0,j;
	char c;
	term* head = NULL;
	while ((c = getchar()) != '\n')
	{
		if (isdigit(c))
		{
			ungetc(c, stdin);//��c�ͻ�������
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

//���ݴεĴ�С˳�������ĺ��� 
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
		p = q;            // ����ָ�벢�к���
		q = q->next;
	}
	if (p == NULL)
	{
		t->next = head;    //���ڱ�ͷ 
		return t;
	}
	if (q == NULL)
	{
		p->next = t;       //���ڱ�β 
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
