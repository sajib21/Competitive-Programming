#include<bits/stdc++.h>

using namespace std;

int n, q, x;
map<int,int>cnt;

int main() {
    scanf("%d %d", &n,&q);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    while(q--) {
        scanf("%d", &x);

        map<int,int>:: iterator it = cnt.end();

        int ans = 0;
        while(x) {
            it--;
            int v = it->first;
            int w = it->second;

            int c = x/v;
            ans += min(c, w);
            x -= min(c,w)*v;

            if(it == cnt.begin()) break;
        }
        if(!x) printf("%d\n", ans);
        else printf("-1\n");
    }
}
