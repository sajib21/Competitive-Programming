#include<bits/stdc++.h>
#define ll long long int
#define LIM 100005
#define segVar int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;

int n,m,k, a[LIM][7];

vector<int>shots,tmp;
int f(int x) {
    ll ans = 10000000000000000LL;

    deque<int>dq[7];
    for(int i=1; i<x; i++) {
        for(int j=1; j<=m; j++) {
            while(!dq[j].empty() && a[dq[j].back()][j] < a[i][j]) dq[j].pop_back();
            dq[j].push_back(i);
        }
    }
//    cout << "BUG" << endl;

    for(int i=x; i<=n; i++) {
        ll temp = 0; tmp.clear();
        for(int j=1; j<=m; j++) {
            while(!dq[j].empty() && i-dq[j].front()+1 > x) dq[j].pop_front();
            while(!dq[j].empty() && a[dq[j].back()][j] < a[i][j]) dq[j].pop_back();
            dq[j].push_back(i);

            ll tt = a[dq[j].front()][j];
            temp += tt;
            tmp.push_back(tt);
//            cout << i << " : " << tt << endl;

        }
        if(temp < ans) {
            ans = temp;
            shots = tmp;
        }
    }
//    cout << "CLEAN " << ans << endl;
//    for(int i=x; i<=n; i++) {
//        ll temp = 0; tmp.clear();
//        for(int j=1; j<=m; j++) {
//            int tt = query(j, 1, 1,n, i-x+1, i);
//            temp += tt;
//            tmp.push_back(tt);
//        }
//        if(temp < ans) {
//            ans = temp;
//            shots = tmp;
//        }
//    }
    return ans;
}

int main() {
    scanf("%d %d %d", &n,&m,&k);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) scanf("%d", &a[i][j]);

    int lo = 0, hi = n, md;
    vector<int>sol;

    while(lo < hi) {
        md = (lo+hi+1)/2;
//        cout << "TEST " << md << endl;
        if(f(md) > k) hi = md-1;
        else {
            lo = md;
            sol = shots;
        }
    }

//    printf("%d\n", hi);
    while(sol.size() < m) sol.push_back(0);
    for(int i=0; i<sol.size(); i++) printf("%d ", sol[i]);
}
