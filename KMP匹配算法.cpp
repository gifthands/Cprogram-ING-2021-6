// KMPģʽƥ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <stdio.h>
#include <string.h>
void GetNext(char s[], int next[], int len);   //��ȡһ���ַ���Ӧ��Next�б�


int main()
{
	char s[100];
	int next[100];			//��Ҫ��õĶ�Ӧnext���飻
	printf("�������ַ��Ӵ���");
	scanf_s("%s", &s, 100);
	GetNext(s, next, strlen(s));
	for (int i = 0; i < strlen(s); i++)
		printf("%d", next[i]);
	return 0;
}

//������KMP�㷨��next����Ļ�ȡ��ʽ��
void GetNext(char s[], int next[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int k = 0;					//��Ϊ��Ҫ������ǰ׺�ͺ�׺�Ĺ��Ӵ���
		if (i == 0)
			k = -1;
		else if(i == 1)
			k = 0;
		else
		{
			while (s[k] != s[i])
				k = s[k];					//���ݵ�ƥ���һ�㣻
			k++;
		}
		next[i] = k;				//���������next��ֵ��
	}
}



