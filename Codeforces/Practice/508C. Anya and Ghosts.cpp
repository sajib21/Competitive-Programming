#include<bits/stdc++.h>

using namespace std;

int main() {

    int m,t,r, timeLine[606] = {0}, tim, vis[303] = {0}, last=0;
    cin >> m >> t >> r;
    if(t < r) {
        cout << "-1" << endl;
        return 0;
    }

    for(int i=0; i<m; i++) {
        cin >> tim;
        vis[tim] = 1;
        last = max(last, tim);
    }

    int candles = 0;
    for(tim=1; tim<=last; tim++) {
        timeLine[tim] += timeLine[tim-1];
        if(vis[tim]) {
            if(timeLine[tim] < r) {
                int c = r - timeLine[tim];
                candles += c;
                timeLine[tim] = r;
                for(int i=tim+t, j=0; j<c; j++, i--) {
                    timeLine[i]--;
                }
            }
        }
    }

//    for(int i=1; i<=last; i++) cout << timeLine[i] << ' '; cout << endl;

    cout << candles << endl;

}
