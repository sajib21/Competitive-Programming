#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 50000
#define MOD 1000000007
#define MAX 10000000

using namespace std;



int n,q, id[5*LIM+100];
int segTree[10*LIM+200];

void init(int node, int st, int ed) {

    segTree[node] = ed - st + 1;
    if(st == ed) return;

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    init(lft, st,   md);
    init(rgt, md+1, ed);

}

void update(int node, int st, int ed, int p, int val) {
    if(st > p || ed < p) return;
    segTree[node] += val;
    if(st == ed) return ;

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    update(lft, st,   md, p,val);
    update(rgt, md+1, ed, p,val);
}

int query(int node, int st, int ed, int k) {
    if(st == ed) return st;

    int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
    if(segTree[lft] >= k) return query(lft, st,   md, k);
    else return query(rgt, md+1, ed, k-segTree[lft]);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(segTree, 0, sizeof(segTree));
        memset(id, -1, sizeof(id));

        scanf("%d %d", &n,&q);
        for(int i=1; i<=n; i++) scanf("%d", &id[i]);
        int lim = n+q;
        for(int i=1; i<=n; i++) update(1, 1,lim, i, 1);

        printf("Case %d:\n", t);
        int cn = n;
        while(q--) {
            char c;
            int d;
            getchar();
            scanf("%c %d", &c,&d);
            if(c == 'a') {
                id[++n] = d;
                update(1, 1,lim, n, 1);
                cn++;
            }
            else if(c == 'c') {

                if(cn < d) {
                    printf("none\n");
                    continue;
                }

                int indx = query(1, 1,lim, d);
                update(1, 1,lim, indx, -1);
                printf("%d\n", id[indx]);
                cn--;
            }
        }
    }
    return 0;
}
