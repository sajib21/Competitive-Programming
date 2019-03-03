#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

struct info {
    pii tmax, lmax, rmax;
    info() {
        tmax = pii(0,0); lmax = pii(0,0); rmax = pii(0,0);
    }
    info(pii tt, pii lll, pii rr) {
        tmax = tt; lmax = lll; rmax = rr;
    }
};

info segMerge(info LFT, info RGT) {
        if(LFT.tmax.first == 0) return RGT;
        if(RGT.tmax.first == 0) return LFT;
        info RET;
        info temp;
        if(LFT.tmax.second > RGT.tmax.second) temp = LFT;
        else temp = RGT;
        if(LFT.rmax.first == RGT.lmax.first) {
            if(LFT.rmax.second+RGT.lmax.second > temp.tmax.second) {
                RET.tmax = pii(LFT.rmax.first, LFT.rmax.second+RGT.lmax.second);
            }
            else RET.tmax = temp.tmax;

            if(LFT.lmax.first == LFT.rmax.first) RET.lmax = pii(LFT.lmax.first, LFT.tmax.second+RGT.lmax.second);
            else RET.lmax = LFT.lmax;
            if(RGT.rmax.first == RGT.lmax.first) RET.rmax = pii(RGT.rmax.first, RGT.tmax.second+LFT.rmax.second);
            else RET.rmax = RGT.rmax;
        }

        else {
            RET.tmax = temp.tmax;
            RET.lmax = LFT.lmax;
            RET.rmax = RGT.rmax;
        }
        return RET;
}

int n,c,q, com[LIM+10];
info segTree[4*LIM+100];

void init(int node, int st, int ed) {
//    cout << node << ' ' << st << ' ' << ed << endl;
    if(st == ed) {
        segTree[node] = info( pii(com[st], 1), pii(com[st], 1), pii(com[st], 1) );
        return;
    }
    segVar;
    init(lft, st,  md);
    init(rgt, md+1,ed);

    segTree[node] = segMerge(segTree[lft],segTree[rgt]);
}

info query(int node, int st, int ed, int l, int r) {
//    cout << node << ' ' << st << ' ' << ed << endl;
    if(st > r || ed < l) return info();
    if(st >= l && ed <= r) {
//        cout << "FOUND AT " << node << ' ' << st << ' ' << ed << endl;
        return segTree[node];
    }
    segVar;
    info a = query(lft, st,  md, l,r);
    info b = query(rgt, md+1,ed, l,r);
    return segMerge(a,b);
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d", &n,&c,&q);
        for(int i=1; i<=n; i++) scanf("%d", &com[i]);
        init(1, 1,n);
        printf("Case %d:\n", t);

//        for(int i=1; i<=15; i++)
//        cout << i << " :: " << segTree[i].lmax.first << " : " << segTree[i].lmax.second << " || " << segTree[i].tmax.first << " : " << segTree[i].tmax.second << " || "
//        << segTree[i].rmax.first << " : " << segTree[i].rmax.second << " || "  << endl;


        while(q--) {
            int l,r;
            scanf("%d %d", &l,&r);
            printf("%d\n", query(1, 1,n, l,r).tmax.second );
        }
    }

    return 0;
}
