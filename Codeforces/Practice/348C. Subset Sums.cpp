#include<bits/stdc++.h>
#define vi vector<ll>
#define pb(x) push_back(x)
#define LIM 100005
#define ll long lont int

using namespace std;

int n, sq, type[LIM], id[LIM];
ll x, a[LIM];
vector< vi > > light, heavy;
int intercet[350][LIM];

int main() {
    scanf("%d %d %d", &n,&m,&q); sq = sqrt(n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    for(int i=1; i<=m; i++) {
        scanf("%d", &k);
        vi temp;
        for(int j=0; j<k; j++) {
            scanf("%lld", &x);
            temp.pb(x);
        }
        sort(temp.begin(), temp.end());
        if(k < sq) {
            type[i] = 0;
            id[i] = light.size();
            light.pb(temp);
        }
        else {
            type[i] = 1;
            id[i] = heavy.size();
            heavy.pb(temp);
        }
    }

    for(int i=0; i<heavy.size(); i++) {
        for(int j=0; j<light.size(); j++) {

        }
    }
}
