#include <stdio.h>
using namespace std;
int upperlim = 255;
int Ans=0;
void test(int row, int ld, int rd)  
  {  
      int pos, p;  
      if ( row != upperlim )  
      {  
          pos = upperlim & (~(row | ld | rd ));  
          while ( pos )  
          {  
              p = pos & (~pos + 1);  
             pos = pos - p;  
             test(row | p, (ld | p) << 1, (rd | p) >> 1);  
        }  
     }  
	      else  
         ++Ans;  
 } 


int main(){
    test(0, 0, 0);
    printf("%d\n", Ans);
}

