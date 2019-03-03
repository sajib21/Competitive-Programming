#include<bits/stdc++.h>
#define OFF 15000
#define ll long long int

using namespace std;

int n;
ll p, a[2010];
map<int,ll>koyta, dui;

//vector<int>

int main() {
//    cout << 2/27.0 << endl;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%lld", &a[i]);
    sort(a, a+n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            koyta[ a[i]-a[j] ]++;
        }
    }

    for(auto p : koyta) {
        for(auto q : koyta) {
            dui[ p.first+q.first ] += p.second*q.second;
        }
    }

//    cout << "Single Dif" << endl;
//    for(auto p : koyta) cout << p.first << ' ' << p.second << endl;
//    cout << "Double Dif" << endl;
//    for(auto q : dui) cout << q.first << ' ' << q.second << endl;

    p = n*(n-1)/2;


    ll cnt = 0;
    ll ans = 0;

    map<int,ll>::iterator i = koyta.begin(), j = dui.begin();


    while(i != koyta.end() && j != dui.end()) {
        if((*i).first <= (*j).first) {
//            ans += cnt;
            ans += cnt*(*i).second;
            i++;
        }
        else {
            cnt += (*j).second;
            j++;
        }
    }

    while(i != koyta.end()) {
        ans += cnt;
        i++;
    }

    ll p3 = 1LL*p*p*p;

    printf("%.10f\n", 1.0*ans/p3 );

//    dp[0][0] = 1;
//
//    for(int make=-15000; make<=15000; make++) {
//        if(koyta)
//    }




//    printf("%.10f\n", f(0, OFF));
}
