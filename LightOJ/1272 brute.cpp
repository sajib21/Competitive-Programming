#include<bits/stdc++.h>

using namespace std;

int ans;
int n,ara[110];

void f(int in, int v) {
    if(in == n) {
        ans = max(ans, v);
        return;
    }
    f(in+1, v^ara[in]);
    f(in+1, v);
}

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &ara[i]);
    ans = 0;
    f(0, 0);
    cout << ans << endl;
}
