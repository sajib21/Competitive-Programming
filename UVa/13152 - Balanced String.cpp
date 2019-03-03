#include<bits/stdc++.h>
#define MAX 50000
using namespace std;

int n,x, cnt[100005], gese;
string ans;
bool f(int u) {
//    cout << "F " << u << ' ' << gese << endl; getchar();
    for( ; gese<n; gese++) {
        if(cnt[u+1]) {
            u++;
            cnt[u]--; //gese++;
            ans += "(";
        }
        else if(u && cnt[u-1]) {
            u--;
            cnt[u]--; //gese++;
            ans += ")";
        }
        else break;
    }

    return u == 0 && gese == n;
}

int main() {
//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w", stdout);
    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++) {
        memset(cnt, 0, sizeof cnt);
        ans = "";
        gese = 0;
        bool g = true;

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(x > MAX || x < 0) g = false;
            if(g) cnt[x]++;
        }
//        if(!n) {
//            printf("Case %d: t")
//        }
        if(!g || !cnt[1] || !cnt[0]) {
            printf("Case %d: invalid\n", t);
            continue;
        }
        ans = "("; cnt[1]--; gese++;
        bool res = f(1);
        if(res) {
            printf("Case %d: ", t);
//            cout << ans << endl;
            for(int i=0; i<n; i++) printf("%c", ans[i]); printf("\n");
        }
        else printf("Case %d: invalid\n", t);
//        cout << ans << endl;
    }
}
