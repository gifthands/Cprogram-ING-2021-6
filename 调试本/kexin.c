//ע��
	//1:�ó���ÿ�����е�ʱ�����С��10�룬����ᳬʱ,����ʱ���������ʣ��Ĳ��Լ�
	//2:�ó���ÿ������ʹ�õ��ڴ治�ܳ���1M������᷵�ش���
	//3:�ó���ÿ����������Ľ�������ʾ1000���ַ�(����Ĳ���ʾ),ÿ��ĩβ�����пո��á���ʾ
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

Node* NewNode(Term* t)//�����½�� 
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = t;
	p->next = NULL;
	return p;
}

Term* NewTerm(double a, int b)//������term 
{
	Term* t = (Term*)malloc(sizeof(Term));
	t->coeff = a;
	t->power = b;
	return t;
}

Node* Append(Node* h, Node* p)//��p��ӵ���hΪͷ������ 
{
	Node* temp = h;
	while (temp->next)
		temp = temp->next;
	temp->next = p;
	return h;
}

Node* Findmaxpower(Node* h)//�ҵ���������term 
{
	if (h)
	{
		Node* r = h;
		Node* p = h;
		int count = 0;
		while (p)//�ҵ������Ľ�� 
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
			while (count1 < count)//��ԭ������ɾ�������� 
			{
				count1 += 1;
				p = p->next;
			}
			//��ʱpΪ�ý���ǰһ����� 
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


int Power(int x, int b)//����x��b�η� 
{
	if (b == 1)
		return x;
	else
		return x * (Power(x, b - 1));
}

void Print(Node* h, int x)//��ӡ���� 
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
	//��ȡ������ʽ scanf
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
	printf("%lf", h->data->coeff);    //��������ĸ�ʽΪlf;
	int x;
	scanf_s("%d", &x);
	//  Print(h,x);

	  //������ʹ��prinf
	  //printf("%d",x);


	return 0;
}