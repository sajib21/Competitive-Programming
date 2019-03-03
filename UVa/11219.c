#include <stdio.h>

int main()
{
    int t,i, cd,cm,cy, bd,bm,by, age,m,d;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d/%d/%d", &cd, &cm, &cy);
        scanf("%d/%d/%d", &bd, &bm, &by);

        age=cy-by;
        if(!age)
        {
            m=cm-bm;
            if(!m)
            {
                d=cd-bd;
                if(d<0) printf("Case #%d: Invalid birth date\n", i);
                else printf("Case #%d: 0\n", i);
            }
            else if(m>0) printf("Case #%d: 0\n", i);
            else printf("Case #%d: Invalid birth date\n", i);
        }
        else if(age<0) printf("Case #%d: Invalid birth date\n", i);
        else
        {
            m=cm-bm;
            if(!m)
            {
                d=cd-bd;
                if(d>=0)
                {
                    if(age<=130) printf("Case #%d: %d\n",i, age);
                    else printf("Case #%d: Check birth date\n", i);
                }
                else
                {
                    if(age<=131) printf("Case #%d: %d\n",i, age-1);
                    else printf("Case #%d: Check birth date\n", i);
                }
            }
            else if(m<0)
                {
                    if(age<=131) printf("Case #%d: %d\n",i, age-1);
                    else printf("Case #%d: Check birth date\n", i);
                }
            else
            {
                if(age<=130) printf("Case #%d: %d\n",i, age);
                else printf("Case #%d: Check birth date\n", i);
            }
        }
    }
    return 0;
}
