#include<bits/stdc++.h>
#define ll unsigned int
#define lll long long int
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
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

///MATRIX EXPO
#define MAXROW 52
#define MAXCOL 52
int matRow;
int matCol;

ll mod;
struct matrix{

    ll mat[MAXROW][MAXCOL];

    matrix() {}
    matrix(int TYPE) {
        memset(mat, 0, sizeof(mat));
//        matRow = r; matCol = c;
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
                    ans.mat[row][col] = ( ans.mat[row][col] + mat[row][p] * b.mat[p][col] ) ;
                }
            }
        }
        return ans;
    }
};

matrix matBigMod(matrix n, lll r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return matBigMod(n, r-1) * n ;
    matrix ans = matBigMod(n, r/2);
    return ans*ans;
}

ll comb[55][55];
void genAllComb(int k) {
    comb[0][0] = 1;
    for(int i=1; i<=k; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++) comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }

//    for(int i=0; i<5; i++) {
//        for(int j=0; j<=i; j++) {
//            cout << comb[i][j] << ' ';
//        }
//        cout << endl;
//    }
}

int main() {
    genAllComb(53);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        lll n,k;
        scanf("%lld %lld", &n, &k);

        matrix co = matrix(0);
        matRow = matCol = k+2;
        co.mat[0][0] = 1;
        for(int i=1; i<=k+1; i++) co.mat[0][i] = comb[k][i-1];
        for(int i=1; i<=k+1; i++) {
            for(int j=i, c=0; j<=k+1; j++, c++) {
                co.mat[i][j] = comb[k-i+1][c];
            }
        }
        co = matBigMod(co, n-1);
        ll ans = 0;

        for(int i=0; i<matCol; i++) ans += co.mat[0][i];
        printf("Case %d: %u\n", t, ans);
    }
    return 0;
}
