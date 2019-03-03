#include<bits/stdc++.h>

using namespace std;

int main() {
    int t=1,n,m;
    while(scanf("%d %d", &n,&m)) {
        if(!n && !m) return 0;

        if(n == 1) {
            printf("Case %d: :-\\\n", t++);
        }
        else if(n <= m) {
            printf("Case %d: :-|\n", t++);
        }
        else {
            printf("Case %d: :-(\n", t++);
        }

    }
}
