///KEEP INDICES OF IN CELLS CONTAINING VALUES IN A VECTOR FOR EACH VALUE.
///FOR EACH QUERY, BS FROM 1 TO 1000 TO FIND THE VALUE IN QUERY RANGE AND UPDATE
///O(q*maxVal*log n)


#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int n,sq, q, ara[LIM+10];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n, &q);
        vii pos[1010];
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            pos[x].pb(i);
        }
        printf("Case %d:\n", t);

        while(q--) {
            int last = -1;
            int ans = INT_MAX;
            int s,e;
            scanf("%d %d", &s,&e);
            for(int i=1; i<=1000; i++) {
                int cnt = upper_bound(pos[i].begin(), pos[i].end() , e) - lower_bound(pos[i].begin(), pos[i].end(), s);
//                if(cnt > 0) cout << "FOUND " << i << " " << cnt << endl;
                if(cnt > 1) {
                    ans = 0;
                    break;
                }
                else if(cnt == 1) {
                    if(last != -1) ans = min(ans, i - last);
                    last = i;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
