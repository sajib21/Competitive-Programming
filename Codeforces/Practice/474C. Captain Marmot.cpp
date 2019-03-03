#include<bits/stdc++.h>

using namespace std;

int dirx[] = {+1, -1, -1, +1};
int diry[] = {+1, +1, -1, -1};

int xx[5],yy[5], a[5],b[5];
int x[5][5],y[5][5];

void rol(int home, int newP) {

    int oldP = newP - 1;
    if(x[home][oldP] < )
}

bool checkSquare(int p, int q, int r, int s) {


}

int moves(int p, int q, int r, int s) {

    int mv = 0;
    if(x[0][p] == xx[0]) {
        if(y[0][p] == yy[0]);
        else mv +=
    }
}

int main() {

    int n;
    cin >> n;
    while(n--) {



        for(int i=0; i<4; i++) {
            cin >> xx[i] >> yy[i] >> a[i] >> b[i];
//            xx[i] -= a[i]; yy[i] -= b[i];
//            int dx = abs(xx[i]), dy = abs(yy[i]);
            x[i][0] = xx[i], y[i][0] = yy[i];
            for(int j=1; j<4; j++) {
                rol(i,j);
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                for(int k=0; k<4; k++) {
                    for(int l=0; l<4; l++) {
                        if(checkSquare(i,j,k,l) ) {
                            ans = min(ans, moves(i,j,k,l) );
                        }

                    }
                }
            }
        }
    }
}
