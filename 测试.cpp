#include <stdio.h> 
int isLess(int x, int y) {
	int n1 = (y>>1)+~(x>>1)+1;
	int n2 = !( n1>>31 | !n1);
  return n2;

}
int reverseBytes(int x) {
	/*将每个字节的数字提取出来，位移恰当的位数使其完成字节的逆转*/
	int m = ((x&0xFF)<<24) + ((x&0xFF00)<<8) + ((x&0xFF0000)>>8) +( ((x&0xFF000000)>>24) ) ;
	int n = ((x&0xFF)<<24) + ((x& ( (0xFF)<<8))<<8) + ((x& ( (0xFF)<<16))>>8) + ((x& ( (0xFF)<<24))>>24) ;
	printf("1:%d,  2:%d",m,n);
  return m;

}
int main() {
	/*复数的符号位是1，其余的是0，右移31位，负数变为-1，其余是0，都加1，则成功 */
	int i=0xffffffff-0xfffffff1;
	//printf( "%d", i);
	int x = 0x7fffffff;
	reverseBytes(x);
  return 0;


}


