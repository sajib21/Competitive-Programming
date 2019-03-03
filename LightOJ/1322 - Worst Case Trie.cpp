#include<bits/stdc++.h>
#define ui unsigned int
#define ll long long int

using namespace std;

int perm[10010];

int main() {

    perm[0] = 1;
    for(int i=1; i<10000; i++) perm[i] = (1 + i*perm[i-1]) % 10000;

    int T, n;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        int ans = perm[n%10000];
        if(n <= 5) printf("Case %d: %d\n", t, ans);
        else printf("Case %d: %04d\n", t, ans);
    }
    return 0;
}
