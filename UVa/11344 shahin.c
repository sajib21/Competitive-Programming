#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main()
{
    char str[1050];
    int i,j,k,l,t,n,ara[12],count,len,sum,sum1,m,num;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        count=0;
        scanf("%s",&str);
        len = strlen(str);
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d",&ara[j]);
        }
        if(len<10){
            num = atoi(str);
            count = 0;
            for(l=0;l<n;l++){
                if(num % ara[l] == 0){
                    count++;
                }
            }
            if(count != n){
                printf("%s - Simple.\n",str);
            }
            else{
                printf("%s - Wonderful.\n",str);
            }

        }
        else{
            for(l=0;l<n;l++){
                switch(ara[l]){
                    case 1:
                        count++;
                        break;
                    case 2:
                        if( (str[len-1]-48) % 2 == 0){
                            count++;
                        }
                        break;
                    case 3:
                        sum = 0;
                        for(k=0;k<len;k++){
                            sum += (str[k]-48);
                        }
                        if(sum % 3 == 0){
                            count++;
                        }
                        break;
                    case 4:
                        sum = 0;
                        sum = (str[len-1]-48)+ 10*(str[len-2]-48);
                        if(sum % 4 == 0){
                            count++;
                        }
                        break;
                    case 5:
                        if( (str[len-1]-48)== 0 || (str[len-1]-48) == 5 ){
                            count++;
                        }
                        break;
                    case 6:
                        sum = 0;
                        for(k=0;k<len;k++){
                            sum += (str[k]-48);
                        }
                        if( ((str[len-1]-48) % 2 == 0) && (sum % 3 == 0)){
                            count++;
                        }
                        break;
                    case 7:
                        sum = 0;
                        for(k=len-1,m=0;k>=0;k--,m++){
                            if( m % 6 == 0){
                                sum += (str[k]-48);
                            }
                            else if( m % 6 == 1){
                                sum += (3*(str[k]-48));
                            }
                            else if( m % 6 == 2){
                                sum += (2*(str[k]-48));
                            }
                            else if( m % 6 == 3){
                                sum += (6*(str[k]-48));
                            }
                            else if( m % 6 == 4){
                                sum += (4*(str[k]-48));
                            }
                            else if( m % 6 == 5){
                                sum += (5*(str[k]-48));
                            }
                        }
                        if(sum % 7 == 0){
                            count++;
                        }
                        break;
                    case 8:
                        sum = 0;
                        sum = (str[len-1]-48)+ 10*(str[len-2]-48) + 100*(str[len-3]-48);
                        if(sum % 8 == 0){
                            count++;
                        }
                        break;
                    case 9:
                        sum = 0;
                        for(k=0;k<len;k++){
                            sum += (str[k]-48);
                        }
                        if(sum % 3 == 0){
                            count++;
                        }
                        break;
                    case 10:
                        if((str[len-1]-48)==0){
                            count++;
                        }
                        break;
                    case 11:
                        sum = 0;
                        for(k=0;k<len;k++){
                            if(k % 2 == 0){
                                sum += (str[k]-48);
                            }
                            else{
                                sum -= (str[k]-48);
                            }
                        }
                        if(sum % 11 == 0){
                            count++;
                        }
                        break;
                    case 12:
                        sum = 0;
                        for(k=0;k<len;k++){
                            sum += (str[k]-48);
                        }
                        sum1 = (str[len-1]-48)+ 10*(str[len-2]-48);
                        if(sum % 3 == 0 && sum1 % 4 == 0){
                            count++;
                        }
                        break;
                }
            }
            if(count != n){
                printf("%s - Simple.\n",str);
            }
            else{
                printf("%s - Wonderful.\n",str);
            }
        }
    }
    return 0;
}
