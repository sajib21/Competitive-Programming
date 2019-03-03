#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int n;
ll fib[70];
string ans;

int main() {

    fib[0] = 0;
    fib[1] = 1;
    for(int i=2; i<=46; i++) fib[i] = fib[i-1] + fib[i-2];
//    cout << fib[45] << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ans = "";
//        cout << ans << endl;
        scanf("%d", &n); n++;

        for(int i=0; i<45; i++) {
            ll temp;

            temp = fib[45-i+1];
            if(temp >= n) {
                ans += '0';
                continue;
            }
            else {
                n -= temp;
            }

//            if(60-i >= 0) {
                temp = fib[45-i];
                if(temp >= n) {
                    ans += "10";
                    i++;
                }
                else {
                    n -= temp;
                }
//            }
        }
        int x=0;
        while(ans[x] == '0' && x < 45) x++;
        printf("Case %d: ", t);
        for(int i=x; i<45; i++) printf("%c", ans[i]); printf("\n");
    }

    return 0;
}
