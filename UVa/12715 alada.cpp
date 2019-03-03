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
vpi pts, qry;
//int lft[LIM], rgt[LIM],
int ans[LIM];


int main() {
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(ans, 0, sizeof ans);
        pts.clear(); qry.clear();

        scanf("%d %d", &n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &x, &y);
            u[i] = x; v[i] = y;
            pts.pb(pii(x, i));
            pts.pb(pii((x+y)/2, n+i));
            pts.pb(pii(y, n+n+i));
        }
        for(int i=0; i<m; i++) {
            scanf("%d", &x);
            k[i] = x;
            qry.pb(pii(x, i));
        }

        sort(pts.begin(), pts.end(), cmpx);
        sort(qry.begin(), qry.end(), cmpx);

//        cout << endl;
//        cout << "PTS " << endl;
//        for(int i=0; i<pts.size(); i++) cout << pts[i].ff << ' ' << pts[i].ss << endl;
//        cout << endl;
//        cout << "QRY " << endl;
//        for(int i=0; i<qry.size(); i++) cout << qry[i].ff << ' ' << qry[i].ss << endl;
//        cout << endl;

        multiset<int>open, close;

        for(int i=0,j=0; i<pts.size() && j<qry.size(); ) {
//            cout << "TEST " << i << ' ' << j << ' ' << pts[i].ff << ' ' << qry[j]
            if(pts[i].ff < qry[j].ff) {
                pii cur = pts[i];
                if(cur.ss < n) { ///open
                    int id = cur.ss;
                    open.insert(u[id]);
//                    cout << "OP s " << i << ' ' << id << ' ' << u[id] << endl;
                }
                else if(cur.ss < n+n) { ///mid
                    int id = cur.ss-n;
                    open.erase(u[id]);
                    close.insert(-v[id]);
//                    cout << "OP e " << i << ' ' << id << ' ' << u[id] << endl;
//                    cout << "CL s " << v[id] << endl;
                }
                else { ///close
                    int id = cur.ss-n-n;
                    close.erase(-v[id]);
//                    cout << "CL e " << i << ' ' << id << ' ' << v[id] << endl;
                }
                i++;
            }
            else {
                pii cur = qry[j];
                int id = cur.ss;
                if(open.size())  ans[id] = max(ans[id], cur.ff- (*open.begin()) );
                if(close.size()) ans[id] = max(ans[id], -(*close.begin())-cur.ff);
                j++;
//                cout << "Q " << i << ' ' << id << ' ' << ans[id] << endl;
            }
//            getchar();
        }

        printf("Case %d:\n", t);
        for(int i=0; i<m; i++) printf("%d\n", ans[i]);

    }
}
