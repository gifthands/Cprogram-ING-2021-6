#include <stdio.h>

#include <stdlib.h>

#include <iostream>

using namespace std;

enum boolean { FALSE, TRUE };

typedef  char ElementType;



struct stack

{

	int top;

	ElementType* elements;

	int MaxSize;

};
typedef stack Stack;

void InitStack(Stack*, int sz);
int Push(Stack* S, ElementType a);
ElementType Pop(Stack* S);
ElementType GetTop(Stack* S);
bool IsEmpty(Stack* S);
bool IsFull(Stack* S);
char* change(char S[], char a[]);



char* change(char S[], char a[])
{
	int i = 0, j = 0;
	Stack* s = new stack;
	InitStack(s, 100);
	while (S[i] != '\0')
	{
		switch (S[i])
		{
		case '+':
			while (!IsEmpty(s) && GetTop(s) != '(')
			{
				a[j] = Pop(s);
				j++;
			}
			Push(s, S[i]);
			break;
		case '-':
			while (!IsEmpty(s) && GetTop(s) != '(')
			{
				a[j] = Pop(s);
				j++;
			}
			Push(s, S[i]);
			break;
		case '*':
			while (!IsEmpty(s) && GetTop(s) == ('*' || '/'))
			{
				a[j] = Pop(s);
				j++;
			}
			Push(s, S[i]);
			break;
		case '/':
			while (!IsEmpty(s) && GetTop(s) == ('*' || '/'))
			{
				a[j] = Pop(s);
				j++;
			}
			Push(s, S[i]);
			break;
		case '(':
			Push(s, S[i]);
			break;
		case ')':
			while (GetTop(s) != '(')
			{
				a[j] = Pop(s);
				j++;
			}
			Pop(s);
			break;
		default:
			a[j] = S[i];
			j++;
		}
		i++;
	}
	while (!IsEmpty(s))
	{
		a[j] = Pop(s);
		j++;
	}
	return a;
}
bool IsEmpty(Stack* S)
{
	return (bool)(S->top == -1);
}
bool IsFull(Stack* S)
{
	return (bool)(S->top == S->MaxSize - 1);
}
void InitStack(Stack* S, int sz)
{
	S->MaxSize = sz;
	S->elements = (ElementType*)malloc(sizeof(ElementType) * S->MaxSize);
	S->top = -1;
}
int Push(Stack* S, ElementType item)
{
	if (!IsFull(S))
	{
		S->elements[++(S->top)] = item;
		return 0;
	}
	else return -1;
}
ElementType Pop(Stack* S)
{
	if (!IsEmpty(S))
		return S->elements[(S->top)--];
}
ElementType GetTop(Stack* S)
{
	if (!IsEmpty(S))
		return S->elements[S->top];
	else
	{
		printf("stack is empty!\n");
		exit(1);
	}
}
int main()
{
	char S[100];
	cin >> S;
	int i = 0;
	char a[100];
	printf(change(S, a));
	return 0;
}
