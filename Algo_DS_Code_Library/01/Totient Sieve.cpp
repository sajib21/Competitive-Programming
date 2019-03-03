#include <stdio.h>
#define MAX 2000100
int phi[MAX] ;
void sievePHI(){
    long long i,j;
    for( i=2;i<MAX;i++){
        if( phi[i]==0){
            phi[i] = i-1;
            for( j = i*2; j<MAX; j+=i){
                if( phi[j] == 0 )phi[j] = j;
                phi[j] /= i ;
                phi[j] *= (i-1) ;
            }
        }
    }
}
int main() {
    int T;
//    printf("Koi ta number er Phi function er value jante chan?\n");
    scanf("%d", &T);
    sievePHI();
    while (T--) {
        int in;
//        printf("A number please: ");
        scanf("%d", &in);
        printf("%d\n", phi[in]);
    }
    return 0;
}
