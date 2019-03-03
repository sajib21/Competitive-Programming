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
#define MAXROW 31
#define MAXCOL 31

int matRow = 2;
int matCol = 2;
int mod = 10;

struct matrix{
    int mat[MAXROW][MAXCOL];

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
    matrix(int ara[]) {
        for(int r=0, n=0; r<matRow; r++) {
            for(int c=0; c<matCol; c++) {
                mat[r][c] = ara[n++];
            }
        }
    }

    matrix operator + (const matrix b) const {
        matrix ans = matrix(0);
        for(int row=0; row <matRow; row++) {
            for(int col=0; col<matCol; col++) {
                ans.mat[row][col] = mat[row][col] + b.mat[row][col];
            }
        }
        return ans;
    }

    matrix operator * (const matrix b) const {
        matrix ans = matrix(0);
        for(int row=0; row<matRow; row++) {
            for(int col=0; col<matCol; col++) {
                for(int p=0; p<matCol; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
                    ans.mat[row][col] = ( ans.mat[row][col] + mat[row][p] * b.mat[p][col] ) % mod;
                }
            }
        }
        return ans;
    }
};

matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return n * matBigMod(n, r-1) ;
    matrix ans = matBigMod(n, r/2);
    return ans * ans;
}


struct matrix2D {
    matrix mat[2][2];

    matrix2D() {}
    matrix2D(int TYPE) {
        if(TYPE == 0) {
            mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = matrix(0);
        }
        if(TYPE == 1) {
            mat[0][0] = mat[1][1] = matrix(1);
            mat[0][1] = mat[1][0] = matrix(0);
        }
    }

    matrix2D operator + (const matrix2D b) const {
        matrix2D ans = matrix2D();
        for(int row=0; row <2; row++) {
            for(int col=0; col<2; col++) {
                ans.mat[row][col] = mat[row][col] + b.mat[row][col];
            }
        }
        return ans;
    }
//
    matrix2D operator * (const matrix2D b) const {
        matrix2D ans = matrix2D(0);
        for(int row=0; row<2; row++) {
            for(int col=0; col<2; col++) {
                for(int p=0; p<2; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
//                    cout << row << ' ' << col << ' ' << p << endl;
                    ans.mat[row][col] = ( ans.mat[row][col] + (mat[row][p] * b.mat[p][col]) );
                }
            }
        }
        return ans;
    }
};

matrix2D mat2DBigMod(matrix2D n, int r) {
//    if(!n) return 0;

    if(!r) return matrix2D(1);
//    cout << r << endl;
    if(r%2) return mat2DBigMod(n, r-1) * n;
//    cout << "BUG" << endl;
    matrix2D ans = mat2DBigMod(n, r/2);
    return ans * ans;
}


int n,k, ara[30*30+10];
matrix A;
matrix2D co;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&k);
        matRow = matCol = n;
        for(int i=0, c=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &ara[c++]);
        A = matrix(ara);

        co.mat[0][0] = A;
        co.mat[0][1] = matrix(1);
        co.mat[1][0] = matrix(0);
        co.mat[1][1] = matrix(1);


        co = mat2DBigMod(co, k-1);
//        cout << "BUG" << endl;

        matrix ans = co.mat[0][0] * A + co.mat[0][1] * A;

        printf("Case %d:\n", t);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("%d", ans.mat[i][j] % 10);
            }
            printf("\n");
        }
    }
    return 0;
}
