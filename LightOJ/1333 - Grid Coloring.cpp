#include<bits/stdc++.h>
#define pii pair<int,int>
#define LIM 1000000
#define MOD 1000000000LL
#define ll long long int

using namespace std;

ll m,n,k,b;
pii blocks[1000];
ll mod = 1000000000LL;

bool cmp(pii a, pii b) {
    if(a.second == b.second) a.first < b.first;
    return a.second < b.second;
}

ll bigMod(ll n, ll r, ll mod) {
    if(!n) return 1;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1, mod)*n) % mod;
    ll ans = bigMod(n, r/2, mod);
    return (ans*ans) % mod;
}

int main() {

//    freopen("1333 Inn.txt", "r", stdin);
//    freopen("1333 Out.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ll ans = 1, two=0, tre=0;
        memset(blocks, 0, sizeof(blocks));
        scanf("%lld %lld %lld %lld", &m,&n,&k,&b);
        two = (m-1)*n;
        tre = n;
        for(int i=1; i<=b; i++) scanf("%d %d", &blocks[i].second, &blocks[i].first);

        sort(blocks+1, blocks+b+1);
//        cout << "SORTED " << endl;
//        for(int i=1; i<=b; i++) cout << blocks[i].second << ' ' << blocks[i].first << endl;

//        cout << "SHURU " << tre << ' ' << two << endl;
        for(int i=1; i<=b; i++) {
//            cout << "EKHON " << blocks[i].second << ' ' << blocks[i].first ;
            if(blocks[i].second == m)
//            if(tre)
                tre--;
            else
//            if(two)
            two--;

//            cout << " MAJHE " << tre << ' ' << two << endl;
            if( blocks[i].second == 1 || (blocks[i].first == blocks[i-1].first && blocks[i].second-1 == blocks[i-1].second) ) continue;

            if(two) {
                two--;
                tre++;
            }

//            cout << " INFO " << tre << ' ' << two << endl;
        }

//        cout << tre << ' ' << two << endl;
//        tre = max(0LL, tre); two = max(0LL, two);
        if(k==1) {
            if(!two) printf("Case %d: 1\n", t);
            else printf("Case %d: 0\n", t);
        }
        else
            printf("Case %d: %lld\n", t, (bigMod(k, tre, mod) * bigMod(k-1, two, mod)) % mod );
    }
    return 0;
}
