#include<bits/stdc++.h>

using namespace std;

int dirR[] = {+1, -1, -2, -2, -1, -3};
int dirC[] = {-2, -2, -1, +1, -3, -1};

int n;
int grundy[503][503];

int genGrundy(int r, int c) {

    if(grundy[r][c] != -1 ) return grundy[r][c];

    set<int>st;
    for(int i=0; i<6; i++) {
        if(r+dirR[i] >= 0 && r+dirR[i] <= 500 && c+dirC[i] >= 0 && c+dirC[i] <= 500) {
            st.insert( genGrundy(r+dirR[i], c+dirC[i]) );
        }
    }
    int ans = 0;
    while(st.find(ans) != st.end()) ans++;
    return grundy[r][c] = ans;
}

int main() {

    memset(grundy, -1, sizeof(grundy));
    grundy[0][0] = grundy[0][1] = grundy[1][0] = 0;
    for(int i=0; i<=500; i++) {
        for(int j=0; j<=500; j++) {
            if(grundy[i][j] == -1) {
                genGrundy(i,j);
            }
        }
    }

//    for(int i=0; i<8; i++) {
//        for(int j=0; j<8; j++) {
//            cout << grundy[i][j] << ' ';
//        }
//        cout << endl;
//    }

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        scanf("%d", &n);
        int r,c, xsum=0;

        for(int i=0; i<n; i++) {
            scanf("%d %d", &r,&c);
            xsum ^= grundy[r][c];
        }

        if(xsum) printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }

    return 0;

}
