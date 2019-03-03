#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

///MATRIX EXPO

#define MAXROW 17
#define MAXCOL 17

int matRow = 2;
int matCol = 2;
ll mod;
struct matrix{
    ll mat[MAXROW][MAXCOL];

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

int n,a,b,c;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d", &n,&a,&b,&c);
        matRow = matCol = 4; /// must change this
        matrix co = matrix(0);
        co.mat[0][0] = a; co.mat[0][2] = b;
        co.mat[0][3] = co.mat[1][0] = co.mat[2][1] = co.mat[3][3] = 1;
        mod = 10007;

        if(n <= 2) {
            printf("Case %d: %lld\n", t, 0LL );
            continue;
        }

        co = matBigMod(co, n-2);
//        co = matMul(co, co);


        printf("Case %d: %lld\n", t, (co.mat[0][3] * c) % mod );



    }

    return 0;
}

