#include<bits/stdc++.h>
#define MX 503
#define ll long long int
#define vi vector<int>
#define pb push_back
#define LIM 100005

using namespace std;

int n,q,mxx,mxy, a[LIM],b[LIM];
int segTree[10*LIM];

void update(int node, int stRow, int stCol, int edRow, int edCol, int Row, int Col, int v) {
    cout << node << ' ' << stRow << ' ' << stCol << ' ' << edRow << ' ' << edCol << ' ' << Row << ' ' < Col << ' ' << v << endl; getchar();

    if(stRow > Row || stCol > Col || edRow < Row || edCol < Col) return;
    if(stRow >= Row && stCol >= Col && edRow <= Row && edCol <= Col) {
        segTree[node] = max(segTree[node], v);
        return;
    }

//    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return;
//    if(stRow > edRow || stCol > edCol) return;

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    update(topLeft, stRow,stCol, midRow,midCol, Row, Col, v);
    update(topRight, stRow,midCol+1, midRow,edCol, Row, Col, v);
    update(botRight, midRow+1,midCol+1, edRow,edCol, Row, Col, v);
    update(botLeft, midRow+1,stCol, edRow,midCol, Row, Col, v);

    segTree[node] = max( max(segTree[topLeft], segTree[topRight]), max(segTree[botLeft], segTree[botRight]) );
}

int query(int node, int stRow, int stCol, int edRow, int edCol, int Row, int Col) {
//    cout << node << ' ' << stRow << ' ' << stCol << ' ' << edRow << ' ' << edCol << ' ' << Row << ' ' < Col << endl; getchar();

    if(stRow > Row || stCol > Col || edRow < Row || edCol < Col) return 0;

//    if(stRow < 0 || stCol < 0 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return 0;
//    if(stRow > edRow || stCol > edCol) return 0;

    if(stRow >= Row && stCol >= Col && edRow <= Row && edCol <= Col) {

        return segTree[node];
    }

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    return max(
    max( query(topLeft, stRow,stCol, midRow,midCol, Row,Col) , query(topRight, stRow,midCol+1, midRow,edCol, Row,Col) ) ,
    max( query(botRight, midRow+1,midCol+1, edRow,edCol, Row,Col), query(botLeft, midRow+1,stCol, edRow,midCol, Row,Col) ) );

}

int main() {
    vi x,y;
    map<int,int>X,Y;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        x.pb(a[i]); y.pb(b[i]);
    }
    sort(x.begin(), x.end()); x.erase( unique( x.begin(), x.end() ), x.end() ); for(int i=0; i<x.size(); i++) X[ x[i] ] = i+1;
    sort(y.begin(), y.end()); y.erase( unique( y.begin(), y.end() ), y.end() ); for(int i=0; i<y.size(); i++) Y[ y[i] ] = i+1;
    for(int i=0; i<n; i++) {
        a[i] = X[ a[i] ];
        b[i] = Y[ b[i] ];
    }
    mxx = a[n-1]; mxy = b[n-1];

    for(int i=0; i<n; i++) cout << "(" << a[i] << "," << b[i] << "), " ; cout << endl;


    int ans = 0;
    for(int i=0; i<n; i++) {
        cout << "Query " << a[i]-1 << " " << b[i]-1 << endl;
        int v = query(1, 0,0, mxx,mxy, a[i]-1,b[i]-1 )+1;
        cout << "UPDATE " << a[i] << ' ' << b[i] << ' ' << v << endl;
        update(1, 0,0, mxx,mxy, a[i],b[i], v);
        ans = max(ans, v);
        cout << i << ' ' << v << ' ' << segTree[1] << endl;
    }
    printf("%d\n", ans);

    return 0;
}
