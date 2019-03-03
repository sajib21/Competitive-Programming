///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             1000000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

using namespace std;

int n,k, ara[LIM+10];

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &ara[i]);
    scanf("%d", &k);

    deque<int>dq;

    for(int i=0; i<k-1; i++) {
        while(!dq.empty() && ara[dq.back()] < ara[i]) dq.pop_back();
        dq.push_back(i);
//        cout << "PUSH"
    }
    for(int i=k-1; i<n; i++) {
        while(!dq.empty() && ara[dq.back()] < ara[i]) dq.pop_back();
        dq.push_back(i);
        if(i > k-1) printf(" ");
        printf("%d", ara[dq.front()]);
        while(!dq.empty() && dq.front() <= i-k+1) dq.pop_front();
    }
    printf("\n");

    return 0;
}
