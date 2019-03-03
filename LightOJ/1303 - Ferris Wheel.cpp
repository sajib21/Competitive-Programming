#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int main() {

//    freopen("1303i.txt", "r", stdin);
//    freopen("1303o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
            int n,m;
        scanf("%d %d", &n,&m);
//        if(n <= m) printf("Case %d: %d\n", t, 5*(sqr(m)+m+n-1));
//        else printf("Case %d: %d\n", t, 5*(m*n + m));
        int pos[22] = {0};
        bool flag[22][22] = {0};
        queue<int> q1,q2;
        for(int i=1; i<=n; i++) q1.push(i);
        int cnt = 0;

        int i=0;
        int x = 0;
        bool f = false;
        while(true) {
            if(pos[i]) {
                q1.push(pos[i]);
                x = i+1;
            }
            pos[i] = 0;
            int p = q1.front();
            while(!q1.empty() && flag[i][ q1.front() ]) {
                p = q1.front();
                q2.push(p);
                q1.pop();
            }
            if(!q1.empty()) {
                pos[i] = q1.front();
                flag[i][ pos[i] ] = 1;
                q1.pop();
                f |= true;
            }

            while(!q1.empty()) {
                q2.push( q1.front() );
                q1.pop();
            }
            while(!q2.empty()) {
                q1.push( q2.front() );
                q2.pop();
            }

//            cout << i << ' ' << f << ' ' << cnt << ' ' ; for(int j=0; j<m; j++) cout << pos[j] << ' ' ; cout << endl;

//            cnt += 5;
            i = (i+1) % m;


            if(!i) {
                if(!f) {
                    cnt += 5*x;
//                    cout << "COUNTED " << cnt << endl;
                    break;
                }
                cnt += 5*m;
                f = false;
                x = 0;
//                cout << "COUNTED " << cnt << endl;
            }
//            i = (i+1) % m;
        }
        printf("Case %d: %d\n", t, cnt);
    }

    return 0;
}
