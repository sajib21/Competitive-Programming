#include<stdio.h>
#include<string.h>
int main()
{
    char st[17],strev[17];
    int i,j,temp,a,n,len,t=1,num;
    while(scanf("%s",strev)==1)
    {
   for (len=0;strev[len]!='\0'; len++);
 // len=strlen(strev);
    for(i=0;i<len;i++)
    st[len-i-1]=strev[i];
    len--;

    printf("%4d.",t);
    t++;
    if(len==14)
    printf(" %d kuti",st[14]-48);

    if(len>=12)
    {
               num=st[12]-48;
               if(len>=13)
               num=num+10*(st[13]-48);
               if(num>0)
     printf(" %d lakh",num);
    }

        if(len>=10)
    {
               num=st[10]-48;
               if(len>=11)
               num=num+10*(st[11]-48);
               //num=num*10+st[11]-48;
               if(num>0)
     printf(" %d hajar",num);
    }

        if(len>=9)
    {
               num=st[9]-48;

               if(num>0)
     printf(" %d shata",num);
    }

       if(len>=7)
    {
               num=st[7]-48;
               if(len>=8)
               num=num+10*(st[8]-48);
             //  num=num*10+st[8]-48;
               if(num>0)
        printf(" %d",num);
     printf(" kuti");

    // printf(" %d kuti",num);
    }

       if(len>=5)
    {
               num=st[5]-48;
               if(len>=6)
                 num=num+10*(st[6]-48);
             //  num=num*10+st[6]-48;
               if(num>0)
     printf(" %d lakh",num);
    }

         if(len>=3)
    {
               num=st[3]-48;
               if(len>=4)
                 num=num+10*(st[4]-48);
               //num=num*10+st[4]-48;
               if(num>0)
     printf(" %d hajar",num);
    }
        if(len>=2)
    {
               num=st[2]-48;

               if(num>0)
     printf(" %d shata",num);
    }

           if(len>=0)
    {
               num=st[0]-48;
               if(len>=1)
                 num=num+10*(st[1]-48);
               //num=num*10+st[1]-48;
               if(num>0)
     printf(" %d",num);
    }
    if(len==0 && st[0]=='0')
    printf(" 0");
    printf("\n");

    }
    return 0;
}
