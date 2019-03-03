#include<bits/stdc++.h>
#define ll      long long int
#define LIM     300005
#define MAX     1000
#define segVar  int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2
#define pii     pair<ll,ll>
#define ff      first
#define ss      second
#define vi      vector<int>
#define pb(x)   push_back(x)

using namespace std;

bool isPrime[1010];
vi primes;

void gen() {
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=MAX; i+=2) isPrime[i] = 1;
    primes.pb(2);
    for(int i=3; i<=MAX; i+=2) {
        if(isPrime[i]) continue;
        primes.pb(i);
        for(int j=i+i; j<=MAX; j+=i) isPrime[j] = 1;
    }
}

int f(int x) {
    int ans = 1;
    for(int i=0; i<primes.size() && primes[i]*primes[i] <= x; i++) {
        int p = primes[i];
        int cnt = 0;
        while(x % p == 0) {
            x /= p;
            cnt++;
        }
        ans *= cnt+1;
    }
    if(x > 1) ans *= 2;
    return ans;
}

int n, m, a[LIM];
pii segTree[6*LIM];

pii operator + (pii a, pii b) {
    return pii(a.ff+b.ff, a.ss+b.ss);
}

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].ff = a[st];
        if(a[st] > 2) segTree[node].ss = 1;
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    segTree[node] = segTree[lft]+segTree[rgt];
}

void update(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r || !segTree[node].ss) return;
    if(st == ed) {
        segTree[node] = pii(0,0);
        a[st] = f(a[st]);
        segTree[node].ff = a[st];
        if(a[st] > 2) segTree[node].ss = 1;
        return;
    }
    segVar;
    if(st >= l && ed <= r) {
        if(segTree[lft].ss) update(lft,   st,md, l,r);
        if(segTree[rgt].ss) update(rgt, md+1,ed, l,r);
    }
    else {
        update(lft,   st,md, l,r);
        update(rgt, md+1,ed, l,r);
    }
    segTree[node] = segTree[lft]+segTree[rgt];
}

ll query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node].ff;
    segVar;
    return query(lft, st,md, l,r)+query(rgt,md+1,ed, l,r);
}


int main() {
    gen();
    scanf("%d %d", &n,&m);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    init(1, 1,n);
    while(m--) {
        int x,y,z;
        scanf("%d %d %d", &x,&y,&z);
        if(x == 1) update(1, 1,n, y,z);
        else printf("%lld\n", query(1, 1,n, y,z));
    }
}
