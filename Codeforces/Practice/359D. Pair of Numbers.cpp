#include<bits/stdc++.h>
#define LIM 300005
#define LOG 20

using namespace std;

int n,a[LIM], mini[LIM][22], gici[LIM][22], ex[22];

int getGici(int i, int sz) {
    int j = i + sz;
    int lim = LOG;
    int ans = 0;
    while(lim >= 0) {
        if(i + (1 << lim) <= j ) {
            ans = __gcd(ans, gici[i][lim]);
            i = i + (1 << lim);
        }
        lim--;
    }
    return ans;
}
int getMini(int i, int sz) {
    int j = i + sz;
    int lim = LOG;
    int ans = INT_MAX;
    while(lim >= 0) {
        if(i + (1 << lim) <= j ) {
            ans = min(ans, mini[i][lim]);
            i = i + (1 << lim);
        }
        lim--;
    }
    return ans;
}

bool ok(int x) {
//    cout << "TEST " << x << endl;
    for(int i=1; i<=n-x+1; i++) {
//        cout << "FOR " << i << " : " << getGici(i,x) << ' ' << getMini(i, x) << endl; getchar();
        if(getGici(i, x) == getMini(i,x)) return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    ex[0] = 1;
    for(int i=1; i<=LOG; i++) ex[i] = ex[i-1]*2;

    memset(gici, 0, sizeof gici);
    memset(mini, 127, sizeof mini);

    for(int i=1; i<=n; i++) mini[i][0] = a[i], gici[i][0] = a[i];

    for(int i=1; i<=LOG; i++) {
        int pre = ex[i-1];
        for(int j=1; j<=n; j++) {
            mini[j][i] = min(mini[j][i-1] , j+pre<=n? mini[j+pre][i-1] : INT_MAX);
            gici[j][i] = __gcd(gici[j][i-1] , j+pre<=n? gici[j+pre][i-1] : 0);
        }
    }

//    cout << "MINI SPARSE " << endl;
//    for(int i=0; i<=3; i++) {
//        for(int j=1; j<=n; j++) cout << mini[j][i] << ' ' ;
//        cout << endl;
//    }

    int lo=0, hi=n, md;

    while(lo < hi) {
        md = (lo+hi+1) / 2;
//        cout << lo << ' ' << hi << ' ' << md << endl; getchar();
        if(ok(md)) lo = md;
        else hi = md-1;
    }

    vector<int>sol;
    for(int i=1; i<=n-hi+1; i++) if(getGici(i, hi) == getMini(i,hi)) sol.push_back(i);

    cout << sol.size() << ' ' << hi-1 << endl;
    for(int i=0; i<sol.size(); i++) {
        if(i) printf(" ");
        printf("%d", sol[i]);
    }
    cout << endl;

    return 0;

}
