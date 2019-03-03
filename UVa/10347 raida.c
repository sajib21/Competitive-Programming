#include <stdio.h>
#include <math.h>
int main()
{
    double m1,m2,m3,a,area,s;
    while(scanf("%lf %lf %lf",&m1,&m2,&m3)==3){
        s=(m1+m2+m3)/2.0;
        a=(s)*(s-m1)*(s-m2)*(s-m3);
        if(a>0){
         area=(4/3.0)*sqrt(a);
        }
        else{
          area=-1.0;
        }
        printf("%.3lf\n",area);
    }
    return 0;
}
