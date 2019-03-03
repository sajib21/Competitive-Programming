///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ll              long long int
#define     ull             unsigned ll
#define     vii             vector<int>
#define     vll             vector<ll>
#define     pb              push_back
#define     LIM             100000
#define     MOD             1000000007
#define     MAX             10000000
#define     pi              acos(-1)
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii             pair<int,int>
#define     mpr             make_pair
#define     EPS             1e-9
#define     sqr(x)          ((x)*(x))
#define     gamma           0.5772156649
#define     harm(x)         log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define     joshephus(n,k)  j(int n, int k) {ll res = 1; for(ll i=2; i<=n; i++) res = (res+k-1) % i + 1; return res;}

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);

///IMPORTANT EQUATIONS
///STARS AND BARS   : (n+k-1)C(k-1)
///STIRLING TWO     : F(n,k) = F(n-1,k-1) + k*(n-1,k); F(n,1) = 1 , F(n,n) = 1;
///STIRLING ONE     : F(n,k) = F(n-1,k-1) + (n-1)*(n-1,k); F(n,1) = (n-1)! , F(n,n) = 1;
///CATALAN NUMBER   : Cat(n) = Comb(2n,n) - Comb(2n,n-1) = Comb(2n,n)/(n+1);

using namespace std;

#define MAXROW 2
#define MAXCOL 2

int matRow = 2;
int matCol = 2;
ll mod = MOD;
struct matrix{
//    ll p,q;
    ll mat[MAXROW][MAXCOL];

    matrix() {
//        p = q = 0;
        memset(mat, 0, sizeof mat);
    }
    matrix(int TYPE) {
//        p = q = 0;
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
                ans.mat[row][col] = (mat[row][col] + b.mat[row][col]) % mod;
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

    void printMat() {
        for(int i=0; i<matRow; i++) {
            for(int j=0; j<matCol; j++) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }

    }

};

struct info{
    ll x,y,z;
    info() {x = y = z = 0;}
    info(ll xx, ll yy = 0, ll zz = 0) {
        x = xx; y = yy; z = zz;
    }
    info operator + (const info b) const {
        return info( (x+b.x)%mod , (y+b.y)%mod  );
    }

    dot(matrix b) {
        ll p,q;
        p = (x*b.mat[0][0] + y*b.mat[1][0]) % mod;
        q = (x*b.mat[0][1] + y*b.mat[1][1]) % mod;
        x = p; y = q;
    }
};

matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;

    if(!r) return matrix(1);
//     cout << r << ' ' << endl; getchar();
    if(r&1) return matBigMod(n, r-1) * n ;
    matrix ans = matBigMod(n, r/2);
    return ans*ans;
}

int n,m;
ll ara[LIM+100];
matrix segTree[4*LIM+100];
info sumTree[4*LIM+100];

void init(int node, int st, int ed) {
//    cout << node << ' ' << st << ' ' << ed << endl; getchar();
    segTree[node] = matrix(1);
    sumTree[node] = info(1,0);
    if(st == ed) {
        matrix temp = matBigMod(matrix(2), ara[st]);
        segTree[node] = temp;
//        cout << "BUG" << endl;
        sumTree[node].dot(temp);
        return;
    }
    segVar;
    init(lft, st, md); init(rgt, md+1, ed);
    sumTree[node] = sumTree[lft] + sumTree[rgt];
}

void update(int node, int st, int ed, int l, int r, matrix x, matrix carry ) {
//    cout << "IN " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << endl;
//    segTree[node].printMat();
//    cout << "RES " << sumTree[node].x << ' ' << sumTree[node].y << endl;
    segTree[node] = segTree[node] * carry;
    sumTree[node].dot(carry);
//    cout << "AF " << endl;
//    segTree[node].printMat();
//    cout << "RE " << sumTree[node].x << ' ' << sumTree[node].y << endl;
//    getchar();

    if(st > r || ed < l) return;
    if(st >= l && ed <= r) {
//        cout << "PRE" << endl;
//        segTree[node].printMat();
//        x.printMat();
//        cout << "RES " << sumTree[node].x << ' ' << sumTree[node].y << endl;
        segTree[node] = segTree[node] * x;
        sumTree[node].dot(x);

//        cout << "UPDATE " << endl;
//        segTree[node].printMat();
//        cout << sumTree[node].x << ' ' << sumTree[node].y << endl;
//        getchar();
        return;
    }
    segVar;
    update(lft, st,md, l,r, x, segTree[node]); update(rgt, md+1,ed, l,r, x, segTree[node]);
    sumTree[node] = sumTree[lft] + sumTree[rgt];
    segTree[node] = matrix(1);
}

ll query(int node, int st, int ed, int l, int r, matrix carry ) {
//    cout << "IN " << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << endl;
//    segTree[node].printMat();
    segTree[node] = segTree[node] * carry;
    sumTree[node].dot(carry);
//    cout << "AF " << endl;
//    segTree[node].printMat();
//    getchar();

    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r) return sumTree[node].x;
    segVar;
    ll ans = ( query(lft, st,md, l,r, segTree[node]) + query(rgt, md+1,ed, l,r, segTree[node]) ) % mod;
    segTree[node] = matrix(1);
    return ans;
}

int main() { ///sum change korte hoite pare

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%I64d", &ara[i]);
        ara[i]--;
    }

    init(1, 1,n);
//    for(int i=1; i<=20; i++) cout << i << ' ' << sumTree[i].x << ' ' << sumTree[i].y << endl;


    while(m--) {
        int c,l,r,x;
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %d %d", &l,&r,&x);
//            x--;
            matrix temp = matBigMod(matrix(2), x);
//            temp.printMat();
            update(1, 1,n, l,r, temp, matrix(1));
        }
        else {
            scanf("%d %d", &l, &r);
            printf("%I64d\n", query(1, 1,n, l,r, matrix(1)));
        }
    }

    return 0;
}
