#include <bits/stdc++.h>

using namespace std;

int rnk[100005];
int par[100005];

int represantive(int a) {
    if(a == par[a]) return a;
    else return par[a] = represantive(par[a]);
}

int unite(int a, int b) {
    int pa = represantive(a), pb = represantive(b);
    if(rnk[pa] < rnk[pb]) {
        par[pa] = pb;
        rnk[pb] += rnk[pa];
        //cout << rnk[pb] <<"prothomta" << endl;
        //represantive(a);
        return rnk[pb];

    }
    else {
        par[pb] = par[pa];
        rnk[pa] += rnk[pb];
        //cout << rnk[pa] <<"ditiyota" << endl;
        //represantive(b);
        return rnk[pa];
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        map<string,int> mp;
        int ed;
        string s1,s2;
        cin >> ed;

        for(int i = 0; i<100005; i++) {
            par[i] = i;
            rnk[i] = 1;
        }

        for(int i=0, x=0; i<ed; i++) {
            cin >> s1 >> s2;
            if(mp.find(s1) == mp.end()) {
                mp[s1] = x;
                par[x] = x;
                rnk[x] = 1;
                x++;
            }
            if(mp.find(s2) == mp.end()) {
                mp[s2] = x;
                par[x] = x;
                rnk[x] = 1;
                x++;
            }

            int u = mp[s1], v = mp[s2];

            if(represantive(u) != represantive(v)) {
                unite(u,v);
                cout << rnk[represantive(mp[s1])] << endl;
            }
        }
    }

    return 0;
}
