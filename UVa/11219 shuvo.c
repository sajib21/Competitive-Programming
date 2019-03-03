#include<stdio.h>

int main()
{
        int bd, bm,by, cd, cm, cy, tc, i;
        float age;
        scanf("%d", &tc);
        for(i=1;i<=tc; i++){
                scanf("%d/%d/%d",&cd,&cm,&cy);
                scanf("%d/%d/%d",&bd,&bm,&by);
                age=(cy-by)+((cm-bm)*30+ (cd-bd))/365.0;
                if(age<0) printf("Case #%d: Invalid birth date\n",i);
                else if(age>130) printf("Case #%d: Check birth date\n",i);
                else printf("Case #%d: %d\n",i, (int)age);
        }
        return 0;
}
