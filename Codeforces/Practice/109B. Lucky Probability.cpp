#include<bits/stdc++.h>
#define vi      vector<ll>
#define pb(x)   push_back(x)
#define MAX     1000000000
#define ll      long long int

using namespace std;

vi lucky;

int main() {
    queue<ll>q;
    q.push(0);
//    q.push(4);
//    q.push(7);

    while(!q.empty()) {
        ll cur = q.front();
        q.pop();


//        cout << cur << ' ' << lucky.size() << endl; //getchar();
        lucky.pb(cur);
        if(cur > MAX) continue;

        q.push(cur*10+4);
        q.push(cur*10+7);
    }

//    cout << lucky.size() << endl;

    ll a,b,c,d, k;
    double ans = 0;
    while( scanf("%lld %lld %lld %lld %lld", &a,&b, &c,&d, &k) != EOF ) {

        ans = 0;

//        if(k == 1) {
//            for(int i=0; i<lucky.size(); i++) {
//                ll p = lucky[i];
//                if(p >= a && p <= b && p >= c && p <= d) ans++;
//            }
//            ans /= (b-a+1)*(b-a+1);
//            printf("%.10f\n", min(ans,1.0));
//            continue;
//        }

        for(int i=k, j=1; i+1<lucky.size(); i++,j++) {
    //        cout << lucky[i] << ' ' << lucky[j] << ' ' << ans << endl;
    //        getchar();
            ll p,q,r,s;
            p = max(a, lucky[j-1]+1);
            q = min(b, lucky[j]);
            r = max(c, lucky[i]);
            s = min(d, lucky[i+1]-1);

            if(p > q || r > s) continue;

            ans += 1.0 * (q-p+1)*(s-r+1) / ((b-a+1)*(d-c+1));

            if(q == r) ans -= 1.0 / ((b-a+1)*(d-c+1));

//            cout << p << ' ' << q << ' ' << r << ' ' << s << ' ' << ans << endl;
//            getchar();
        }

//        cout << "HALFWAY " << ans << endl;

        for(int i=k, j=1; i+1<lucky.size(); i++,j++) {
    //        cout << lucky[i] << ' ' << lucky[j] << ' ' << ans << endl;
    //        getchar();
            ll p,q,r,s;
            p = max(c, lucky[j-1]+1);
            q = min(d, lucky[j]);
            r = max(a, lucky[i]);
            s = min(b, lucky[i+1]-1);

            if(p > q || r > s) continue;

            ans += 1.0 * (q-p+1)*(s-r+1) / ((b-a+1)*(d-c+1));

//            cout << p << ' ' << q << ' ' << r << ' ' << s << ' ' << ans << endl;
//            getchar();
        }

        printf("%.10f\n", min(ans,1.0));

    }
}
