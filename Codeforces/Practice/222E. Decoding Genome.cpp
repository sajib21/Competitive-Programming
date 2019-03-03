#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;

///MATRIX EXPO

#define MAXROW 52
#define MAXCOL 52

int matRow = 52;
int matCol = 52;
ll mod = MOD;

struct matrix{
    ll mat[MAXROW][MAXCOL];

    matrix() {}
    matrix(int TYPE) {
        memset(mat, 0, sizeof(mat));
        if(TYPE == 1) { ///Identity Matrix
            for(int i=0, j=0; i<matRow && j<matCol; i++, j++) mat[i][j] = 1;
        }
        if(TYPE == 2) { ///all 1
            for(int i=0; i<matRow; i++)
                for(int j=0; j<matCol; j++)
                    mat[i][j] = 1;
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

matrix matBigMod(matrix n, ll r) {
//    if(!n) return 0;
    if(!r) return matrix(1);
    if(r%2) return matBigMod(n, r-1) * n ;
    matrix ans = matBigMod(n, r/2);
    return ans*ans;
}

ll n;
int m,k;
char seq[4];
matrix mat;

int main() {
    scanf("%lld %d %d", &n,&m,&k);
    matRow = matCol = m;
    mat = matrix(2);

    for(int i=0; i<k; i++) {
        scanf("%s", seq);
        int u,v;
        if(seq[0] >= 'a' && seq[0] <= 'z') u = seq[0] - 'a';
        else u = seq[0] - 'A' + 26;
        if(seq[1] >= 'a' && seq[1] <= 'z') v = seq[1] - 'a';
        else v = seq[1] - 'A' + 26;
        mat.mat[u][v] = 0;
    }

//    cout << "INT " << endl;
//    mat.printMat();

    mat = matBigMod(mat, n-1);
//    cout << "BIG " << endl;
//    mat.printMat();


    ll ans = 0;
    for(int i=0; i<matRow; i++)
        for(int j=0; j<matCol; j++)
            ans = (ans + mat.mat[i][j] )%MOD;

    cout << ans << endl;
}
