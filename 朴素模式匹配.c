//ע��
    //1:�ó���ÿ�����е�ʱ�����С��10�룬����ᳬʱ,����ʱ���������ʣ��Ĳ��Լ�
    //2:�ó���ÿ������ʹ�õ��ڴ治�ܳ���1M������᷵�ش���
    //3:�ó���ÿ����������Ľ�������ʾ1000���ַ�(����Ĳ���ʾ),ÿ��ĩβ�����пո��á���ʾ
#include <stdio.h>
int main()
{
  //��ȡ������ʽ scanf
  //int x  =0;
  //int y = 0;
  //scanf("%d", &x);
	char T[100], P[100];
	scanf("%s", &P);		//�Ӵ� 
	scanf("%s", &T);		//ĸ�� 
	printf("%d",Search(P, T));
  //������ʹ��prinf
  //printf("%d",x);

  return 0;
}


int Search(char P[], char T[])
{
	char *t=T, *p=P;
	int i=0,j=0,x=0,count=0,Plen=0,Tlen=0;
	while(*(t+i++)!='\0')	Tlen++;			//��Ŀ�괮���� 
	while(*(p+j++)!='\0')	Plen++;			//��Ŀ�괮���� 
	i=j=0;
  //��Ҫ˼��������ģʽƥ��
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

