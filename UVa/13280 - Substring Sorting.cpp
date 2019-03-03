#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#define  segVar     int lft = 2*node, rgt = 2*node+1, md = (st+ed)/2

using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MAXN = 1 << 18;
const int MAXL = 18;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], ranky[MAXL][MAXN];
char str[MAXN], str2[MAXN];

inline bool equal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(ranky[stp-1][u] != ranky[stp-1][v]) return false;
    int a = u + mv < n ? ranky[stp-1][u+mv] : -1;
    int b = v + mv < n ? ranky[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !equal(suffix[i], suffix[i-1])) {
            ranky[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else ranky[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = ranky[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = ranky[stp-1][idx];
        int x = sum[idx];
        tmp[x + cnt[idx]] = suffix[i] - mv;
        cnt[idx]++;
    }
    update();
    return;
}

inline bool cmp(const int &a, const int &b){
    if(str[a]!=str[b]) return str[a]<str[b];
    return false;
}

void SortSuffix() {
    int i;
    for(i = 0; i < n; i++) tmp[i] = i;
    sort(tmp, tmp + n, cmp);
    stp = 0;
    update();
    ++stp;
    for(mv = 1; mv < n; mv <<= 1) {
        Sort();
        stp++;
    }
    stp--;
    for(i = 0; i <= stp; i++) ranky[i][n] = -1;
}

inline int lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(ranky[i][u] == ranky[i][v]) {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}

void printSuffix() {
    printf("INIT %s\n", str);
    for(int i=0; i<n; i++) {
        printf("%3d %3d : ", i, suffix[i]);
        for(int j=suffix[i]; j<n; j++) cout << str[j] ;
        cout << endl;
    }
}

struct info{
    int x,y,z, a; /// x = id, y = sz, z = ith, a = ans;
    info() {}
    info(int xx, int yy, int zz, int aa) {
        x = xx; y = yy; z = zz; a = aa;
    }
};
bool cmpx(info a, info b) { /// id comp
    return a.x < b.x;
}
bool cmpy(info a, info b) { ///len comp
    return a.y < b.y;
}

int m, close[MAXN];
info q[MAXN];
set<int>open[MAXN];

int segTree[4*MAXN];

int init(int node, int st, int ed) {
    if(st == ed) return segTree[node] = suffix[st];
    segVar;
    return segTree[node] = min( init(lft, st,md) , init(rgt, md+1,ed) );
}
int query(int node, int st, int ed, int l, int r) {
    if(ed < l || st > r) return INT_MAX;
    if(st >= l && ed <= r) return segTree[node];
    segVar;
    return min( query(lft, st,md, l,r), query(rgt, md+1,ed, l,r) );
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s", &str);
        n = strlen(str);
        SortSuffix();
//        printSuffix();

        for(int i=0; i<n; i++) open[i].clear();

        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d %d", &q[i].y, &q[i].z); q[i].z--;
            q[i].x = i;
        }
        sort(q, q+m, cmpy);


        open[1].insert(0);
        close[n-suffix[0]] = 0;

        for(int i=1; i<n; i++) {
            int x = lcp(suffix[i], suffix[i-1]);
            open[x+1].insert(i);
            close[n-suffix[i]] = i;
        }

//        cout << "OPEN " << endl;
//        for(int i=1; i<=n; i++) {
//            cout << i << " : ";
//            for(auto it : open[i]) cout << it << ' '; cout << endl;
//        }
//        cout << "CLOSE " << endl;
//        for(int i=1; i<=n; i++) cout << close[i] << ' '; cout << endl;

        ordered_set cur;
        int i = 0; ///qry cur
        for(int sz=1; sz<=n && i<m; sz++) {
            for(auto it : open[sz]) cur.insert(it);
//            cout << "SZ " << sz << " : ";
//            for(auto it : cur) cout << it << ' ' ; cout << endl;
//            cout << "CLOSE " << close[sz] << endl;
//            getchar();
            while(i<m && q[i].y == sz) {
                if(q[i].z >= cur.size()) q[i].a = -1;
                else q[i].a = *cur.find_by_order(q[i].z);
//                cout << i << " QUERY " << q[i].x << ' ' << q[i].y << ' ' << q[i].z << ' ' << q[i].a << endl;
//                if(q[i].a != -1) cout << "SUF " << suffix[ q[i].a ] << endl;
//                getchar();
                i++;
            }
            cur.erase(close[sz]);
        }

        sort(q, q+m, cmpx);

        init(1, 0,n-1);

        for(int i=0; i<m; i++) {
            if(q[i].a == -1) printf("Not found\n");
            else {
                int lo = q[i].a, hi = n, md;
                while(lo < hi) {
                    md = (lo+hi)/2;
//                    cout << "IN " << lo << ' ' << hi << ' ' << md << ' ' << lcp()
                    if(lcp(suffix[q[i].a], suffix[md]) < q[i].y) hi = md;
                    else lo = md+1;
                }
                hi--;
                printf("%d\n", query(1, 0,n-1, q[i].a, hi) );
//                cout << q[i].a << ' ' << hi << ' ' << suffix[ q[i].a ] << endl;
//                cout << query(1, 0,n-1, q[i].a, hi) << endl;
//                getchar();
//                printf("%d\n", q[i].a);
            }
        }



    }
}
