#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 1500000
#define MOD 1000000007
#define MAX 1429431
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;

using namespace std;

int n, segTree[LIM*4];
vector<int>ara;

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node] = st % 2;
        return;
    }
    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    init(lft, st,   md);
    init(rgt, md+1, ed);
    segTree[node] = segTree[lft] + segTree[rgt];
}

int query(int node, int st, int ed, int pos) {
    if(st == ed) return st;
    segVar;
    if(segTree[lft] >= pos) return query(lft, st, md, pos);
    else return query(rgt, md+1,ed, pos-segTree[lft] );
}

void update(int node, int st, int ed, int pos) {
    if(st > pos || ed < pos) return;
    if(st == pos && ed == pos) {
//        cout << st << endl;
        segTree[node]--;
        return;
    }
    segVar;
    update(lft, st,  md, pos);
    update(rgt, md+1,ed, pos);
    segTree[node] = segTree[lft] + segTree[rgt];
}

void gen() {
    init(1, 1, LIM);
    ara.pb(1);
    for(int p = 2; ; p++) {
        if(p > segTree[1]) break;
        int v = query(1, 1, LIM, p);

        ara.pb(v);

        vector<int>tmp;

        for(int vv=v; ; vv+=v) {
            if(vv > segTree[1]) break;
            tmp.pb(query(1,1,LIM, vv));
        }
        int sz = tmp.size();
        for(int i=0; i<sz; i++)
            update(1, 1,LIM, tmp[i]);
    }
}

int main() {
    gen();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", t, ara[n-1]);
    }
    return 0;
}
