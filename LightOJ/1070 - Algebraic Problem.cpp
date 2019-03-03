#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

///DIRECTION ARRAY
/*
int dirR[] = {-1,  0, +1,  0};
int dirC[] = { 0, +1,  0, -1};
*/

///ROW COLUMN INFO
/*
struct rc {
    int r, c, tim;
    rc() {}
    rc(int rr, int cc, int t) {
        r = rr;
        c = cc;
        tim = t;
    }
};
*/

///MATRIX EXPO


#define MAXROW 17
#define MAXCOL 17

int matRow = 2;
int matCol = 2;
ll mod;
struct matrix{
    ull mat[MAXROW][MAXCOL];

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
//    cout << "A" << endl;
//    for(int i=0; i<2; i++) {
//        for(int j=0; j<2; j++) {
//            cout << a.mat[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << "B" << endl;
//    for(int i=0; i<2; i++) {
//        for(int j=0; j<2; j++) {
//            cout << b.mat[i][j] << ' ';
//        }
//        cout << endl;
//    }

    for(int row=0; row<matRow; row++) {
        for(int col=0; col<matCol; col++) {
            for(int p=0; p<matCol; p++) { ///OR WE CAN TAKE P < MATROW OF 2ND MATRIX
                ans.mat[row][col] = ( ans.mat[row][col] + a.mat[row][p] * b.mat[p][col] ) ;
            }
        }
    }
    return ans;
}
matrix matBigMod(matrix n, int r) {
//    if(!n) return 0;
//    cout << r << endl;
    if(!r) return matrix(1);
//    cout << "AFTER BASE" << endl;
    if(r%2) return matMul( matBigMod(n, r-1) , n );
    matrix ans = matBigMod(n, r/2);
    return matMul(ans,ans);
}

int n;
ull g1,g2;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        ///MUST CHANGE MATRIX SIZE HERE
        scanf("%llu %llu %d", &g1,&g2, &n);

        if(abs(n) < 1) {
            printf("Case %d: 2\n", t);
            continue;
        }

        matRow = matCol = 2;
        matrix co = matrix(0);
        co.mat[0][0] = (ull) g1 ; co.mat[0][1] = -g2;
        co.mat[1][0] = 1  ; co.mat[1][1] = 0;

        co = matBigMod(co, n-1 );

//        for(int i=0; i<2; i++) {
//            for(int j=0; j<2; j++) {
//                cout << co.mat[i][j] << ' ';
//            }
//            cout << endl;
//        }

        printf("Case %d: %llu\n", t, co.mat[0][0]*g1 + 2*co.mat[0][1]);
    }
    return 0;

}

