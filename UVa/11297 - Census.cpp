#include<bits/stdc++.h>
#define MX 503
#define MAX 10000000000000LL
#define ll long long int
using namespace std;

struct info{
    ll x,y;
    info() {}
    info(ll xx, ll yy) {
        x = xx; y = yy;
    }
};

ll n,q, grid[MX][MX];
info segTree[64*100000];

void init(int node, int stRow, int stCol, int edRow, int edCol) {

    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return;
    if(stRow > edRow || stCol > edCol) return;

    if(stRow == edRow && stCol == edCol) {
        segTree[node].x = segTree[node].y = grid[stRow][stCol];
        return;
    }

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    init(topLeft, stRow,stCol, midRow,midCol);
    init(topRight, stRow,midCol+1, midRow,edCol);
    init(botRight, midRow+1,midCol+1, edRow,edCol);
    init(botLeft, midRow+1,stCol, edRow,midCol);

    info ans;
    ans.x = max( max(segTree[topLeft].x, segTree[topRight].x), max(segTree[botLeft].x, segTree[botRight].x) );
    ans.y = min( min(segTree[topLeft].y, segTree[topRight].y), min(segTree[botLeft].y, segTree[botRight].y) );
    segTree[node] = ans;

//    if(!segTree[node].y) {
//        cout << segTree[topLeft].x << ' ' << segTree[topRight].x << ' ' << segTree[botLeft].x << ' ' << segTree[botRight].x << endl;
//        cout << segTree[topLeft].y << ' ' << segTree[topRight].y << ' ' << segTree[botLeft].y << ' ' << segTree[botRight].y << endl;
//        cout << node << ' ' << stRow << ' ' << stCol << ' ' << edRow << ' ' << edCol << ' ' << ans.x << ' ' << ans.y << endl;
//        getchar();
//    }
}

void update(int node, int stRow, int stCol, int edRow, int edCol, int r, int c, ll val) {

    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return;
    if(stRow > r || stCol > c || edRow < r || edCol < c) return;

    if(stRow == edRow && stCol == edCol) {
        segTree[node].x = segTree[node].y = val;
        return;
    }

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    update(topLeft, stRow,stCol, midRow,midCol, r,c, val);
    update(topRight, stRow,midCol+1, midRow,edCol, r,c, val);
    update(botRight, midRow+1,midCol+1, edRow,edCol, r,c, val);
    update(botLeft, midRow+1,stCol, edRow,midCol, r,c, val);

    info ans;
    ans.x = max( max(segTree[topLeft].x, segTree[topRight].x), max(segTree[botLeft].x, segTree[botRight].x) );
    ans.y = min( min(segTree[topLeft].y, segTree[topRight].y), min(segTree[botLeft].y, segTree[botRight].y) );
    segTree[node] = ans;
}

info query(int node, int stRow, int stCol, int edRow, int edCol, int lRow, int lCol, int rRow, int rCol) {

//    cout << "IN " << node << endl;

    if(stRow > rRow || stCol > rCol || edRow < lRow || edCol < lCol) return info(0, MAX);
    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return info(0, MAX);
    if(stRow > edRow || stCol > edCol) return info(0, MAX);

    if(stRow >= lRow && stCol >= lCol && edRow <= rRow && edCol <= rCol) return segTree[node];

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    info q1 = info(0,MAX) ,q2 = info(0,MAX) ,q3 = info(0,MAX) ,q4 = info(0,MAX);
    info an = info(0, MAX);
    q1 = query(topLeft, stRow,stCol, midRow,midCol, lRow,lCol, rRow,rCol);
    q2 = query(topRight, stRow,midCol+1, midRow,edCol, lRow,lCol, rRow,rCol);
    q3 = query(botRight, midRow+1,midCol+1, edRow,edCol, lRow,lCol, rRow,rCol);
    q4 = query(botLeft, midRow+1,stCol, edRow,midCol, lRow,lCol, rRow,rCol);

    an.x = max( max( q1.x , q2.x ) , max( q3.x , q4.x ) );
    an.y = min( min( q1.y , q2.y ) , min( q3.y , q4.y ) );

////    if(node == 10) {
//        cout << q1.x << ' ' << q2.x << ' ' << q3.x << ' ' << q4.x << endl;
//        cout << q1.y << ' ' << q2.y << ' ' << q3.y << ' ' << q4.y << endl;
//        cout << node << ' ' << stRow << ' ' << stCol << ' ' << edRow << ' ' << edCol << ' ' << ans.x << ' ' << ans.y << endl;
//        getchar();
//    }

//    cout << "OUT " << node << ' ' << an.x << ' ' << an.y << endl;
    return an;

}

int main() {

//    freopen("11235i.txt", "r", stdin);
//    freopen("11235o.txt", "w", stdout);

    int T = 1;
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        for(int i=0; i<64*100000; i++) segTree[i].x = 0 , segTree[i].y = MAX;


        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%lld", &grid[i][j]);
            }
        }
        init(1, 1,1, n,n);

        int q;
        scanf("%d", &q);

        while(q--) {
            char c;
            int x1,y1, x2,y2, xl,yl, xr,yr;
            ll v;
            getchar();
            scanf("%c", &c);
            if(c == 'q') {
                scanf("%d %d %d %d", &x1,&y1, &x2,&y2);
                info ttt =  query(1, 1,1,n,n, x1,y1, x2,y2);
                printf("%lld %lld\n", ttt.x, ttt.y);
            }

            else {
                scanf("%d %d %lld", &xl,&yl, &v);
                update(1, 1,1, n,n, xl,yl, v);
            }
        }
//        cout << "TEST CASE ENDS HERE !!!" << endl;
    }

    return 0;
}
