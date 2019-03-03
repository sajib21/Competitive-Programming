#include<bits/stdc++.h>
#define MX 150005
#define pb push_back


using namespace std;

int n,q, segl[MX],segr[MX], pnt[MX], tree[4*MX];


vector<int>points;
map<int,int>mp;

void update(int node, int st, int ed, int l, int r) {

//    cout << node << ' ' << st << ' ' << ed << ' ' << l << ' ' << r << ' ' << endl;

    if(ed < l || st > r) return;
    if(st >= l && ed <= r) {
        tree[node]++;
        return;
    }

    int left = 2*node, right = 2*node+1, mid = (st+ed)/2;
    update(left, st,mid, l,r);
    update(right, mid+1,ed, l,r);
}

int query(int node, int st, int ed, int p, int carry = 0) {

//    cout << node << ' ' << st << ' ' << ed << ' ' << p << endl;

    if(ed < p || st > p) return 0;
    if(st >= p && ed <= p) return tree[node] + carry;

    int left = 2*node, right = 2*node+1, mid = (st+ed)/2;
    return query(left, st,mid, p, carry+tree[node]) +
        query(right, mid+1,ed, p, carry+tree[node]);
}

int main() {

    int T,t;
    cin >> T;
    for(t=1; t<=T; t++) {

        points.clear(); mp.clear();
        memset(tree, 0, sizeof(tree));

        scanf("%d %d", &n, &q);
        for(int i=0; i<n; i++) {
            int l,r;
            scanf("%d %d", &l, &r);
            points.pb(l); points.pb(r);
            segl[i] = l; segr[i] = r;
        }
        for(int i=0; i<q; i++) {
            scanf("%d", &pnt[i]);
            points.pb(pnt[i]);
        }

        sort(points.begin(), points.end());
        mp[ points[0] ] = 1;
        int sz = points.size(); int j = 2;
        for(int i=1; i<sz; i++) {
            if(points[i] != points[i-1]) {
//                cout << "found " << j << " at " << points[i] << endl;
                mp[ points[i] ] = j++;

            }
        }
//        cout << "HIGHEST POINT " << j <<  endl;

//        cout << "FIRST PHASE COMPLETE" << endl;

        int lst = points[sz-1];
        for(int i=0; i<n; i++) {
            update(1, 1,mp[lst], mp[ segl[i] ], mp[ segr[i] ] );
//            cout << "update " << i << " segment successful"  << endl;
        }
        printf("Case %d:\n", t);

        for(int i=0; i<q; i++) {
            printf("%d\n", query(1, 1, mp[lst] , mp[ pnt[i] ]));
        }
    }
    return 0;
}
