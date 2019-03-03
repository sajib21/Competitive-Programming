#include <stdio.h>
#include <math.h>

main()
{

    double a,b,t,i,fstep,f2step;
    scanf("%lf",&t);
    while(t)
    {
        scanf("%lf%lf",&a,&b);
        while(b)
        {
            for(i=1; i<=a; i++)
            {
                fstep=(i/9)*((pow(10,i))-1);
                printf ("%0.lf\n",fstep);
            }

            i=i-2;
            for(i; i>0; i--)
            {
                f2step=(i/9)*((pow(10,i))-1);
                printf ("%0.lf\n",f2step);
            }
            b--;
            if(b || t>1) printf("\n");
        }
        t--;
    }
    return 0;
}
