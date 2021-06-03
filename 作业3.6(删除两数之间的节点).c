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
Node* Delete(Node*h,int min,int max);

int main()
{
  //获取参数方式 scanf
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
		}while (getchar() != '\n');   //题目里面用EOF*/
	//printf("请输入min和max,将取出之间的节点:");
	scanf("%d%d",&min,&max); 
	//数据读取完毕
	//构建初始链表 
  	for(i=0;i<8;i++)
  	{
	  	Node *t=(Node*)malloc(sizeof(Node));
		t->data = b[i];
		t->next = NULL;
		head = insertTail( head,  t); //构建链表的函数 
  	}
  	//初始链表构建完毕 
  	head = Delete(head,min,max);  //核心函数 
  	print(head);
  	//结果输出使用prinf
  	//printf("%d",x);
  	return 0;
}

//构建链表的函数，连接节点 
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

//核心函数，删除min和max之间的节点 
Node* Delete(Node* head, int min, int max)
{
	Node* p = head;
	Node *minNode=NULL,*maxNode=NULL; //要截去的一段链表,minNode和MaxNode不删去
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

//打印链表的函数 
void print(Node* h)
{
	Node* p = h;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

