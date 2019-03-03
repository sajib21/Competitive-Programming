/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 16;
const int MAXL = 16;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], myRank[MAXL][MAXN];
char str[MAXN];

inline bool myEqual(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(myRank[stp-1][u] != myRank[stp-1][v]) return false;
    int a = u + mv < n ? myRank[stp-1][u+mv] : -1;
    int b = v + mv < n ? myRank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !myEqual(suffix[i], suffix[i-1])) {
            myRank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else myRank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = myRank[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = myRank[stp-1][idx];
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
    for(i = 0; i <= stp; i++) myRank[i][n] = -1;
}

inline int lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(myRank[i][u] == myRank[i][v]) {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        char xxx[MAXN];
        scanf("%s", str);
        int m = strlen(str);
        strcpy(xxx, str);
        strcat(str, xxx);
        n = strlen(str);
        int p,q;

        SortSuffix();
        int ans = -1;
        for(int i=0; i<n; i++) {
            if(suffix[i] < m) {
                if(ans == -1) ans = i;
                else {
//                    cout << suffix[ans] << ' ' << suffix[i] << ' ' << lcp(suffix[ans], suffix[i]) << endl;
                    if(lcp(suffix[ans], suffix[i]) == n-suffix[ans]) ans = i;
                }
            }
        }
        printf("%d\n", suffix[ans]+1);
    }
    return 0;
}
