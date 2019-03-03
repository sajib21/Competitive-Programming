#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define pp pop_back

using namespace std;

int n;
bool taken[20], prime[40];
vii ans;

void f(int last) {
    if(ans.size() == n) {
        if(prime[last+1]) {
            for(int i=0; i<ans.size(); i++) {
                if(i) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1; i<=n; i++) if(!taken[i] && prime[last+i]) {
        ans.pb(i); taken[i] = 1;
        f(i);
        ans.pp(); taken[i] = 0;
    }
}

int main() {
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = prime[37] = 1;
    int t = 1;
    taken[1] = 1; ans.pb(1);
    while(scanf("%d", &n) != EOF) {
        if(t > 1) printf("\n");
        printf("Case %d:\n", t++);
        f(1);
    }
    return 0;
}
