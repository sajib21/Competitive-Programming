#include<bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c;
    while( scanf("%d %d %d", &b,&a,&c) != EOF ) {
        int n = a + b;
        printf("%.5lf\n", 1.0*a/n*(a-1)/(n-1-c) + 1.0*b/n*a/(n-1-c) );

    }
    return 0;
}
