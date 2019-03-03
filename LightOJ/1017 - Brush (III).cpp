#include<bits/stdc++.h>

using namespace std;

int n,nn,w,k;
vector<int> dustY;
map<int, int> mpY;
int dp[110][110];

int getMax(int mv, int indx) {

    if(mv==k) return 0;
    if(dp[mv][ indx ] != -1) return dp[mv][indx];

    int dust = 0;
    for(int i=indx; i<nn; i++) {

        //if(dustY[i] == pre) continue;

        int tempDust = 0; int j;
        //int x = i;
//        for(j= dustY[i] ; j<=dustY[i]+w; j++) {
//            tempDust += mpY[j];
//            if(mpY[j]) x++;
//        }
        for(j=i; dustY[j] <= dustY[i]+w && j <nn; j++) {
            tempDust += mpY[ dustY[j] ];
        }
        //cout << "indx " << dustY[i] << " theka init nitase " << tempDust << endl;
        dust = max(dust, tempDust + getMax(mv+1, j));
        //cout << "indx " << dustY[i] << "theka max nitase " << dust << endl;
    }

    return dp[mv][indx] = dust;
}

int main() {

    int t,T;
    cin >> T;
    for(t=1; t<=T; t++) {

        memset(dp, -1, sizeof(dp));
        //memset(dustY, 0, sizeof(dustY));
        dustY.clear();
        mpY.clear();

        cin >> n >> w >> k;
        nn = 0;
        for(int i=0; i<n; i++) {
            int x,y;
            cin >> x >> y;
            if(!mpY[ y ]) {
                dustY.push_back(y);
                nn++;
            }
            mpY[y]++;
        }

        sort(dustY.begin(), dustY.end());

        printf("Case %d: %d\n", t, getMax(0, 0));

    }

    return 0;
}
