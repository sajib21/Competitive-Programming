#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;


/*

int isPrime[LIM+100];
vector<int>primes;
void genSieve() {
    primes.clear();
    memset(isPrime, 0, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 1;
    for(int i=4; i<=LIM; i+=2) isPrime[i] = 1;
    int sq = sqrt(LIM);
    for(int i=2; i<=sq; i+=2) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=LIM; j+=i) isPrime[j] = 1;
        }
    }
    primes.pb(2);
    for(int i=3; i<=LIM; i+=2) if(!isPrime[i]) primes.pb(i);
}
*/

/*
ll bigMod(ll n, ll r) {
    if(!n) return 0;
    if(!r) return 1;
    if(r%2) return (bigMod(n, r-1)*n) % MOD;
    ll ans = bigMod(n, r/2);
    return (ans*ans) % MOD;
}
*/

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

int d,n;

int main() {

    int T;
//    scanf("%d", &T);
    while(scanf("%d %d %lld", &d,&n,&mod) && d && n && mod) {
        n--;
        matRow = matCol = d;
        int a[17], f[17];
        for(int i=0; i<d; i++) scanf("%d", &a[i]);
        for(int i=0; i<d; i++) scanf("%d", &f[i]);
        matrix co = matrix(0);
        for(int i=0; i<d; i++) co.mat[0][i] = a[i];
        for(int i=1; i<d; i++) co.mat[i][i-1] = 1;

        if(n < d) {
            printf("%d\n", f[n]%mod);
            continue;
        }
//        for(int i=0; i<d; i++) {
//            for(int j=0; j<d; j++) {
////                cout << co.mat[i][j] << ' ';
//                printf("%10d", co.mat[i][j]);
//            }
//            cout << endl;
//        }
        co = matBigMod(co, n-d+1);
//        for(int i=0; i<d; i++) {
//            for(int j=0; j<d; j++) {
//                cout << co.mat[i][j] << ' ';
//            }
//            cout << endl;
//        }

//        cout << co.mat[0][0] << ' ' << co.mat[0][1] << ' ' << co.mat[0][2] << endl;
//        cout << co.mat[1][0] << ' ' << co.mat[1][1] << ' ' << co.mat[1][2] << endl;
//        cout << co.mat[2][0] << ' ' << co.mat[2][1] << ' ' << co.mat[2][2] << endl;


        ll ans = 0;
        for(int i=0; i<d; i++) ans = (ans + co.mat[0][i]*f[d-i-1]) % mod;
        printf("%lld\n", ans);
    }
    return 0;

}
