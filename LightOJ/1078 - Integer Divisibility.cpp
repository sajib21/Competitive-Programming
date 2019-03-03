#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        int n,d, c,x, cnt = 1, total;
        scanf("%d %d", &n,&d);
        x = d % n;
        c = 10 % n;
        total = x;
        while(total % n != 0) {
//            cout << x << endl;
//            getchar();
            cnt++;
            x = (c*x)%n ;
            total = (total+x) % n;
        }
        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
