#include <stdio.h>
typedef char ElementType;
enum boolean{FALSE,TRUE};
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

void InitBinaryTree(BinaryTree* bt)
{
	bt->root = NULL;
}
Bool IsEmpty(BinaryTree* bt)
{
	return ((bt->root) ? FALSE : TRUE);
}
Bool getroot(BinaryTree* bt, ElementType* x)
{
	if (bt->root)
	{
		*x = bt->root->data;
		return TRUE;
	}
	else
		return FALSE;
}
BinaryTreeNode* MakeTree(BinaryTree* bt, ElementType element, BinaryTreeNode* left, BinaryTreeNode* right)
{
	bt->root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	if (bt->root == NULL)
	{
		printf("Memory allocation failure!\n");
		exit(1);
	}
	InitBinaryTreeNode(bt->root, element, left, right);
	return bt->root;
}

void RNL(BinaryTreeNode* t)
{
	BinaryTreeNode* stack[100];
	int top = 0;
	stack[0] = t;
	do
	{
		while (stack[top] != NULL)
			stack[++top] = stack[top]->RightChild;
		if (top > 0)
		{
			printf("%c", stack[--top]->data);
			stack[top] = stack[top]->LeftChild;
		}
	} while (top > 0 || stack[top] != NULL);
}


int main()
{
	BinaryTree* t = (BinaryTree*)malloc(sizeof(BinaryTree));
	BinaryTreeNode* A, * B, * C, * D, * E, * F;
	F = MakeTree(t, 'F', NULL, NULL);
	E = MakeTree(t, 'E', NULL, F);
	C = MakeTree(t, 'C', E, NULL);
	D = MakeTree(t, 'D', NULL, NULL);
	B = MakeTree(t, 'B', NULL, D);
	A = MakeTree(t, 'A', B, C);
	RNL(t->root);
	return 0;
}
