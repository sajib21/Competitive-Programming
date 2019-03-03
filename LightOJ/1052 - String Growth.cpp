#include<bits/stdc++.h>
#define ll long long int

using namespace std;

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

int n,x,m,y,k;
ll a,b,c, p,q,r;

int main() {

    mod = 1000000007;

    matrix mat = matrix(2);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d %d %d %d %d", &n,&x,&m,&y,&k);
        matrix nth = matBigMod(mat, n-1);
        a = nth.mat[1][0] + nth.mat[1][1];
        b = nth.mat[0][0] + nth.mat[0][1];
        c = x;
        matrix mth = matBigMod(mat, m-1);
        p = mth.mat[1][0] + mth.mat[1][1];
        q = mth.mat[0][0] + mth.mat[0][1];
        r = y;

        ll D = a*q - b*p;
        ll A = (c*q - b*r) / D;
        ll B = (a*r - c*p) / D;

        nth = matBigMod(mat, k-1);
        a = nth.mat[1][0] + nth.mat[1][1];
        b = nth.mat[0][0] + nth.mat[0][1];
        c = x;

//        cout << a << ' ' << b << ' ' << c << ' ' << p << ' ' << q << ' ' << r << endl;
//        cout << A << ' ' << B << endl;
        if(A<0 || B<0 || a*A + b*B <= 0) printf("Case %d: Impossible\n", t);
        else printf("Case %d: %lld\n", t, (a*A + b*B) % mod );
    }
    return 0;
}
