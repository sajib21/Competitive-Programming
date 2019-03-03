#include<bits/stdc++.h>
#define pii pair<int,int>
#define ll long long int

using namespace std;

map<int,bool>visx,visy;
map<int,int>cntx,cnty;
map<pii,int>cnt;

int n,x,y;

int main() {
    scanf("%d", &n);
    ll ans = 0;
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x,&y);
        ans += cntx[x]; cntx[x]++;
        ans += cnty[y]; cnty[y]++;
        ans -= cnt[pii(x,y)]; cnt[pii(x,y)]++;
    }
    cout << ans << endl;
}
