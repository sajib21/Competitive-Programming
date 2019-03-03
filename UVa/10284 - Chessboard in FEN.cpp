#include<bits/stdc++.h>

using namespace std;

int main() {

    char s[100];
    char board[10][10];
    int sq[10][10];

    while(scanf("%s", &s) != EOF) {

        //memset(sq, 1, sizeof(sq));
        for(int i=1; i<9; i++) {
            for(int j=1; j<9; j++) {
                sq[i][j] = 1;
            }
            //cout << endl;
        }


        int sz = strlen(s);
        int r=1, c=1;
        for(int i=0; i<sz; i++) {

            if(s[i] == '/') {
                r++;
                c=1;
            }

            else if(s[i] > '0' && s[i] < '9') {
                for(int b=0; b < s[i]-'0'; b++) {
                    board[r][c++] = 0;
                }
            }
            else {
                if(s[i] == 'p' || s[i] == 'P') board[r][c++] = s[i];
                else board[r][c++] = toupper(s[i]);
            }
        }

//        for(int i=1; i<9; i++) {
//            for(int j=1; j<9; j++) {
//                cout << board[i][j];
//            }
//            cout << endl;
//        }
//
//        cout << "debug" << endl;

        for(r=1; r<=8; r++) {
            for(c=1; c<=8; c++) {

                if(!board[r][c]) {
                    //cout << "dekhi to continue;" << endl;
                    continue;
                }

//                cout << "dhukse  " << r << ' ' <<  c << ' ' << board[r][c] <<  endl;



                if(board[r][c] == 'p') {
                    sq[r][c] = sq[r+1][c-1] = sq[r+1][c+1] = 0;
                }
                else if(board[r][c] == 'P') {
                    sq[r][c] = sq[r-1][c-1] = sq[r-1][c+1] = 0;
                }

                else if(board[r][c] == 'R') {

                    int rr, cc;

                    rr = r;
                    do {
                        sq[rr--][c] = 0;
                    } while( !board[rr][c] && rr >0);

                    rr = r;
                    do {
                        sq[rr++][c] = 0;
                    } while( !board[rr][c] && rr <=8);

                    cc = c;
                    do {
                        sq[r][cc--] = 0;
                    } while( !board[r][cc] && cc >0);

                    cc = c;
                    do {
                        sq[r][cc++] = 0;
                    } while( !board[r][cc] && cc <=8);
                }

                else if(board[r][c] == 'N') {

                    sq[r][c] = 0;

                    if(r-2 > 0 && c-1 > 0 && !board[r-2][c-1]) sq[r-2][c-1] = 0;
                    if(r-1 > 0 && c-2 > 0 && !board[r-1][c-2]) sq[r-1][c-2] = 0;
                    if(r-2 > 0 && c+1 > 0 && !board[r-2][c+1]) sq[r-2][c+1] = 0;
                    if(r-1 > 0 && c+2 > 0 && !board[r-1][c+2]) sq[r-1][c+2] = 0;
                    if(r+2 > 0 && c-1 > 0 && !board[r+2][c-1]) sq[r+2][c-1] = 0;
                    if(r+1 > 0 && c-2 > 0 && !board[r+1][c-2]) sq[r+1][c-2] = 0;
                    if(r+2 > 0 && c+1 > 0 && !board[r+2][c+1]) sq[r+2][c+1] = 0;
                    if(r+1 > 0 && c+2 > 0 && !board[r+1][c+2]) sq[r+1][c+2] = 0;
                }

                else if(board[r][c] == 'B') {

                    int rr,cc;

                    sq[r][c] = 0;

                    rr = r; cc = c;
                    do {
                        sq[rr--][cc--] = 0;
                    } while( !board[rr][cc] && rr >0 && cc >0);

                    rr = r; cc = c;
                    do {
                        sq[rr++][cc--] = 0;
                    } while( !board[rr][cc] && rr <=8 && cc >0);

                    rr=r; cc = c;
                    do {
                        sq[rr--][cc++] = 0;
                    } while( !board[rr][cc] && rr >0 && cc <=8);

                    rr = r; cc = c;
                    do {
                        sq[rr++][cc++] = 0;
                    } while( !board[rr][cc] && rr <=8 && cc <=8);
                }

                else if(board[r][c] == 'Q') {

                    int rr, cc;

                    rr = r;
                    do {
                        sq[rr--][c] = 0;
                    } while( !board[rr][c] && rr >0);

                    rr = r;
                    do {
                        sq[rr++][c] = 0;
                    } while( !board[rr][c] && rr <=8);

                    cc = c;
                    do {
                        sq[r][cc--] = 0;
                    } while( !board[r][cc] && cc >0);

                    cc = c;
                    do {
                        sq[r][cc++] = 0;
                    } while( !board[r][cc] && cc <=8);

//                                        cout << "bujhlam na Q te ki hoilo : " << r << ' ' << c << endl;


                    sq[r][c] = 0;



                    rr = r; cc = c;
                    do {
                        sq[rr--][cc--] = 0;
                    } while( !board[rr][cc] && rr >0 && cc >0);

                    rr = r; cc = c;
                    do {
                        sq[rr++][cc--] = 0;
                    } while( !board[rr][cc] && rr <=8 && cc >0);

                    rr=r; cc = c;
                    do {
                        sq[rr--][cc++] = 0;
                    } while( !board[rr][cc] && rr >0 && cc <=8);

                    rr = r; cc = c;
                    do {
                        sq[rr++][cc++] = 0;
                    } while( !board[rr][cc] && rr <=8 && cc <=8);

//                    cout << "bujhlam na Q te ki hoilo : " << r << ' ' << c << endl;

                }

                else if(board[r][c] == 'K') {

                    sq[r][c] = 0;

                    sq[r-1][c-1] = 0;
                    sq[r-1][c] = 0;
                    sq[r-1][c+1] = 0;
                    sq[r][c-1] = 0;
                    sq[r][c+1] = 0;
                    sq[r+1][c-1] = 0;
                    sq[r+1][c] = 0;
                    sq[r+1][c+1] = 0;
                }

//                            for(int i=1; i<9; i++) {
//                for(int j=1; j<9; j++) {
//                    cout << sq[i][j];
//                }
//                cout << endl;
//            }
//            cout << endl;

                //getchar();
            }


        }
//
//        cout << "sob pore" << endl;
//
//                for(int i=1; i<9; i++) {
//            for(int j=1; j<9; j++) {
//                cout << sq[i][j];
//            }
//            cout << endl;
//        }

        int fil = 0;

        for(int r=1; r<=8; r++) {
            for(int c=1; c<=8; c++) {
                fil += sq[r][c];
            }
        }

        cout << fil << endl;

    }
}

///PNBRQK
