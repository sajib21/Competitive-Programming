/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

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

ll f(int st, int ed, int sz) {
//    cout << "IN " << st << ' ' << ed << ' ' << sz << ' ' << lcp(suffix[st], suffix[ed]) << endl; getchar();
    if(st == ed) return 0;
    int X = lcp(suffix[st], suffix[ed]);
    if(X >= sz) return (X-sz+1) + f(st,ed, X+1);

    int lo = st+1, hi = ed, md;
    while(lo < hi) {
        md = (lo+hi)/2;
//                    cout << "IN " << lo << ' ' << hi << ' ' << md << ' ' << lcp()
        if(lcp(suffix[st], suffix[md]) < sz) hi = md;
        else lo = md+1;
    }
    hi--;
    int x = lcp(suffix[st], suffix[hi]);
//    cout << "HI " << hi << ' ' << x << endl; getchar();
    ll ans = 0;
    if(st < hi && x >= sz) ans += (x-sz+1) + f(st, hi, x+1);
    if(hi+1 < ed) ans += f(hi+1, ed, sz);

//    cout << "OUT " << st << ' ' << ed << ' ' << sz << ' ' << ans << endl; getchar();
    return ans;
}

int main() {
//    freopen("12191i.txt", "r", stdin);
//    freopen("12191o.txt", "w", stdout);

    while(scanf("%s", str)) {
        if(!strcmp(str, "*")) return 0;
        n = strlen(str); if(n == 1) {printf("0\n"); continue;}
        SortSuffix();
//        printSuffix();

        ll ans = 0;
        int last = lcp(suffix[0], suffix[1]);

//        cout << 1 << ' ' << last << ' ' << ans << endl;
        for(int i=2; i<n; i++) {
            int x = lcp(suffix[i], suffix[i-1]);
            if(x >= last) last = x;
            else {
                ans += last-x;
                last = x;
            }
//            cout << i << ' ' << last << ' ' << ans << endl; getchar();
        }
        ans += last;

        printf("%lld\n", ans);
    }
}
