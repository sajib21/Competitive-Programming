#include <stdio.h>
unsigned long num1[1000000],num2[1000000],res[1000000];
int main()
{
    unsigned long long int i,j,block,digit,n1,n2,d;
    scanf("%llu",&block);
    for(i=0;i<block;i++){
     scanf("%llu",&digit);
     for(j=0;j<digit;j++){
      scanf("%llu %llu",&n1,&n2);
      num1[j]=n1;
      num2[j]=n2;
     }
     for(j=0;j<digit+1;j++){
      res[j]=res[j]+num1[j]+num2[j];
      if(res[j]>=10){
       res[j+1]=res[j]/10;
       res[j]=res[j]%10;

      }

     }
     for(j=digit;j>=0;j--){
      d=res[j];
      printf("%d",d);
     }


    }


    return 0;
}
