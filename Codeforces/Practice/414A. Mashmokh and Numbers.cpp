#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,k;

    scanf("%d %d", &n, &k);

    int p = n/2;

    if(n == 1 && k == 0) {
        printf("1\n");
        return 0;
    }

    if(k < p || n == 1) {
        printf("-1\n");
        return 0;
    }

    else {

        int t = k-p ;
        int i = 0;
        if(t) printf("%d %d ", t+1, (t+1)*2), i = 2;
int c = (t+1)*2+1;
        if(i < n) {

            printf("%d", c++); i++;
        }
        for(; i<n; i++) printf(" %d", c++);
        printf("\n");
    }

    return 0;
}
