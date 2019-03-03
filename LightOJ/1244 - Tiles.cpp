#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9

using namespace std;

///MATRIX EXPO


#define MAXROW 3
#define MAXCOL 3

int matRow = 3;
int matCol = 3;
int mod = 10007;
struct matrix{
    int mat[10][10];

    matrix() {}
    matrix(int TYPE) {
        memset(mat, 0, sizeof(mat));
        if(TYPE == 1) { ///Identity Matrix
            for(int i=0, j=0; i<matRow && j<matCol; i++, j++) mat[i][j] = 1;
        }
        else if(TYPE == 2) { ///Fibonacci
            mat[0][0] = mat[0][1] = mat[1][0] = 1;
        }
        else if(TYPE == 3) { ///nth order fib : f(n) = f(n-1) + f(n-2) + f(n-3) + ....
            for(int i=0; i<matCol; i++) mat[0][i] = 1;
            for(int i=1; i<matRow; i++) mat[i][i-1] = 1;
        }
    }
    matrix(ll ara[]) {
        for(int r=0, n=0; r<matRow; r++) {
            for(int c=0; c<matCol; c++) {
                mat[r][c] = ara[n++];
            }
        }
    }
};
matrix matMul(matrix a, matrix b) {
    matrix ans = matrix(0);
//    memset(ans.mat, 0, sizeof(ans.mat));
    for(int row=0; row<matRow; row++) {
        for(int col=0; col<matCol; col++) {
            for(int p=0; p<matCol; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
                ans.mat[row][col] = ( ans.mat[row][col] + a.mat[row][p] * b.mat[p][col] ) % mod;
            }
        }
    }
    return ans;
}
matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return matMul( matBigMod(n, r-1) , n );
    matrix ans = matBigMod(n, r/2);
    return matMul(ans,ans);
}

int n;
matrix mat;
int elem[9] = {1,1,2, 1,0,0, 0,1,1};
int xxx[3] = {1,1,2};
int bas[3] = {5,2,2};
//int init[] = {1, 1, 2};

int main() {
//    mat = matrix(elem);

//    freopen("in.txt", "r", stdin);
//    freopen("ot.txt", "w", stdout);

    memset(mat.mat, 0, sizeof(mat.mat));
    int x = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            mat.mat[i][j] = elem[x++];
        }
    }


    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
//        memset(mat.mat, 0, sizeof(mat.mat));
        scanf("%d", &n);
        if(n<3) {
            printf("Case %d: %d\n", t, xxx[n]);
            continue;
        }

        matrix temp;
        temp = matBigMod(mat, n-3);

        ll ans = 0;
        for(int i=0; i<3; i++) ans = (ans + temp.mat[0][i]*bas[i] ) % mod;
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
