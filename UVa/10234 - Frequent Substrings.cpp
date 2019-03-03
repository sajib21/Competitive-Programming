/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1 << 10;
const int MAXL = 10;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], mrank[MAXL][MAXN];
char str[MAXN];

inline bool mequal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(mrank[stp-1][u] != mrank[stp-1][v]) return false;
    int a = u + mv < n ? mrank[stp-1][u+mv] : -1;
    int b = v + mv < n ? mrank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !mequal(suffix[i], suffix[i-1])) {
            mrank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else mrank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = mrank[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = mrank[stp-1][idx];
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
    for(i = 0; i <= stp; i++) mrank[i][n] = -1;
}

inline int lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(mrank[i][u] == mrank[i][v]) {
            ret += 1<<i;
            u += 1<<i;
            v += 1<<i;
        }
    }
    return ret;
}

int main() {
//    freopen("11512i.txt", "r", stdin);
//    freopen("11512o.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    while(gets(str) != NULL) {
        n = strlen(str);
        for(int i=0; i<n; i++) if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
        SortSuffix();
//        for(int i=0; i<n; i++) cout << suffix[i] << ' '; cout << endl;

        int p,q;
        scanf("%d", &p);

        int lcpa[MAXN+10];
        for(int i=1; i<n; i++) lcpa[i] = lcp(suffix[i], suffix[i-1]);

        while(p--) {
            scanf("%d", &q);
            int a = 0, b=n,c=0;
            int ax=0,ay=n,az=0;

            bool f = false;
            for(int i=1; i<n; i++) {
//                cout << "CUR " << suffix[i] << ' ' << suffix[i-1] << ' ' << lcp(suffix[i], suffix[i-1]) << ' ' << endl; getchar();
//                cout << "PRE " << a << ' ' << b << ' ' << c << endl;
                int x = lcpa[i];
                if(x < q) {
                    if(c > az) {
                        ax = a, ay = b, az = c;
//                        cout << "SAVING " << ax << ' ' << ay << ' ' << az << " SO " << endl;
                    }
                    a = c = 0; b = n;
                    f = false;
                }
                else if(!f) {
//                    cout << suffix[i] << ' ' << suffix[i-1] << ' ' << x << endl;
                    a = x;
                    b = suffix[i];
                    c = 2;
                    f = true;
                }
                else if(f) {
//                    cout << suffix[i] << ' ' << suffix[i-1] << ' ' << x << endl;
                    c++;
                }
            }
            if(!az) {
                for(int i=0; i<n; i++) if(n-suffix[i] >= q) {
                    printf("1 ");
                    for(int in=suffix[i]; in<suffix[i]+q; in++) printf("%c", str[in]);
                    printf("\n");
                    break;
                }
            }
            else {
                printf("%d ", az);
                for(int i=ay; i<ay+q; i++) printf("%c", str[i]);
                printf("\n");
            }

        }

    }
    return 0;
}
