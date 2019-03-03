#include<bits/stdc++.h>
#define ll unsigned int
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

using namespace std;

int  setBit(int mask, int pos) { return mask | (1 << pos) ; }
int  togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
bool chkBit(int mask, int pos) { return mask & (1 << pos) ; }

#define MAXROW 37
#define MAXCOL 37

int matRow = 36;
int matCol = 36;
ll mod = MOD;

struct matrix{
    ll mat[MAXROW][MAXCOL];

    matrix() {}
    matrix(int TYPE) {
        memset(mat, 0, sizeof(mat));
        if(TYPE == 1) { ///Identity Matrix
            for(int i=0, j=0; i<=matRow && j<=matCol; i++, j++) mat[i][j] = 1;
        }
        if(TYPE == 11) { ///All 1 matrix
            for(int i=0; i<=matRow; i++) for(int j=0; j<=matCol; j++) mat[i][j]= 1;
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
        for(int row=1; row <=matRow; row++) {
            for(int col=1; col<=matCol; col++) {
                ans.mat[row][col] = mat[row][col] + b.mat[row][col];
            }
        }
        return ans;
    }

    matrix operator * (const matrix b) const {
//        cout << "MUL" << endl;
        matrix ans = matrix(0);
        for(int row=1; row<=matRow; row++) {
            for(int col=1; col<=matCol; col++) {
                for(int p=1; p<=matCol; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
                    ans.mat[row][col] = ( ans.mat[row][col] + mat[row][p] * b.mat[p][col] );
//                    cout << row << ' ' << col << ' ' << ans.mat[row][col] << endl;
                }
//                cout << ans.mat[row][col] ;
            }
//            cout << endl;
        }
        return ans;
    }

};

matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return matBigMod(n, r-1) * n ;
    matrix ans = matBigMod(n, r/2);
    return ans*ans;
}

int n, ara[7], x, cnt=0;
map<int, int> mp, mp2;
vii graph[40];
matrix co;

void genMap(int mask, int in, int taken) {
    if(mp[mask]) return;
    if(taken == 2) {
        mp[mask] = ++cnt;
        mp2[cnt] = mask;
//        cout << mask << " ER VALUE " << mp[mask] << endl;
    }
    if(in >= 10) return;

    genMap(setBit(mask, in), in+2, taken+1);
    genMap(mask, in+1, taken);
}

int vis[1050][40];

int main() {
    co = matrix(0);

    genMap(0, 0, 0);

    for(int i=1; i<=36; i++) {
        int umask = mp2[i], vmask=0;
        for(int xx=0; xx<10; xx++) {
            int x = umask % 2;
            umask /= 2;
            if(x) {
                if(xx-1 >= 0) vmask = setBit(vmask, xx-1);
                vmask = setBit(vmask, xx);
                if(xx+1 <= 9) vmask = setBit(vmask, xx+1);
            }
        }
        for(int p=0; p<10; p++) if(!chkBit(vmask, p)) {
            int wmask = setBit(0, p);
            for(int q=p+2; q<10; q++) if(!chkBit(vmask, q)) {
                int v = mp[ setBit(wmask, q) ];
                co.mat[i][v] = 1;
//                ct++;
//                cout << "MAKING " << i << ' ' << v << ' ' << setBit(wmask, q) << endl;
            }
        }

    }

//    cout << "DONE" << endl;
//    for(int i=1; i<=matRow; i++) {
////        cout << i << ' ' << ' ' << mp2[i] << "  :  ";
//        for(int j=1; j<=matCol; j++) {
//            cout << co.mat[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << "CT " << ct << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int mask = 0, u;
        scanf("%d", &n); n--;
        matrix temp = matBigMod(co, n);
        ll ans = 0;
        for(int i=1; i<=matCol; i++) {
            for(int j=1; j<=matCol; j++) {
                ans += temp.mat[i][j];
            }
        }
        printf("Case %d: %u\n", t, ans);
    }
    return 0;
}

