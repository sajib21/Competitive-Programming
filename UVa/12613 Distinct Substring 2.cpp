/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>
#define ll unsigned long long int


using namespace std;

const int MAXN = 1 << 19;
const int MAXL = 19;

int n,k, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], ranky[MAXL][MAXN];
char temp[MAXN], str[MAXN];

inline bool equaly(const int &u, const int &v){
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
        if(i && !equaly(suffix[i], suffix[i-1])) {
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
//        cout << i << ' ' << suffix[i] << " : ";
        printf("%3d %3d : ", i, suffix[i]);
        for(int j=suffix[i]; j<n; j++) cout << str[j] ;
        cout << endl;
    }
}

int main() {
//    freopen("12613i.txt", "r", stdin);
//    freopen("12613o.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s", temp);
        int pr = strlen(temp);
        scanf("%d", &k);

//        if(k <= 2) {
            strcpy(str, temp); k--;
            while(k--) strcat(str, temp);

            n = strlen(str);

            SortSuffix();
//            printSuffix();

            ll ans = 0;
            for(int i=0; i<n; i++) {
                if(i) ans += n-suffix[i] - lcp(suffix[i], suffix[i-1]);
                else ans += n-suffix[i];
    //            cout << ans << endl;
            }
        if(k < 3) {
            printf("Case %d: %llu\n", t, ans );
            continue;
        }

        int p,q;
        strcpy(str, "#");
        strcat(str, temp); p = strlen(str);
        strcat(str, temp); q = strlen(str);
        strcat(str, temp);
        n = strlen(str);

        SortSuffix();
//        printSuffix();

        ll temp = 0;
        for(int i=1; i<n; i++) {
            temp += n-suffix[i] - lcp(suffix[i], suffix[i-1]);
        }
        printf("Case %d: %llu\n", t, ans+(ans-temp)*(k-2) );
    }
    return 0;
}

