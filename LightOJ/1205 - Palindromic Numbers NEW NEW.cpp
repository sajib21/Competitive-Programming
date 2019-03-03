#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

ll palCnt[20], palCumCnt[20];
string a,b;

ll sz1, sz2, cnt1, cnt2;

string numToString(ll num) {
    string n;
    if(num < 0) return "-1";
    if(num == 0) return "0";
    while(num > 0LL) {
        n += (num%10) + '0';
        num /= 10;
    }
    reverse(n.begin(), n.end());
    return n;
}

ll palCount(string num) {

    if(num == "0") return 1LL;

    int sz = num.size();

    bool palChk[19] = {false};
    int m1,m2;
    m1 = (sz-1)/2 ; m2 = sz/2;

    while(m1 >= 0) {
        if(num[m1] != num[m2]) break;
        palChk[m1] = palChk[m2] = true;
        m1--; m2++;
    }

    ll ans = 1;

    for(int p=0, q=sz-1; p<sz && p<=q; p++, q--) {
        int mul;
        if(!p) mul = num[p] - '0' - 1;
        else mul = num[p] - '0';

        if(p == q) ans += mul*palCnt[0];
        else ans += mul*palCnt[q-p-1];
        if(num[p] > num[q] && ( (abs(p-q) > 1 && palChk[p+1] ) || abs(p-q) <= 1)  ) ans--;
    }

    return ans + (palCumCnt[sz-1]) + 1;

}

int main() {
    palCnt[0] = 1; palCnt[1] = palCnt[2] = 10;
    palCumCnt[0] = 0; palCumCnt[1] = 9, palCumCnt[2] = 18;
    for(int i=3; i<18; i++) palCnt[i] = 10*palCnt[i-2];
    for(int i=3; i<18; i++) palCumCnt[i] = palCumCnt[i-1] + palCnt[i] - palCnt[i-2];

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int i,j;
        ll aa,bb;
        scanf("%lld %lld", &aa,&bb);
        if(aa > bb) swap(aa,bb);
        aa--;

        a = numToString(aa);
        b = numToString(bb);

        if(a != "-1") cnt1 = palCount(a);
        else cnt1 = 0;
        cnt2 = palCount(b);

        printf("Case %d: %lld\n", t, cnt2-cnt1);
    }

    return 0;
}

