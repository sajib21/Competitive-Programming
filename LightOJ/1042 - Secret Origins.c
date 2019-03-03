#include <stdio.h>
#include <math.h>

int main()
{
    int t,T, n,temp, i,j, one,zero, change=0;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        one=0; zero=0; change=0;
        scanf("%d", &n);
        temp=n; i=0;
        while(!(temp%2))
        {
            zero++;
            temp/=2;
            i++;
        }

        for(j=i;  ; j++)
        {
            if(!(temp%2))
            {
                change+=(int) pow(2,j-1);
                one--;
                break;
            }
            else one++;
            temp/=2;
        }
        j-=2; i=0;
        while(one && zero)
        {
            change-= (int) (pow(2,j)-pow(2,i));
            one--; zero--;
            j--; i++;
        }

        printf("Case %d: %d\n", t,n+ change);
    }
    return 0;
}
