#include<bits/stdc++.h>
#define ll long long int
 #define LIM 1000000

using namespace std;

int n, dif[LIM+10];
int x,y, mx;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(dif, 0, sizeof(dif));
        mx = 0;
        scanf("%d", &n);
//        scanf("%d", &x);
        x = 0;
        for(int i=0; i<n; i++) {
            scanf("%d", &y);
            dif[i] = y - x;
            x = y;
            mx = max(mx, dif[i]);
        }


        for(int i=0; i<n; i++) {
//            cout << dif[i] << endl;
            if(dif[i] == mx) {
                int temp = mx;
                for(int j=i; j<n; j++) {
                    if(dif[j] == temp) temp--;
                    else if(dif[j] > temp) {
                        mx++;
                        goto here;
                    }
//                    i = j;
                }
            }
        }
        here:
        printf("Case %d: %d\n", t, mx);
    }
    return 0;

}
