#pragma warning(disable:4703)
#include <iostream>
using namespace std;
typedef int ElementType;
enum boolean { FALSE, TRUE };
typedef enum boolean Bool;
struct binaryTreeNode
{
	ElementType data;
	struct binaryTreeNode* LeftChild, * RightChild;
};
typedef struct binaryTreeNode BinaryTreeNode;
struct binaryTree
{
	BinaryTreeNode* root;
};
typedef struct binaryTree BinaryTree;
struct binarySTree
{
	BinaryTreeNode* root;
};
typedef struct binarySTree BinarySTree;

void InitBinaryTreeNode(BinaryTreeNode* btree, ElementType e, BinaryTreeNode* l, BinaryTreeNode* r)
{
	btree->LeftChild = l;
	btree->RightChild = r;
	btree->data = e;
}



BinaryTreeNode* CreateNode(ElementType x, BinaryTreeNode* a, BinaryTreeNode* b)
{
	BinaryTreeNode* p = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p->data = x;
	p->LeftChild = a;
	p->RightChild = b;
	return p;
}

BinaryTreeNode* make_bst(BinaryTreeNode* r, int data[], int len)
{
	BinaryTreeNode* p, * q, * s;
	int i = 1;
	r = NULL;

	p = CreateNode(data[0], NULL, NULL);
	r = p;

	for (i; i < len; i++)
	{
		q = CreateNode(data[i], NULL, NULL);
		p = r;
		while (p != NULL)
		{
			s = p;
			if (q->data < p->data) p = p->LeftChild;
			else p = p->RightChild;
		}
		if (q->data < s->data) s->LeftChild = q;
		else s->RightChild = q;
	}
	return r;
}

void ins_bst(BinaryTreeNode* p, BinaryTreeNode** q)
{
	if (*q == NULL)
		* q = p;
	else if (p->data < (*q)->data)
		ins_bst(p, &((*q)->LeftChild));
	else
		ins_bst(p, &((*q)->RightChild));
}

//打印对称序
void InOrder(BinaryTreeNode* t)
{
	if (t)
	{
		InOrder(t->LeftChild);
		printf("%d", t->data);
		InOrder(t->RightChild);
	}
}


//可以打印树状图
void RNL(BinaryTreeNode* t)
{
	BinaryTreeNode* stack[100];
	int top = 0, n[100];
	stack[0] = t;
	n[0] = 0;
	do
	{
		while (stack[top] != NULL)
		{
			stack[top + 1] = stack[top]->RightChild;
			n[top + 1] = n[top] + 1;
			top++;
		}
		if (top > 0)
		{
			for (int i = 0; i < n[top - 1]; i++)
				printf("        ");
			printf("%d\n", stack[--top]->data);
			n[top] = n[top] + 1;
			stack[top] = stack[top]->LeftChild;

		}
	} while (top > 0 || stack[top] != NULL);
}


//删除节点函数
BinaryTreeNode* delet_bst1(BinaryTreeNode* root, BinaryTreeNode* p, BinaryTreeNode* f)   //根节点root，待删节点p，p的父节点f
{
	BinaryTreeNode* s=NULL, * t = NULL, * sr = NULL;   //s是被删除节点的对称序后继，sr是s的右子树，t是s的父节点
	if (p->RightChild == NULL)             //若p右子树为空
		if (f == NULL)		root = p->LeftChild;    //p是否为根节点
		else if (f->LeftChild == p)					//p为父节点的左子女
			f->LeftChild = p->LeftChild;
		else                                                     //p为父节点的右子女
			f->RightChild = p->LeftChild;
	else                                     //若p的右子树不为空
	{
		s = p->RightChild;
		t = p;
		while (s && s->LeftChild != NULL)        //循环找到p对称序后继以及其父节点和右子女
		{
			t = s;
			s = s->LeftChild;
		}
		sr = s->RightChild;
		if (f == NULL)                          //p为根节点
		{
			root = s;
			root->LeftChild = p->LeftChild;
			root->RightChild = p->RightChild;
			t->LeftChild = sr;
		}
		else if (f->LeftChild == p)             //p为父节点的左子女
		{
			f->LeftChild = s;
			s->LeftChild = p->LeftChild;
			if (s != p->RightChild)	s->RightChild = p->RightChild;      //如果s不是p的右子女的话，避免造成s与s连
			t->LeftChild = sr;
		}
		else                                         //p为父节点的右子女
		{
			f->RightChild = s;
			s->LeftChild = p->LeftChild;
			if (s != p->RightChild)	s->RightChild = p->RightChild;            //如果s不是p的右子女的话，避免造成s与s连
			t->LeftChild = sr;
		}
	}
	return root;             //返回其树根
}

int main()
{
	BinaryTree* a=(BinaryTree*)malloc(sizeof(BinaryTree));
	int data[7] = { 10,5,15,2,6,12,18 },j=0;
	BinaryTreeNode* b = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	BinaryTreeNode* n[7],*x;
	for (j; j < 7; j++)
	{
		n[j] = CreateNode(data[j], NULL, NULL);
		/*n[j]->data = data[j];
		n[j]->LeftChild = NULL;
		n[j]->RightChild = NULL;*/
	}
	a->root = n[0];
	
	int i = 1,k=0;
	for (i; i < 7; i++)
	{
		//BinaryTreeNode* t = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
		ins_bst(n[i], &b);
	}
	printf("\n原二叉树\n");
	InOrder(a->root);
	printf("\n");
	RNL(a->root);
	x = n[0];
	printf("\n删除节点%d后，二叉树的形状打印图\n", x->data);
	a->root = delet_bst1(a->root, x,NULL);
	InOrder(a->root);
	printf("\n");
	RNL(a->root);
	return 0;
}
