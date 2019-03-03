#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 1000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int n, w[LIM+10], cap[LIM+10];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &w[i]);
        for(int i=0; i<n; i++) scanf("%d", &cap[i]);
        sort(w, w+n);
        sort(cap, cap+n);

        ll ans = 1;
        for(int c=0, p=0; c<n; c++) {
            while(w[p] <= cap[c] && p < n) p++;
//            cout << p << endl;
            ans = (ans * (p-c) ) % MOD;
        }
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}
