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

int a1,b1,c1, a2,b2,c2, f0,f1,f2, g0,g1,g2;

int main() {

    int T, q;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ///MUST CHANGE MATRIX SIZE HERE
        matRow = 6 ; matCol = 6;
        int fg[10];
        scanf("%d %d %d", &a1,&b1,&c1);
        scanf("%d %d %d", &a2,&b2,&c2);
        for(int i=2; i>=0; i--) scanf("%d", &fg[i]);
        for(int i=5; i>=3; i--) scanf("%d", &fg[i]);
//        scanf("%d %d %d", &f0,&f1,&f2);
//        scanf("%d %d %d", &g0,&g1,&g2);
        scanf("%lld", &mod);

        matrix co = matrix(0);
        co.mat[0][0] = a1 ; co.mat[0][1] = b1 ; co.mat[0][5] = c1 ;
        co.mat[1][0] = 1 ; co.mat[2][1] = 1 ;
        co.mat[3][2] = c2 ; co.mat[3][3] = a2 ; co.mat[3][4] = b2 ;
        co.mat[4][3] = 1 ; co.mat[5][4] = 1 ;

        matrix temp = co;

        scanf("%d", &q);
        printf("Case %d:\n", t);
        while(q--) {
            co = temp;
            int n;
            scanf("%d", &n);

            if(n < 3) {
                printf("%d %d\n", fg[2-n]%mod, fg[5-n]%mod);
                continue;
            }
//            for(int i=0; i<6; i++) {
//                for(int j=0; j<6; j++) {
//                    cout << co.mat[i][j] << ' ';
//                }
//                cout << endl;
//            }

            co = matBigMod(co, n-2);
            ll ans1 = 0, ans2=0;
            for(int i=0; i<6; i++) {
                ans1 += co.mat[0][i]*fg[i];
                ans2 += co.mat[3][i]*fg[i];
                ans1 %= mod; ans2 %= mod;
//                cout << ans1 << ' ' << ans2 << endl;
            }
            printf("%lld %lld\n", ans1, ans2);
//            for(int i=0; i<6; i++) {
//                for(int j=0; j<6; j++) {
//                    cout << co.mat[i][j] << ' ';
//                }
//                cout << endl;
//            }
        }
    }
    return 0;
}

