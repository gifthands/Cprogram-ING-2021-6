#include <stdio.h> 
int isLess(int x, int y) {
	int n1 = (y>>1)+~(x>>1)+1;
	int n2 = !( n1>>31 | !n1);
  return n2;

}
int reverseBytes(int x) {
	/*��ÿ���ֽڵ�������ȡ������λ��ǡ����λ��ʹ������ֽڵ���ת*/
	int m = ((x&0xFF)<<24) + ((x&0xFF00)<<8) + ((x&0xFF0000)>>8) +( ((x&0xFF000000)>>24) ) ;
	int n = ((x&0xFF)<<24) + ((x& ( (0xFF)<<8))<<8) + ((x& ( (0xFF)<<16))>>8) + ((x& ( (0xFF)<<24))>>24) ;
	printf("1:%d,  2:%d",m,n);
  return m;

}
int main() {
	/*�����ķ���λ��1���������0������31λ��������Ϊ-1��������0������1����ɹ� */
	int i=0xffffffff-0xfffffff1;
	//printf( "%d", i);
	int x = 0x7fffffff;
	reverseBytes(x);
  return 0;


}


