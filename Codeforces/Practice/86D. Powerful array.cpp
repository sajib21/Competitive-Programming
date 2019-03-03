#include<bits/stdc++.h>
#define LIM 200000
#define pb push_back
#define ll long long int

using namespace std;

int rootN, pos[LIM+10];

struct query {
    int l,r, indx;
};
bool cmp(query a, query b) {
//    int seg1 = a.l/rootN , seg2 = b.l/rootN;
    if(pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}

int ara[LIM+10], flag[LIM*5 + 10]; ///ara[LIM] nwar karone tle kn khaitasilam bujhlam na :/
query queries[LIM+10];
ll reslt[LIM+10];

int main() {

    int n,t;
    scanf("%d %d", &n,&t);
    rootN = sqrt(n);

    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    for(int i=1; i<=n; i++) pos[i] = i/rootN;
    for(int i=0; i<t; i++) {
        scanf("%d %d", &queries[i].l, &queries[i].r);
        queries[i].indx = i;
    }
    sort(queries, queries+t, cmp);

    int pl = 0, pr = 0;
    ll ans = 0;
    for(int i=0; i<t; i++) {
//        cout << "QUERY OF " << queries[i].l << ' ' << queries[i].r << endl;
        while(pr < queries[i].r) {
            pr++;
            ans = ans + 1ll*(2*flag[ ara[pr] ] + 1)*ara[pr];
            flag[ ara[pr] ]++;
        }
        while(pr > queries[i].r) {
            ans = ans + 1ll*(-2*flag[ ara[pr] ] + 1)*ara[pr];
            flag[ ara[pr] ]--;
            pr--;
        }
        while(pl < queries[i].l) {
            ans = ans + 1ll*(-2*flag[ ara[pl] ] + 1)*ara[pl];
            flag[ ara[pl] ]--;
            pl++;
        }
        while(pl > queries[i].l) {
            pl--;
            ans = ans + 1ll*(2*flag[ ara[pl] ] + 1)*ara[pl];
            flag[ ara[pl] ]++;
        }
        reslt[ queries[i].indx ] = ans;
    }
    for(int i=0; i<t; i++) printf("%I64d\n", reslt[i]);

    return 0;
}
