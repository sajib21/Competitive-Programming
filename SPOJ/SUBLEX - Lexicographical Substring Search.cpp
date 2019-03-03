/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 20;
const int MAXL = 20;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], ranky[MAXL][MAXN];
char str[MAXN];
int dis[MAXN];

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

int main() {
    int T;
//    scanf("%d", &T);
    for(int t=1; t<=1; t++) {
        scanf("%s", str);
        n = strlen(str);
        int p,q;
//        scanf("%d %d", &p,&q);
        SortSuffix();

//        for(int i=0; i<n; i++) cout << suffix[i] << ' '; cout << endl;
        int ans = 0;
        dis[0] = n-suffix[0];
        for(int i=1; i<n; i++) dis[i] += dis[i-1] + n-suffix[i] - lcp(suffix[i], suffix[i-1]);

//        for(int i=0; i<n; i++) cout << dis[i] << ' ' ; cout << endl;

        scanf("%d", &q);
        while(q--) {
            scanf("%d", &p);
            int in = lower_bound(dis, dis+n, p) - dis;
             int x = lcp(suffix[in], suffix[in-1]);
             if(!in) x = 0;
             int im = suffix[in] +x-(in? dis[in-1] : 0) + p-1;
//             cout << in << ' ' << suffix[in] << ' ' << x << ' ' << im << endl;
             for(int i=suffix[in]; i<=im; i++) printf("%c", str[i]); printf("\n");
        }

//        printf("%d\n", ans );
    }
    return 0;
}

