//注意
    //1:该程序每次运行的时间必须小于10秒，否则会超时,程序超时将不会测试剩余的测试集
    //2:该程序每次运行使用的内存不能超过1M，否则会返回错误
    //3:该程序每次运行输出的结果最多显示1000个字符(多余的不显示),每行末尾的所有空格用□表示
#include <stdio.h>
int main()
{
  //获取参数方式 scanf
  //int x  =0;
  //int y = 0;
  //scanf("%d", &x);
	char T[100], P[100];
	scanf("%s", &P);		//子串 
	scanf("%s", &T);		//母串 
	printf("%d",Search(P, T));
  //结果输出使用prinf
  //printf("%d",x);

  return 0;
}


int Search(char P[], char T[])
{
	char *t=T, *p=P;
	int i=0,j=0,x=0,count=0,Plen=0,Tlen=0;
	while(*(t+i++)!='\0')	Tlen++;			//求目标串长度 
	while(*(p+j++)!='\0')	Plen++;			//求目标串长度 
	i=j=0;
  //主要思想是朴素模式匹配
	for(i;i<=Tlen-Plen;i++)
	{
		for(j;j<Plen;j++)
		{
			if(*(t+i+j)==*(p+j))
				count++;
		}
		if(count==Plen)
			return i;
		j=0;
		count=0;
	}
	return -1;
}

