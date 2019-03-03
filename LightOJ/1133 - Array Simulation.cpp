#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int n,m;
        ll ara[110];
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++) scanf("%lld", &ara[i]);
        while(m--) {
            getchar();
            char c;
            ll d;
            scanf("%c", &c);
            if(c=='S') {
                scanf("%lld", &d);
                for(int i=0; i<n; i++) ara[i] += d;
            }
            else if(c=='M') {
                scanf("%lld", &d);
                for(int i=0; i<n; i++) ara[i] *= d;
            }
            else if(c=='D') {
                scanf("%lld", &d);
                for(int i=0; i<n; i++) ara[i] /= d;
            }
            else if(c=='R') {
                for(int i=0; i<n/2; i++) swap(ara[i], ara[n-i-1]);
            }
            else {
                int a,b;
                scanf("%d %d", &a,&b);
                swap(ara[a], ara[b]);
            }
//            for(int i=0; i<n; i++) printf(" %d", ara[i]);
//            printf("\n");
        }
        printf("Case %d:\n%lld", t, ara[0]);
        for(int i=1; i<n; i++) printf(" %d", ara[i]);
        printf("\n");
    }
    return 0;
}
