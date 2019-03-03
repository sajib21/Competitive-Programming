#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, ara[100005];
    scanf("%d", &n);
    ara[0] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i]);
        ara[i] += ara[i-1];
    }

    int ans = 0;
    for(int i=1; i<n; i++) {
        if(ara[i] == ara[n] - ara[i]) ans++;
    }

    printf("%d\n", ans);

    return 0;

}
