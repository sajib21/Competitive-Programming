#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T;t++) {
        int d,m,y,Y;
        scanf("%d %d %d %d", &d,&m,&y,&Y);
        if(d == 29 && m == 2) {
            int ans = 0;
            for(int i=y+4; i<=Y; i+=4) {
                if(i%400==0) ans++;
                else if(i%100) ans++;
            }
            printf("Case %d: %d\n", t, ans);
        }
        else printf("Case %d: %d\n", t, Y-y);
    }
}
