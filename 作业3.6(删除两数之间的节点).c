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
Node* Delete(Node*h,int min,int max);

int main()
{
  //��ȡ������ʽ scanf
  //int x  =0;
  //int y = 0;
  //scanf("%d", &x);
 	int min,max,b[8]={1,14,25,36,78,99,102,256};
	int i;
	Node *head=NULL;
  	/*do{
	  	scanf_s("%d", &x);
		a[i] = x;
		i++;
		}while (getchar() != '\n');   //��Ŀ������EOF*/
	//printf("������min��max,��ȡ��֮��Ľڵ�:");
	scanf("%d%d",&min,&max); 
	//���ݶ�ȡ���
	//������ʼ���� 
  	for(i=0;i<8;i++)
  	{
	  	Node *t=(Node*)malloc(sizeof(Node));
		t->data = b[i];
		t->next = NULL;
		head = insertTail( head,  t); //��������ĺ��� 
  	}
  	//��ʼ��������� 
  	head = Delete(head,min,max);  //���ĺ��� 
  	print(head);
  	//������ʹ��prinf
  	//printf("%d",x);
  	return 0;
}

//��������ĺ��������ӽڵ� 
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

//���ĺ�����ɾ��min��max֮��Ľڵ� 
Node* Delete(Node* head, int min, int max)
{
	Node* p = head;
	Node *minNode=NULL,*maxNode=NULL; //Ҫ��ȥ��һ������,minNode��MaxNode��ɾȥ
	while(p)
	{
		if(p->data <= min)
		minNode = p;    
		if(p->data < max)
		maxNode = p;
		p = p->next;
	}
	if(minNode != NULL)
	{
		minNode->next = maxNode->next;
		if(minNode != maxNode)
		maxNode->next = NULL;
	}
	else if(minNode == NULL)
	{
		head = maxNode->next;
	}
	return head;
}

//��ӡ����ĺ��� 
void print(Node* h)
{
	Node* p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

