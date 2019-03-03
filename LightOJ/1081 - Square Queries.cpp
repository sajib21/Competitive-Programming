#include<bits/stdc++.h>
#define MX 503
#define ll long long int
using namespace std;

int n,q, grid[MX][MX];
int segTree[4*100000];

void init(int node, int stRow, int stCol, int edRow, int edCol) {

    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return;
    if(stRow > edRow || stCol > edCol) return;

    if(stRow == edRow && stCol == edCol) {
        segTree[node] = grid[stRow][stCol];
        return;
    }

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    init(topLeft, stRow,stCol, midRow,midCol);
    init(topRight, stRow,midCol+1, midRow,edCol);
    init(botRight, midRow+1,midCol+1, edRow,edCol);
    init(botLeft, midRow+1,stCol, edRow,midCol);

    segTree[node] = max( max(segTree[topLeft], segTree[topRight]), max(segTree[botLeft], segTree[botRight]) );
}

int query(int node, int stRow, int stCol, int edRow, int edCol, int lRow, int lCol, int rRow, int rCol) {

    if(stRow > rRow || stCol > rCol || edRow < lRow || edCol < lCol) return 0;
    if(stRow < 1 || stCol < 1 || edRow > n || edCol > n || stRow > n || stCol > n || edRow < 1 || edCol < 1) return 0;
    if(stRow > edRow || stCol > edCol) return 0;

    if(stRow >= lRow && stCol >= lCol && edRow <= rRow && edCol <= rCol) return segTree[node];

    int topLeft = 4*node-2, topRight = 4*node-1, botRight = 4*node, botLeft = 4*node+1;
    int midRow = (stRow+edRow)/2, midCol = (stCol+edCol)/2;

    return max(
    max( query(topLeft, stRow,stCol, midRow,midCol, lRow,lCol, rRow,rCol) , query(topRight, stRow,midCol+1, midRow,edCol, lRow,lCol, rRow,rCol) ) ,
    max( query(botRight, midRow+1,midCol+1, edRow,edCol, lRow,lCol, rRow,rCol) , query(botLeft, midRow+1,stCol, edRow,midCol, lRow,lCol, rRow,rCol) ) );

}

int main() {

//    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        memset(segTree, 0 ,sizeof(segTree));

        scanf("%d %d", &n, &q);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        init(1, 1,1, n,n);

        printf("Case %d:\n", t);
        while(q--) {
            int I,J,S;
            scanf("%d %d %d", &I,&J,&S );
            printf("%d\n", query(1, 1,1,n,n, I,J, I+S-1,J+S-1));
        }
//        cout << "TEST CASE ENDS HERE !!!" << endl;
    }

    return 0;
}
