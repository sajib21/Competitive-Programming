///HEADERS
#include    <bits/stdc++.h>
///PREPROCESSORS
#define     ui              unsigned int
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

int n, val;
char valChar[30], str[60];
//string bad;

string pattern;
int sizePattern;
int prefix[60];

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

#define MAXROW 55
#define MAXCOL 55

int matRow = 2;
int matCol = 2;
ll mod;
struct matrix{
    ui mat[MAXROW][MAXCOL];

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
                    ans.mat[row][col] = ( ans.mat[row][col] + mat[row][p] * b.mat[p][col] ) ;
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

matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return matBigMod(n, r-1) * n ;
    matrix ans = matBigMod(n, r/2);
    return ans*ans;
}




int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    matrix mat;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        scanf("%s", valChar); val = strlen(valChar);
        scanf("%s", str);
        pattern = str; pattern = "0" + pattern;
        sizePattern = pattern.size();
        generatePrefix();

        mat = matrix(0);
        matRow = matCol = sizePattern-1;

        for(int c=1; c<sizePattern; c++) {
            int r = c;
            int cnt = 0;
            bool flag[30] = {0};
            while(r > 1) {
                int p = pattern[r] - 'a';
                if(!flag[p]) {
                    mat.mat[r][c-1] = 1;
                    cnt++;
                    flag[p] = true;
                }
                r = prefix[r-1] + 1;
            }

            int p = pattern[r] - 'a';
            if(!flag[p]) {
                mat.mat[r][c-1] = 1;
                cnt++;
                flag[p] = true;
            }

            mat.mat[0][c-1] = val - cnt;
        }

//        for(int i=0; i<matRow; i++) {
//            for(int j=0; j<matCol; j++) {
//                cout << mat.mat[i][j] << ' ' ;
//            }
//            cout << endl;
//        }

        mat = matBigMod(mat, n);

//        cout << "X" << endl;
//        mat.printMat();

        ui ans = 0;
        for(int i=0; i<matRow; i++) ans += mat.mat[i][0] ;
        printf("Case %d: %u\n", t, ans);
    }

    return 0;
}
