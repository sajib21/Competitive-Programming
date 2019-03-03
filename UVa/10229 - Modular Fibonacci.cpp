#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

#define matRow 2
#define matCol 2
ll mod;
struct matrix{
    ll mat[matRow][matCol];

    matrix() {
        memset(mat, 0, sizeof(mat));
        for(int i=0, j=0; i<matRow && j<matCol; i++, j++) mat[i][j] = 1;
    }
    matrix(int t) {
        memset(mat, 0, sizeof(mat));
        mat[0][0] = mat[0][1] = mat[1][0] = 1;

    }
};
matrix matMul(matrix a, matrix b) {
    matrix ans;
    memset(ans.mat, 0, sizeof(ans.mat));
    for(int row=0; row<matRow; row++) {
        for(int col=0; col<matCol; col++) {
            for(int p=0; p<matCol; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
                ans.mat[row][col] = ( ans.mat[row][col] + a.mat[row][p] * b.mat[p][col] ) % mod;
            }
        }
    }

//    cout << "MUL" << endl;
//    cout << ans.mat[0][0] << ' ' << ans.mat[0][1] << ' ' << endl;
//    cout << ans.mat[1][0] << ' ' << ans.mat[1][1] << ' ' << endl;


    return ans;
}
matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
    if(!r) return matrix();
    if(r%2) return matMul( matBigMod(n, r-1) , n );
    matrix ans = matBigMod(n, r/2);
    return matMul(ans,ans);
}



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

int n,m;

int main() {

    int T;
//    scanf("%d", &T);
    while(scanf("%d %d", &n,&m) != EOF) {
        mod = 1 << m ;

        matrix temp = matBigMod(matrix(1) , n);
        cout << temp.mat[0][0] << ' ' << temp.mat[0][1] << endl;
        cout << temp.mat[1][0] << ' ' << temp.mat[1][1] << endl;


        printf("%lld\n", temp.mat[1][0] );
    }
    return 0;
}
