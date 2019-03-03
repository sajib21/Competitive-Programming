#include<bits/stdc++.h>
#include<string>
#define ll long long int

using namespace std;

template <typename T>
string NumberToString(T pNumber)
{
 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();
}

struct info {

    ll zero, comb;
    info() {}
    info(ll z, ll c) {
        zero = z; comb = c;
    }
};

int sz;
string pre, post;
info dp[20][5];

info get(int indx, int con) {

    if(indx == sz) return info(0, 1);
    if(dp[indx][con].zero != -1) return dp[indx][con];

    ll lim, ans = 0, cmb = 0;
    if(con == 0) {
        ans += get(indx+1, 1).zero;
        cmb += get(indx+1, 1).comb;
        for(int i=1; i<pre[indx]-'0'; i++) {
            ans += get(indx+1, 2).zero;
            cmb += get(indx+1, 2).comb;
        }

        ans += get(indx+1, 3).zero;
        cmb += get(indx+1, 3).comb;


    }
    else if(con == 1) {
        ans += get(indx+1, 1).zero;
        cmb += get(indx+1, 1).comb;
        for(int i=1; i<=9; i++) {
            ans += get(indx+1, 2).zero;
            cmb += get(indx+1, 2).comb;
        }
    }
    else if(con == 2) {
        ans += 1*get(indx+1, 2).comb + get(indx+1, 2).zero;
        cmb += get(indx+1, 2).comb;
        for(int i=1; i<=9; i++) {
            ans += get(indx+1, 2).zero;
            cmb += get(indx+1, 2).comb;
        }
    }
    else {

        if(pre[indx] == '0') {
            ans += get(indx+1, 3).comb + get(indx+1, 3).zero;
            cmb += get(indx+1, 3).comb;
        }
        else {
            ans += 1*get(indx+1, 2).comb + get(indx+1, 2).zero;
            cmb += get(indx+1, 2).comb;
            for(int i=1; i<pre[indx]-'0'; i++) {
                ans += get(indx+1, 2).zero;
                cmb += get(indx+1, 2).comb;
            }
            ans += get(indx+1, 3).zero;
            cmb += get(indx+1, 3).comb;

        }



    }

//    cout << indx << ' ' << con << ' ' << ans << ' ' << cmb << endl;
    return dp[indx][con] = info(ans, cmb);

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        ll m,n;
        ll a,b;
//        cin >> pre >> post;
        scanf("%lld %lld", &m,&n);
        if(m == 0) a = -1;
        else if(m == 1) a = 0;
        else {
            m--;
    //        cout << m << endl;
            pre = NumberToString(m) ;
            sz = pre.size();
            memset(dp, -1, sizeof(dp));
            a = get(0, 0).zero;
        }

//        cout << pre << endl;

        pre = NumberToString(n) ;
        sz = pre.size();
        memset(dp, -1, sizeof(dp));
        b = get(0, 0).zero;

//        cout << pre << endl;
//        cout << a << ' ' << b << endl;
//        cout << b - a << endl;
        printf("Case %d: %lld\n", t, b-a);
    }
    return 0;
}
