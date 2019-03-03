
#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 50000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int r,c,w, total=0, x[LIM+10]={0}, y[LIM+10]={0};
        int m,n, q;
        scanf("%d %d %d", &m,&n, &q);
        while(q--) {
            scanf("%d %d %d", &r,&c,&w);
            x[r] += w;
            y[c] += w;
            total += w;
        }

        int i,j, cnt=0;
        for(i=0; i<=m && 2*cnt<total; ++i) {
            cnt += x[i];
        }
        cnt = 0;
        for(j=0; j<=n && 2*cnt<total; ++j) {
            cnt += y[j];
        }

        printf("Case %d: %d %d\n", t, i-1, j-1);
    }

    return 0;
}
