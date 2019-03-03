#include<bits/stdc++.h>

using namespace std;

int n, d;

int f(int level, int in, int rem) {
    if(level == d) return in;
    if(rem&1) return f(level+1, 2*in, (rem+1)/2);
    else return f(level+1, 2*in+1, rem/2);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &d, &n);
        printf("%d\n", f(1, 1, n) );
    }
    return 0;
}
