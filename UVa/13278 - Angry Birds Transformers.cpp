#include<bits/stdc++.h>
#define MIN 0
#define MAX 10004
using namespace std;

int n, x,y, cnt[20004];

int main() {
    int T;
//    scanf("%d", &T);
    for(int t=1; ; t++) {
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        if(!n) return 0;
        for(int i=0; i<n; i++) {
            scanf("%d %d", &x,&y);
            cnt[max(MIN,x-y)  ]++;
            cnt[min(MAX,x+y)+1]--;
        }
        int ans = 0;
        for(int i=1; i<=MAX; i++) {
            cnt[i] += cnt[i-1];
            ans = max(ans, cnt[i]);
        }
        printf("%d\n", ans);
    }
}
