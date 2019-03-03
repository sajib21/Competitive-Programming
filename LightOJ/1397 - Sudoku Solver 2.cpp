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

char grid[10][10];
bool colFlag[10][10], rowFlag[10][10], matFlag[10][10];
bool option[10][10][10];
int matrix[10][10], optCnt[10][10];
int remain;

bool backTrack(int rem) {
//    if(row > 9) return true;
//    if(col > 9) return backTrack(row+1, 1);
//    if(matrix[row][col]) return backTrack(row, col+1);
//    cout << rem << endl;
    if(!rem) return true;

    for(int row=1; row<=9; row++) {
        for(int col=1; col<=9; col++) {
            if(!matrix[row][col] && optCnt[row][col] < 9) {

                int mat = (row-1)/3 *3 + (col+2)/3;
            //    cout << "IN  " << row << ' ' << col << ' ' << mat << ' ' << matrix[row][col] << endl; getchar();
                for(int val=1; val<=9; val++) {
            //        cout << rowFlag[row][val] << ' ' << colFlag[col][val] << ' ' << matFlag[mat][val] << endl;
                    if(!colFlag[col][val] && !rowFlag[row][val] && !matFlag[mat][val] && option[row][col][val]) {
            //            cout << "OUT " << row << ' ' << col << ' ' << mat << ' ' << val << endl;
            //            getchar();
                        matrix[row][col] = val;
                        colFlag[col][val] = 1; rowFlag[row][val] = 1; matFlag[mat][val] = 1;

                        int BackUpRow[10][10] = {0} , BackUpCol[10][10] = {0} , BackUpMat[10][10][10] = {0} ;

                        for(int c=1; c<=9; c++) BackUpRow[c][val] = option[row][c][val];
                        for(int r=1; r<=9; r++) BackUpCol[r][val] = option[r][col][val];
                        if(mat == 1) for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 2) for(int i=1; i<=3; i++) for(int j=4; j<=6; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 3) for(int i=1; i<=3; i++) for(int j=7; j<=9; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 4) for(int i=4; i<=6; i++) for(int j=1; j<=3; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 5) for(int i=4; i<=6; i++) for(int j=4; j<=6; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 6) for(int i=4; i<=6; i++) for(int j=7; j<=9; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 7) for(int i=7; i<=9; i++) for(int j=1; j<=3; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 8) for(int i=7; i<=9; i++) for(int j=4; j<=6; j++) BackUpMat[i][j][val] = option[i][j][val];
                        if(mat == 9) for(int i=7; i<=9; i++) for(int j=7; j<=9; j++) BackUpMat[i][j][val] = option[i][j][val];


                        for(int c=1; c<=9; c++) if(option[row][c][val]) option[row][c][val] = 0 , optCnt[row][c]--;
                        for(int r=1; r<=9; r++) if(option[r][col][val]) option[r][col][val] = 0 , optCnt[r][col]--;
                        if(mat == 1) for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 2) for(int i=1; i<=3; i++) for(int j=4; j<=6; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 3) for(int i=1; i<=3; i++) for(int j=7; j<=9; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 4) for(int i=4; i<=6; i++) for(int j=1; j<=3; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 5) for(int i=4; i<=6; i++) for(int j=4; j<=6; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 6) for(int i=4; i<=6; i++) for(int j=7; j<=9; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 7) for(int i=7; i<=9; i++) for(int j=1; j<=3; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 8) for(int i=7; i<=9; i++) for(int j=4; j<=6; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;
                        if(mat == 9) for(int i=7; i<=9; i++) for(int j=7; j<=9; j++) if(option[i][j][val]) option[i][j][val] = 0 , optCnt[i][j]--;

                        if(row == 1 && col == 1 && val == 1 && rem == remain) {
                            cout << "TRYING AT " << row << ' ' << col << ' ' << val << endl;
                            for(int i=1; i<=9; i++) {
                                for(int j=1; j<=9; j++) cout << optCnt[i][j] ;
                                cout << endl;
                            }
                            cout << "MATRIX " << endl;
                            for(int i=1; i<=9; i++) {
                                for(int j=1; j<=9; j++) cout << matrix[i][j] ;
                                cout << endl;
                            }
                            cout << endl;
                            getchar();
                        }




                        if( backTrack(rem-1) ) return true;
                        colFlag[col][val] = 0; rowFlag[row][val] = 0; matFlag[mat][val] = 0; option[row][col][val] = 1;
                        matrix[row][col] = 0;

                        for(int c=1; c<=9; c++) if(BackUpRow[c][val] && !option[row][c][val]) option[row][c][val] = BackUpRow[c][val] , optCnt[row][c]++;
                        for(int r=1; r<=9; r++) if(BackUpCol[r][col] && !option[r][col][val]) option[r][col][val] = BackUpCol[r][val] , optCnt[r][col]++;
                        if(mat == 1) for(int i=1; i<=3; i++) for(int j=1; j<=3; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 2) for(int i=1; i<=3; i++) for(int j=4; j<=6; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 3) for(int i=1; i<=3; i++) for(int j=7; j<=9; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 4) for(int i=4; i<=6; i++) for(int j=1; j<=3; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 5) for(int i=4; i<=6; i++) for(int j=4; j<=6; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 6) for(int i=4; i<=6; i++) for(int j=7; j<=9; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 7) for(int i=7; i<=9; i++) for(int j=1; j<=3; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 8) for(int i=7; i<=9; i++) for(int j=4; j<=6; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;
                        if(mat == 9) for(int i=7; i<=9; i++) for(int j=7; j<=9; j++) if(BackUpMat[i][j][val] && !option[i][j][val]) option[i][j][val] = BackUpMat[i][j][val] , optCnt[i][j]++;


                        if(row == 1 && col == 1 && val == 1 && rem == remain) {
                            cout << "RETURN " << row << ' ' << col << ' ' << val << endl;
                            for(int i=1; i<=9; i++) {
                                for(int j=1; j<=9; j++) cout << optCnt[i][j] << ' ' ;
                                cout << endl;
                            }
                            cout << "MATRIX " << endl;
                            for(int i=1; i<=9; i++) {
                                for(int j=1; j<=9; j++) cout << matrix[i][j] ;
                                cout << endl;
                            }
                            cout << endl;
                            getchar();
                        }
                    }
                }
                return false;
            }
        }
    }



    return false;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

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
//        for(int j=0; j<9; j++) {
//            for(int i=0; i<9; i++) if(grid[i][j] > '0' && grid[i][j] <= '9') {
//                colFlag[j+1][ grid[i][j] - '0' ] = 1;
//            }
//        }
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
        cout << "OPTCNT" << endl;
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) cout << optCnt[i][j] << ' ';
            cout << endl;
        }

        getchar(); getchar();


//        cout << "ROWFLAG" << endl;
//        for(int i=1; i<=9; i++) {
//            for(int j=1; j<=9; j++) cout << rowFlag[i][j] << ' ' ;
//            cout << endl;
//        }
//        cout << "COLFLAG" << endl;
//        for(int i=1; i<=9; i++) {
//            for(int j=1; j<=9; j++) cout << colFlag[i][j] << ' ' ;
//            cout << endl;
//        }
//        cout << "MATFLAG" << endl;
//        for(int i=1; i<=9; i++) {
//            for(int j=1; j<=9; j++) cout << matFlag[i][j] << ' ' ;
//            cout << endl;
//        }

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

