#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)
#define ff first
#define ss second

using namespace std;

int f(int a, int n) {
    return a*( (1<<n) - 1);
}

int n, x;
map<int,int>koyta;
vi ashol;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        koyta[x]++;
    }
    for(auto it : koyta) ashol.pb(it.ss);

    sort(ashol.begin(), ashol.end());
//    reverse(ashol.begin(), ashol.end());

    int ans = 0;

    for(int st=1; st<=200000; st++) {
        int cur = st;
        int in=0;
        int curans=0;
        while(true) {
            int x = lower_bound(ashol.begin()+in, ashol.end(), cur) - ashol.begin();
            if(x < ashol.size()) {
                curans += cur;
                ans = max(ans, curans);
                cur *= 2;
                in = x+1;
            }
            else break;
        }
    }

    cout << ans << endl;

    return 0;


//    for(int i=0; i<ashol.size(); i++) {
//
//    }


//    for(auto p : ashol) cout << p << ' '; cout << endl;

//    int cnt=0, ans=0, last=2*ashol[0];
//    int temp=0;
//    for(int i=0; i<ashol.size(); i++) {
//        if(last%2 || ashol[i] < last/2) {
//            ans = max(ans, f(last, cnt) );
//
//            cnt++;
//            last = min(last/2, ashol[i]);
//        }
//        else {
//            cnt++;
//            last /= 2;
//            ans = max(ans, f(last, cnt) );
//        }
//    }
//
//    cout << ans << endl;
}
