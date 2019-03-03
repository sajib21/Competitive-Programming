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
int sum[MAXN], cnt[MAXN], myrank[MAXL][MAXN];
char str[MAXN], a[MAXN];

inline bool myequal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(myrank[stp-1][u] != myrank[stp-1][v]) return false;
    int a = u + mv < n ? myrank[stp-1][u+mv] : -1;
    int b = v + mv < n ? myrank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !myequal(suffix[i], suffix[i-1])) {
            myrank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else myrank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = myrank[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = myrank[stp-1][idx];
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
    for(i = 0; i <= stp; i++) myrank[i][n] = -1;
}

inline int lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(myrank[i][u] == myrank[i][v]) {
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
    int m = 0;int x[12];

    strcpy(str, "#");
    x[m++] = strlen(str)-1;

    scanf("%s", a); strcat(str, a);


    while(scanf("%s", &a) != EOF) {
        strcat(str, "#");
        x[m++] = strlen(str)-1;

        strcat(str, a);

    }

//    strcat(str, "#");

    n = strlen(str);
//    x[m++] = n-1;

//    cout << str << ' ' << n << endl;
//    for(int i=0; i<m; i++) cout << x[i] << ' ' ; cout << endl;

    SortSuffix();

//    int ans = 0;

    int p,q; p = q = m;
    int f[12] = {0};
    int flag = 0;

    int ans = 0;

    while(p < n && q < n) {

        if(flag < m) {
            for(int k=m-1; k>=0; k--) if(suffix[p] > x[k]) {
                if(!f[k]) flag++;
                f[k]++;
//                cout << "IN " << suffix[p] << ' ' << str[suffix[p]] << " : " << p << " COMES FROM " << k << endl; getchar();
                break;
            }
            p++;
        }
        else {
//            int tempans = INT_MAX;
//            for(int i=q+1; i<p; i++) tempans = min(tempans, lcp(suffix[i-1], suffix[i]));
            ans = max(ans, lcp(suffix[q], suffix[p-1] ) );

//            cout << "CHECK " << q << ' ' << p << ' ' << lcp(suffix[q], suffix[p-1] ) << endl; getchar();

            for(int k=m-1; k>=0; k--) if(suffix[q] > x[k]) {
                f[k]--;
                if(!f[k]) flag--;
//                cout << "OUT " << suffix[q] << ' ' << str[suffix[q]] << " : " << q << " COMES FROM " << k << endl; getchar();
                break;
            }
            q++;
        }
//        cout << "STEP " << q << ' ' << p << ' ' << flag << ' ' << ans << endl; getchar();
    }

    printf("%d\n", ans );

    return 0;
}


