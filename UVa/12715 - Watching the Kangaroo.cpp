#include<bits/stdc++.h>
#define LIM     100005
#define vi      vector<int>
#define pii     pair<int,int>
#define ff      first
#define ss      second
#define vpi     vector<pii>
#define pb(x)   push_back(x)

using namespace std;

bool cmpx(pii a, pii b) {
    return (a.ff == b.ff && a.ss < b.ss) || a.ff < b.ff;
}
bool cmpy(pii a, pii b) {
    return a.ss < b.ss;
}

int n,m, x,y, u[LIM],v[LIM], k[LIM];
vpi pts;
//int lft[LIM], rgt[LIM],
int ans[LIM];


int main() {
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(ans, 0, sizeof ans);
        pts.clear();

        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            u[i] = x; v[i] = y;
            pts.pb(pii(x, i));
            pts.pb(pii((x+y)/2, n+m+i));
            pts.pb(pii(y, n+m+n+i));
        }
        for(int i=0; i<m; i++) {
            scanf("%d", &x);
            k[i] = x;
            pts.pb(pii(x, n+i));
        }

        sort(pts.begin(), pts.end(), cmpx);

//        for(int i=0; i<pts.size(); i++) {
//            cout << pts[i].ff << ' ' << pts[i].ss << endl;
//        }


        multiset<int>open, close;

        for(int i=0; i<pts.size(); i++) {
            pii cur = pts[i];
            if(cur.ss < n) { ///open
                int id = cur.ss;
                open.insert(u[id]);
            }
            else if(cur.ss < n+m) { ///query
                int id = cur.ss-n;
//                int lft = *open.begin();
//                int rgt = *close.begin();
//                ans[id] = max( cur.ff-lft , -rgt-cur.ff );
                if(open.size())  ans[id] = max(ans[id], cur.ff- (*open.begin()) );
                if(close.size()) ans[id] = max(ans[id], -(*close.begin())-cur.ff);
//                lft[ cur.ss-n ] = cur.ff - far;
            }
            else if(cur.ss < n+m+n) { ///mid
                int id = cur.ss-n-m;
                open.erase(u[id]);
                close.insert(-v[id]);
            }
            else { ///close
                int id = cur.ss-n-m-m;
                close.erase(-v[id]);
            }
        }

        printf("Case %d:\n", t);
        for(int i=0; i<m; i++) printf("%d\n", ans[i]);

    }
}
