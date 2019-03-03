#include<bits/stdc++.h>

using namespace std;

double f[100005];

int main() {
    f[1] = 1;
    for(int i=2; i<=100000; i++) f[i] = 1.0/i + f[i-1];
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%.8f\n", f[n]);
    }
}
