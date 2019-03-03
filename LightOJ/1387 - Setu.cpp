#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T ;t++) {
        int n;
        string cmd;
        int am, tot = 0;

        scanf("%d", &n);
        printf("Case %d:\n", t);
        while(n--) {
            cin >> cmd;

            if(cmd == "donate") {
                scanf("%d", &am);
                tot += am;
            }
            else {
                printf("%d\n", tot);
            }
        }
    }
    return 0;
}
