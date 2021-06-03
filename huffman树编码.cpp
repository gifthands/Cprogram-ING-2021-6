#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct huffmannode
{
	int weight;
	int tag,LeftChild,RightChild,Parent;
} ;
typedef struct huffmannode Huffmannode;

 

struct huffmantree
{
	int root;
};
typedef struct huffmantree Huffmantree;

Huffmannode *InitHuffmannode(int w,int t,int l,int r,int p);
void InitHuffmantree(Huffmantree *ht, int r);
void makeHuffmantree(Huffmantree *ht,Huffmannode *b[],int n);
char* compose(char string[],Huffmannode *b[],Huffmantree *t,int p,int n);
void reverse(char string[]);

Huffmannode *InitHuffmannode(int w,int t,int l,int r,int p)
{
	Huffmannode *h=(Huffmannode*)malloc(sizeof(Huffmannode));
	h->weight=w;
	h->tag=t;
	h->LeftChild=l;
	h->RightChild=r;
	h->Parent=p;
	return h;
}

void InitHuffmantree(Huffmantree *ht, int r)
{
	ht->root=r;
}

void makeHuffmantree(Huffmantree *ht,Huffmannode *b[],int n)
{
	int i,j,m1,m2,x1,x2;
	i=1;
	for(i;i<n;i++)
	{
		m1=m2=32767;
		x1=x2=-1;
		j=0;
		for(j;j<n+i-1;j++)
		{
			if(b[j]->weight<m1&&b[j]->tag==0)
			{
				m2=m1;
				x2=x1;	
				m1=b[j]->weight;
				x1=j;
			}
			else
			{
			if(b[j]->weight<m2&&b[j]->tag==0)
			{
				m2=b[j]->weight;
				x2=j;
			}
			}
		}
		b[x1]->tag=1;
		b[x2]->tag=1;
		b[x1]->Parent=n-1+i;
		b[x2]->Parent=n-1+i;
		
		b[n-1+i]->weight=b[x1]->weight + b[x2]->weight;
		b[n-1+i]->LeftChild=x1;
		b[n-1+i]->RightChild=x2;
		b[n-1+i]->tag=0; 
	
	}
	ht->root=2*n-2;
}


char* compose(char string[],Huffmannode *b[],Huffmantree *t,int p,int n)
{
	int x=-1,i=0,j=0;
	for(j;j<n;j++)
	{
		if(b[j]->weight==p) 
		{x=j;break;
		}
	}
	if(x==-1) return "";
	else
	{
	Huffmannode *w=b[b[x]->Parent];
	while(w->weight!=b[2*n-2]->weight)
	{
		if(b[w->LeftChild]==b[x]) 
		string[i++]='0';
		else
		string[i++]='1';
		w=b[w->Parent];
		x=b[x]->Parent;
	}
	if(b[w->LeftChild]==b[x]) 
	string[i++]='0';
	else
	string[i++]='1';
	return string;}
}

void reverse(char string[])
{
	int len=0;
	while(string[len]!='\0') len++;
	if(len==0) printf("Not Found!");
	else
	{
	int i=len-1; 
	for(i;i>=0;i--) printf("%c",string[i]);
	}
}

void transfer(Huffmannode *b[],char dest[],int n,int a[],char s[])
{
	int len=0;
	while(dest[len]!='\0') len++;
	Huffmannode *w=b[2*n-2];
	int i=0;
	for(i;i<=len;i++)
	{
		if(w->LeftChild==-1&&w->RightChild==-1) 
		{
			int k=0;char p;
			for(k;k<n;k++)
			{
				if(w->weight==a[k]) 
				{p=s[k];break;} 
			}
			printf("%c",p);
			//printf("%d ",w->weight);
			w=b[2*n-2];
			i=i-1;
		}
		else
		{
		if(dest[i]=='0')
			w=b[w->LeftChild];
		else 
			w=b[w->RightChild];
		}
	}
}

int main()
{
	int n=13;
	int a[13]={2,3,5,7,11,13,17,19,23,29,31,37,41};				//老师给的例子是{9,3,7,10,5,6,4,12,8} 
	char s[100]={"abcdefghijklm"};								//字符集{c1,c2,c3,c4,c5,c6,c7,c8,c9} 
	int i=0;
	Huffmannode *b[2*n-1]; 
	for(i;i<2*n-1;i++) 
	{
		if(i<n)
		b[i]=InitHuffmannode(a[i],0,-1,-1,-1);
		else
		b[i]=InitHuffmannode(0,0,-1,-1,-1);
	}
	Huffmantree *t=(Huffmantree*)malloc(sizeof(Huffmantree));
	InitHuffmantree(t,0);
	makeHuffmantree(t,b,n);
	
	int p;char d[100];
	
	printf("输入要编译的字：");
	scanf("%s",&d);
	int k=0;
	for(k;k<strlen(d);k++)
	{
		int m=0;char string[100]; 
		for(m;m<n;m++)
		{
			if(d[k]==s[m]) p=a[m];
		}
		compose(string,b,t,p,n);
		reverse(string);
		memset(string, '\0', 100);
	}
	printf("\n"); 
	char dest[100];
	printf("请输入要翻译的密码：");
	scanf("%s",&dest);
	transfer(b,dest,n,a,s);
	return 0;
}

