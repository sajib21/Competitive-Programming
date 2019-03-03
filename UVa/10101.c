#include <stdio.h>
#include <string.h>

int main()
{
    char take[17], num[17];
    int c=1;
    while((scanf("%s", num))==1)
    {
        int len=strlen(num), i=0;
        printf("%4d.", c);
        c++;
        switch(len)
        {
            case 15: if(num[i]!='0') printf(" %c kuti", num[i]); i++;
            case 14: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 13: if((num[i-1]!='0' && i) || (num[i-1]=='0' && num[i]!='0')) printf("%c lakh", num[i]); i++;
            case 12: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 11: if((num[i-1]!='0' && i) || (num[i-1]=='0' && num[i]!='0')) printf("%c hajar", num[i]); i++;
            case 10: if(num[i]!='0') printf(" %c shata", num[i]); i++;
            case 9: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 8: if((num[i-1]!='0' && i) || (num[i-1]=='0' && num[i]!='0')) printf("%c", num[i]); printf(" kuti");  i++;
            case 7: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 6: if((num[i-1]!='0' && i) || (num[i-1]=='0' && num[i]!='0')) printf("%c lakh", num[i]); i++;
            case 5: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 4: if((num[i-1]!='0' && i) || (num[i-1]=='0' && num[i]!='0')) printf("%c hajar", num[i]); i++;
            case 3: if(num[i]!='0') printf(" %c shata", num[i]); i++;
            case 2: if(num[i]!='0') printf(" %c", num[i]); i++;
            case 1: if(num[i-1]!='0' || (num[i-1]=='0' && num[i]!='0')) printf("%c", num[i]);
        }
        printf("\n");
    }
    return 0;
}
