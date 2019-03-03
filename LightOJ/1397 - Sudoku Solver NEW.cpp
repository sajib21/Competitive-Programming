#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info{
    int x,y, k;
    info() {}
    info(int xx, int yy, int kk) {
        x = xx; y = yy; k = kk;
    }
    bool operator < (const info &b) const {
        return k > b.k;
    }
};

char grid[10][10];
bool colFlag[10][10], rowFlag[10][10], matFlag[10][10];
bool option[10][10][10];
int matrix[10][10], optCnt[10][10];
int remain;

info matPtr[10];

bool backTrack(int rem) {
    if(!rem) return true;

    priority_queue<info>pq;
    for(int row=1; row<=9; row++) for(int col=1; col<=9; col++) if(!matrix[row][col]) pq.push(info(row,col, optCnt[row][col]));

    while(!pq.empty()) {
        info nd = pq.top(); pq.pop();
        int row = nd.x, col = nd.y;
//        cout << nd.k << endl; getchar(); getchar();
//        if(nd.k > 3) continue;
        int mat = (row-1)/3 *3 + (col+2)/3;

        for(int val=1; val<=9; val++) {
            if(!colFlag[col][val] && !rowFlag[row][val] && !matFlag[mat][val] && option[row][col][val]) {
                int r,c;
                r = matPtr[mat].x ; c = matPtr[mat].y;

                matrix[row][col] = val;
                colFlag[col][val] = 1; rowFlag[row][val] = 1; matFlag[mat][val] = 1;

                int backUpOption[10][10][10] = {0} , backUpOptionCount[10][10] = {0} ;

                for(int c=1; c<=9; c++) backUpOption[row][c][val] = option[row][c][val] , backUpOptionCount[row][c] = optCnt[row][c];
                for(int r=1; r<=9; r++) backUpOption[r][col][val] = option[r][col][val] , backUpOptionCount[r][col] = optCnt[r][col];
                for(int i=r; i<r+3; i++) for(int j=c; j<c+3; j++) backUpOption[i][j][val] = option[i][j][val] , backUpOptionCount[i][j] = optCnt[i][j];

                option[row][col][val] = optCnt[row][col] = 0;
                for(int c=1; c<=9; c++) if(option[row][c][val]) option[row][c][val] = 0 , optCnt[row][c]--;
                for(int r=1; r<=9; r++) if(option[r][col][val]) option[r][col][val] = 0 , optCnt[r][col]--;
                for(int i=r; i<r+3; i++) for(int j=c; j<c+3; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;

                if( backTrack(rem-1) ) return true;

                colFlag[col][val] = 0; rowFlag[row][val] = 0; matFlag[mat][val] = 0; option[row][col][val] = 1;
                matrix[row][col] = 0;

                for(int c=1; c<=9; c++) option[row][c][val] = backUpOption[row][c][val] , optCnt[row][c] = backUpOptionCount[row][c];
                for(int r=1; r<=9; r++) option[r][col][val] = backUpOption[r][col][val] , optCnt[r][col] = backUpOptionCount[r][col];
                for(int i=r; i<r+3; i++) for(int j=c; j<c+3; j++) option[i][j][val] = backUpOption[i][j][val] , optCnt[i][j] = backUpOptionCount[i][j];
            }
        }
        return false;
    }
    return false;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    matPtr[1] = info(1,1,0); matPtr[2] = info(1,4,0); matPtr[3] = info(1,7,0);
    matPtr[4] = info(4,1,0); matPtr[5] = info(4,4,0); matPtr[6] = info(4,7,0);
    matPtr[7] = info(7,1,0); matPtr[8] = info(7,4,0); matPtr[9] = info(7,7,0);



    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(matrix , 0, sizeof(matrix ));
        memset(rowFlag, 0, sizeof(rowFlag));
        memset(colFlag, 0, sizeof(colFlag));
        memset(matFlag, 0, sizeof(matFlag));
        memset(option , 0, sizeof(option ));
        memset(optCnt , 0, sizeof(optCnt ));
        remain = 0;
        for(int i=0; i<9; i++) scanf("%s", grid[i]);
        for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(grid[i][j] == '.') remain++;

        for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matrix[i+1][j+1] = grid[i][j] - '0';

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') {
                rowFlag[i+1][ grid[i][j] - '0' ] = 1;
                colFlag[j+1][ grid[i][j] - '0' ] = 1;
            }
        }

        for(int i=0; i<3; i++) for(int j=0; j<3; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[1][ grid[i][j] - '0' ] = 1;
        for(int i=0; i<3; i++) for(int j=3; j<6; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[2][ grid[i][j] - '0' ] = 1;
        for(int i=0; i<3; i++) for(int j=6; j<9; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[3][ grid[i][j] - '0' ] = 1;
        for(int i=3; i<6; i++) for(int j=0; j<3; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[4][ grid[i][j] - '0' ] = 1;
        for(int i=3; i<6; i++) for(int j=3; j<6; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[5][ grid[i][j] - '0' ] = 1;
        for(int i=3; i<6; i++) for(int j=6; j<9; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[6][ grid[i][j] - '0' ] = 1;
        for(int i=6; i<9; i++) for(int j=0; j<3; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[7][ grid[i][j] - '0' ] = 1;
        for(int i=6; i<9; i++) for(int j=3; j<6; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[8][ grid[i][j] - '0' ] = 1;
        for(int i=6; i<9; i++) for(int j=6; j<9; j++) if(grid[i][j] > '0' && grid[i][j] <= '9') matFlag[9][ grid[i][j] - '0' ] = 1;

//        cout << rowFlag[1][1] << ' ' << colFlag[1][1] << ' ' << matFlag[1][1] << endl; getchar();

        ///SETTING OPTIONS : PHASE 1
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                for(int k=1; k<=9; k++) {
                    int mat = (i-1)/3 *3 + (j+2)/3;
                    if(!matrix[i][j] && !rowFlag[i][k] && !colFlag[j][k] && !matFlag[mat][k]) {
                        option[i][j][k] = 1;
                        optCnt[i][j]++;
                    }
                }
            }
        }

        ///SETTING OPTIONS : PHASE 2


//        cout << "OPTIONS " << endl;
//        for(int i=1; i<=9; i++) for(int j=1; j<=9; j++) {
//            cout << i << ' ' << j << " : " ;
//            for(int k=1; k<=9; k++) cout << option[i][j][k] << ' ' ;
//            cout << endl;
//        }
//        cout << "OPTCNT" << endl;
//        for(int i=1; i<=9; i++) {
//            for(int j=1; j<=9; j++) cout << optCnt[i][j] << ' ';
//            cout << endl;
//        }
//
//        getchar(); getchar();

        backTrack(remain);

        printf("Case %d:\n", t);
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                printf("%d", matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

/*
123
8769.....
.1...6...
.4.3.58..
4.....21.
.9.5.....
.5..4.3.6
.29.....8
..469.173
.....1..4
*/
