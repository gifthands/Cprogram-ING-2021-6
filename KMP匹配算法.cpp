// KMP模式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <string.h>
void GetNext(char s[], int next[], int len);   //读取一个字符对应的Next列表；


int main()
{
	char s[100];
	int next[100];			//需要获得的对应next数组；
	printf("请输入字符子串：");
	scanf_s("%s", &s, 100);
	GetNext(s, next, strlen(s));
	for (int i = 0; i < strlen(s); i++)
		printf("%d", next[i]);
	return 0;
}

//下面是KMP算法的next数组的获取方式；
void GetNext(char s[], int next[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int k = 0;					//即为需要求的最大前缀和后缀的公子串；
		if (i == 0)
			k = -1;
		else if(i == 1)
			k = 0;
		else
		{
			while (s[k] != s[i])
				k = s[k];					//回溯到匹配的一点；
			k++;
		}
		next[i] = k;				//这是求出的next的值；
	}
}



