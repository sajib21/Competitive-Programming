#include<bits/stdc++.h>

using namespace std;

char seq[10][25];
int con;

int cost(int x) {
    int ans = 0;
    while(x) {
        int m = x%2;
        if(m) ans += 500;
        else  ans += 250;
        x /= 2;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        for(int i=0; i<8; i++) scanf("%s", seq[i]);

        int x,y;

        for(int i=0; i<8; i++) if(seq[i][1] == '_') {
            x = i;
            if(x == 4) y = 6;
            if(x == 5) y = 5;
            if(x == 6) y = 4;
            break;
        }
        x--; y--;

        if(x == y) con = 0; ///soman
        else if(x > y) con = 1; ///left boro
        else con = 2; ///right boro

        int w1=0, w2=0;

        for(int i=1; ; i++) {
            if(seq[x][i] < 'A' || seq[x][i] > 'Z') break;
            w1 += cost(seq[x][i]);
        }

        for(int i=11; ; i++) {
            if(seq[y][i] < 'A' || seq[y][i] > 'Z') break;
            w2 += cost(seq[y][i]);
        }

        if(con == 0 && w1 == w2) printf("Case %d:\nThe figure is correct.\n", t);
        else if(con == 1 && w1 > w2) printf("Case %d:\nThe figure is correct.\n", t);
        else if(con == 2 && w1 < w2) printf("Case %d:\nThe figure is correct.\n", t);
        else {
            if(w1 == w2) {
                char sol[10][25] = {
                    "........||........ ",
                    ".../\\...||.../\\... ",
                    "../..\\..||../..\\.. ",
                    "./....\\.||./....\\. ",
                    "/......\\||/......\\ ",
                    "\\______/||\\______/ ",
                    "........||........ ",
                    "------------------ "
                };
                for(int i=1; ; i++) {
                    if(seq[x][i] < 'A' || seq[x][i] > 'Z') break;
                    sol[4][i] = seq[x][i];
                }
                for(int i=11; ; i++) {
                    if(seq[y][i] < 'A' || seq[y][i] > 'Z') break;
                    sol[4][i] = seq[y][i];
                }
                printf("Case %d:\n", t);
                for(int i=0; i<7; i++) {
                    for(int j=0; j<18; j++) printf("%c", sol[i][j]);
                    printf("\n");
                }
            }
            else if(w1 > w2) {
                char sol[10][25] = {
                    "........||.../\\... ",
                    "........||../..\\.. ",
                    ".../\\...||./....\\. ",
                    "../..\\..||/......\\ ",
                    "./....\\.||\\______/ ",
                    "/......\\||........ ",
                    "\\______/||........ ",
                    "------------------ "
                };
                for(int i=1; ; i++) {
                    if(seq[x][i] < 'A' || seq[x][i] > 'Z') break;
                    sol[5][i] = seq[x][i];
                }
                for(int i=11; ; i++) {
                    if(seq[y][i] < 'A' || seq[y][i] > 'Z') break;
                    sol[3][i] = seq[y][i];
                }
                printf("Case %d:\n", t);
                for(int i=0; i<7; i++) {
                    for(int j=0; j<18; j++) printf("%c", sol[i][j]);
                    printf("\n");
                }
            }
            else {
                char sol[10][25] = {
                    ".../\\...||........ ",
                    "../..\\..||........ ",
                    "./....\\.||.../\\... ",
                    "/......\\||../..\\.. ",
                    "\\______/||./....\\. ",
                    "........||/......\\ ",
                    "........||\\______/ ",
                    "------------------ "
                };
                for(int i=1; ; i++) {
                    if(seq[x][i] < 'A' || seq[x][i] > 'Z') break;
                    sol[3][i] = seq[x][i];
                }
                for(int i=11; ; i++) {
                    if(seq[y][i] < 'A' || seq[y][i] > 'Z') break;
                    sol[5][i] = seq[y][i];
                }
                printf("Case %d:\n", t);
                for(int i=0; i<7; i++) {
                    for(int j=0; j<18; j++) printf("%c", sol[i][j]);
                    printf("\n");
                }
            }


        }

    }
}
