#include<bits/stdc++.h>
#define LIM 50050
#define pb push_back

using namespace std;

struct point {
    int x,y;
};

struct query{
    int x1,y1, x2,y2, id, ans;
};

bool cmp1(point a, point b) {
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(query a, query b) {
    if(a.x1 == b.x1) {
        if(a.id%2 == 1 && b.id%2 == 1) return a.y1 < b.y1;
        if(a.id%2) return true;
        if(b.id%2) return false;
    }
    return a.x1 < b.x1;
}
bool cmp3(query a, query b) {
    if(a.id == b.id) return a.x1 < b.x1;
    return a.id < b.id;
}

int p,q;
point givenPoints[LIM+10];
query queryPoints[2*LIM+10];
vector<int>coX,coY;
map<int, int>mapX, mapY;

int segTree[6*LIM];

void update(int node, int st, int ed, int pos) {

    if(ed < pos || st > pos) return;
    if(st == pos && pos == ed) {
        segTree[node]++;
        return;
    }

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    update(lft, st, mid, pos);
    update(rgt, mid+1,ed, pos);

    segTree[node] = segTree[lft] + segTree[rgt];
}

int Query(int node, int st, int ed, int l, int r) {

    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) return segTree[node];

    int lft = node << 1 , rgt = (node << 1) + 1 , mid = (st+ed)/2;
    return Query(lft, st, mid, l,r) + Query(rgt, mid+1,ed, l,r);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        memset(segTree, 0, sizeof(segTree));
        coX.clear() , coY.clear() , mapX.clear() , mapY.clear();

        scanf("%d %d", &p, &q);
        for(int i=0; i<p; i++) {
            scanf("%d %d", &givenPoints[i].x, &givenPoints[i].y);
            coX.pb(givenPoints[i].x);
            coY.pb(givenPoints[i].y);
        }
        for(int i=1; i<=2*q; i+=2) {
            int x1,y1,x2,y2;
            scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
            queryPoints[i].x1 = x1, queryPoints[i].y1 = y1;
            queryPoints[i].x2 = x1, queryPoints[i].y2 = y2;
            queryPoints[i+1].x1 = x2, queryPoints[i+1].y1 = y1;
            queryPoints[i+1].x2 = x2, queryPoints[i+1].y2 = y2;
            queryPoints[i].id = i, queryPoints[i+1].id = i+1;

            coX.pb(x1); coX.pb(x2);
            coY.pb(y1); coY.pb(y2);
        }
        sort(coX.begin(), coX.end());
        sort(coY.begin(), coY.end());

        int szX = coX.size() , szY = coY.size();

        mapX[ coX[0] ] = mapY[ coY[0] ] = 1;
        for(int i=1, pn=2; i<szX; i++) if(coX[i] != coX[i-1]) mapX[ coX[i] ] = pn++;
        for(int i=1, pn=2; i<szY; i++) if(coY[i] != coY[i-1]) mapY[ coY[i] ] = pn++;

        for(int i=0; i<p; i++)  givenPoints[i].x = mapX[ givenPoints[i].x ] , givenPoints[i].y = mapY[ givenPoints[i].y ];
        for(int i=1; i<=2*q; i++) queryPoints[i].x1 = mapX[ queryPoints[i].x1 ] , queryPoints[i].y1 = mapY[ queryPoints[i].y1 ] ,
                                queryPoints[i].x2 = mapX[ queryPoints[i].x2 ] , queryPoints[i].y2 = mapY[ queryPoints[i].y2 ] ;

        sort(givenPoints, givenPoints+p, cmp1);
        sort(queryPoints, queryPoints+2*q+1, cmp2);

        int hiX = mapX[ coX[ szX-1 ] ], hiY = mapY[ coY[ szY-1 ] ];

        for(int i=1, px=0, qx=1; i<=hiX; i++) {
            while(queryPoints[qx].x1 == i && queryPoints[qx].id % 2) {
                queryPoints[qx].ans = Query(1, 1,hiY, queryPoints[qx].y1, queryPoints[qx].y2 );
                qx++;
            }
            while(givenPoints[px].x == i) {
                update(1, 1,hiY, givenPoints[px].y);
                px++;
            }
            while(queryPoints[qx].x1 == i) {
                queryPoints[qx].ans = Query(1, 1,hiY, queryPoints[qx].y1, queryPoints[qx].y2 );
                qx++;
            }

        }

        sort(queryPoints, queryPoints+2*q+1, cmp3);

        printf("Case %d:\n", t);
        for(int i=2; i<=2*q; i+=2) printf("%d\n", queryPoints[i].ans - queryPoints[i-1].ans);



    }
    return 0;

}
