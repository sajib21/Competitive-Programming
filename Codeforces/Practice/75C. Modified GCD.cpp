#include<bits/stdc++.h>
#define vi      vector<int>
#define pb(x)   push_back(x)

using namespace std;

int main() {
    int a,b,g,n, l,r, sq;
    vi div;

    scanf("%d %d %d", &a,&b,&n);

    g = __gcd(a,b);
    sq = sqrt(g);
    for(int i=1; i<=sq; i++) {
        if(g%i==0) {
            div.pb(i);
            div.pb(g/i);
        }
    }
    sort(div.begin(), div.end());

    while(n--) {
        scanf("%d %d", &l,&r);
        int x = upper_bound(div.begin(), div.end(), r) - div.begin();
        x--;
        if(x >= 0 && l <= div[x] && div[x] <= r) printf("%d\n", div[x]);
        else printf("-1\n");
    }
}
