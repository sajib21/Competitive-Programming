#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n;
ll dp[305][505];

ll getMax( ll brick, ll last) {
    if(!brick) {
            cout << last << "thamse\n";
            return 1;
    }
    if(brick < 0 ) return 0;
    if(last+1 == brick) {

        return 1;

    }
    if(last >= brick) return 0;

    //cout << brick << "\t" << last << "\n";

    if(dp[brick][last] == -1) {
        ll temp = 0;
        for(ll i=last+1; i <= brick ; i++) {
            //if(i==4) printf("ekbar i %lld brick %lld\n", i, brick);
            printf("%lld %lld %lld\n",brick,i, temp);
            //if(getMax( brick-i, i) ) {
                temp += getMax(brick-i, i);
                printf("sudhu temp1 %lld\n", temp);
            //}
            //printf("%lld %lld %lld\n",brick-i,i, temp);
            //else break;
        }
        printf("sudhu temp2 %lld\n", temp);
        dp[brick][last] = temp;
    }

    return dp[brick][last];


}

int main() {
    cin >> n;

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", getMax(n, 0)-1);
}
