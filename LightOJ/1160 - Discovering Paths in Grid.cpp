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
#define sqr(x) ((x)*(x))

using namespace std;

int  setBit(int mask, int pos) { return mask | (1 << pos) ; }
int  togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
bool chkBit(int mask, int pos) { return mask & (1 << pos) ; }

#define MAXROW 36
#define MAXCOL 36

int matRow = 35;
int matCol = 35;
ll mod = MOD;

struct matrix{
    ll mat[MAXROW][MAXCOL];

    matrix() {}
    matrix(int TYPE) {
        memset(mat, 0, sizeof(mat));
        if(TYPE == 1) { ///Identity Matrix
            for(int i=0, j=0; i<=matRow && j<=matCol; i++, j++) mat[i][j] = 1;
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
                    ans.mat[row][col] = ( ans.mat[row][col] + mat[row][p] * b.mat[p][col] ) % mod;
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
    if(taken == 4) {
        mp[mask] = ++cnt;
        mp2[cnt] = mask;
//        cout << mask << " ER VALUE " << cnt << endl;
    }
    if(in == 7) return;

    genMap(setBit(mask, in), in+1, taken+1);
    genMap(mask, in+1, taken);
}

int vis[1050][40];

void genMat(int vmask, int u, int i, int pos[4]) {
    if(vis[vmask][u]) return;
    vis[vmask][u] = 1;
    if(i == 4) {
        int v = mp[vmask];
        co.mat[u][v] = co.mat[v][u] = 1;
//        if(u == 35) cout << u << ' ' << v << ' ' << vmask << endl;
        return;
    }


    int p = pos[i];

    if(p-1 >= 0 && !chkBit(vmask, p-1)) genMat(setBit(vmask, p-1), u, i+1, pos);
//    if(!chkBit(vmask, p)) genMat(setBit(vmask, p), u, i+1, pos);
    if(p+1 < 7 && !chkBit(vmask, p+1)) genMat(setBit(vmask, p+1), u, i+1, pos);



}

int main() {
    co = matrix(0);
    genMap(0, 0, 0);
    for(int i=1; i<=35; i++) {
        int pos[4], p=0, umask = mp2[i];
        for(int i=0; i<7; i++) {
            int x = umask % 2;
            umask /= 2;
            if(x) {
                pos[p++] = i;
            }
        }
        genMat(0, i, 0, pos);
    }

//    cout << "DONE" << endl;
//    for(int i=1; i<=matRow; i++) {
////        cout << i << ' ' << ' ' << mp2[i] << "  :  ";
//        for(int j=1; j<=matCol; j++) {
//            cout << co.mat[i][j] << ' ';
//        }
//        cout << endl;
//    }

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int mask = 0, u;
        scanf("%d", &n); n--;
        matrix temp = matBigMod(co, n);
        for(int i=0; i<7; i++) {
            scanf("%d", &x);
            if(x) mask = mask*2 + 1;
            else mask = mask*2;
        }
//        cout << mask << ' ' << mp[mask] << endl;
        ll p=mp[mask], ans = 0;
        for(int i=1; i<=matCol; i++) ans = (ans + temp.mat[p][i]) % MOD;
        printf("Case %d: %lld\n", t, ans);
    }
    return 0;
}

