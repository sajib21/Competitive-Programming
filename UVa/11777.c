#include <stdio.h>

int main()
{
     int n,i, t1,t2,tf,a, ct1,ct2,ct3, total, ct;

    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &tf, &a, &ct1, &ct2, &ct3);
        if(ct1<=ct2 && ct1<=ct3) ct=(ct2+ct3)/2;
        else if(ct2<=ct1 && ct2<=ct3) ct=(ct1+ct3)/2;
        else ct=(ct1+ct2)/2;

        total=t1+t2+tf+a+ct;

        printf("Case %d: ", i);

        if(total>=90) printf("A\n");
        else if(total>=80 && total<90) printf("B\n");
        else if(total>=70 && total<80) printf("C\n");
        else if(total>=60 && total<70) printf("D\n");
        else printf("F\n");
    }

    return 0;
}
