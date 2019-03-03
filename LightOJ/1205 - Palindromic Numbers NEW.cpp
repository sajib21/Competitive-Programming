#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;

ll pal[20], palCnt[20], palCumCnt[20];
string a,b;

ll sz1, sz2, cnt1, cnt2;

string numToString(ll num) {
    string n;
    if(num < 0) return "-1";
    while(num > 0LL) {
        n += (num%10) + '0';
        num /= 10;
    }
    reverse(n.begin(), n.end());
    return n;
}

int palCount(string num) {

    int sz = num.size();
    int i = 0 , j = sz - 1;
    int cnt = 0;
//    cnt += palCumCnt[sz-1];

    for(int i=1; i<sz; i++) cnt += pal[i];

    while(i <= j) {
        if(num[i] > '1') {
            if(i == j) cnt += (num[i]-'0' - 1) ;
            else cnt += (num[i]-'0' - 1)*(palCnt[sz-2*(i+1)]) ;
        }
        i++; j--;
    }

    return cnt + 2;

}

int main() {

    palCnt[0] = 1; palCnt[1] = palCnt[2] = 10;
    pal[0] = 0; pal[1] = 9; pal[2] = 9;
    palCumCnt[0] = 0; palCumCnt[1] = 9, palCumCnt[2] = 18;

    for(int i=3; i<18; i++) palCnt[i] = 10*palCnt[i-2];
    for(int i=3; i<18; i++) pal[i] = 9*palCnt[i-2];
    for(int i=3; i<18; i++) palCumCnt[i] = palCumCnt[i-1] + palCnt[i] - palCnt[i-2];
//    for(int i=1; i<18; i++) cout << palCnt[i] << ' ' ; cout << endl;
//    for(int i=1; i<18; i++) cout << palCumCnt[i] << ' ' ; cout << endl;

    for(int i=0; i<10; i++) cout << pal[i] << ' ' ; cout << endl;
    for(int i=0; i<10; i++) cout << palCumCnt[i] << ' ' ; cout << endl;

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

        cout << "NUM " << a << ' ' << b << endl;

        if(a != "-1") cnt1 = palCount(a);
        else cnt1 = 0;
        cnt2 = palCount(b);

        cout << "COUNT " << cnt1 << ' ' << cnt2 << endl;

        printf("Case %d: %lld\n", t, cnt2-cnt1);
    }

    return 0;
}

