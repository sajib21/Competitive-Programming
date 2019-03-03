/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>

using namespace std;

string text, pattern;
int sizeText, sizePattern;
int prefix[50005];
vector<int>results;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

void matchingCheck() {
    int i=1, j=1, k=1;
    while(i < sizeText) {
        while(j < sizePattern && text[i] == pattern[j]) i++ , j++;
        if(j == sizePattern) results.push_back(k);
        if(prefix[j-1] > 0) k = i - prefix[j-1];
        else {
            if(i == k) i++;
            k = i;
        }
        if(j > 1) j = prefix[j-1] + 1;
    }
}


const int MAXN = 1 << 18;
const int MAXL = 18;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], rank[MAXL][MAXN];
char str[MAXN], str2[MAXN];

inline bool equal(const int &u, const int &v){
    if(!stp) return str[u] == str[v];
    if(rank[stp-1][u] != rank[stp-1][v]) return false;
    int a = u + mv < n ? rank[stp-1][u+mv] : -1;
    int b = v + mv < n ? rank[stp-1][v+mv] : -1;
    return a == b;
}

void update(){
    int i, rnk;
    for(i = 0; i < n; i++) sum[i] = 0;
    for(i = rnk = 0; i < n; i++) {
        suffix[i] = tmp[i];
        if(i && !equal(suffix[i], suffix[i-1])) {
            rank[stp][suffix[i]] = ++rnk;
            sum[rnk+1] = sum[rnk];
        }
        else rank[stp][suffix[i]] = rnk;
        sum[rnk+1]++;
    }
}

void Sort() {
    int i;
    for(i = 0; i < n; i++) cnt[i] = 0;
    memset(tmp, -1, sizeof tmp);
    for(i = 0; i < mv; i++){
        int idx = rank[stp - 1][n - i - 1];
        int x = sum[idx];
        tmp[x + cnt[idx]] = n - i - 1;
        cnt[idx]++;
    }
    for(i = 0; i < n; i++){
        int idx = suffix[i] - mv;
        if(idx < 0)continue;
        idx = rank[stp-1][idx];
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
    for(i = 0; i <= stp; i++) rank[i][n] = -1;
}

inline int lcp(int u, int v) {
    if(u == v) return n - u;
    int ret, i;
    for(ret = 0, i = stp; i >= 0; i--) {
        if(rank[i][u] == rank[i][v]) {
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
        results.clear();
//        for(int i=0; i<10; i++) cout << i ; cout << endl;
        scanf("%s", str);
        scanf("%s", str2);

        text = str; pattern = str2;
        text = "#" + text; pattern = "#" + pattern;
        sizeText = text.size(); sizePattern = pattern.size();

        generatePrefix(); matchingCheck();

//        cout << "KMP" << endl;
        for(int i=0; i<results.size(); i++) results[i]--;
//        for(int i=0; i<results.size(); i++) cout << results[i] << ' ' ; cout << endl;


        n = strlen(str);
        int p,q;

        SortSuffix();

//        for(int i=0; i<n; i++) cout << suffix[i] << ' '; cout << endl;
        int ans = 0;
        for(int i=0; i<n; i++) {
            int x = 0;
            if(i) x = lcp(suffix[i], suffix[i-1]);


            int y = lower_bound(results.begin(), results.end(), suffix[i]) - results.begin();

//            cout << suffix[i] << ' ' << suffix[i-1] << ' ' << x << ' ' << y << ' ' << results[y] << endl;

            int temp = 0;
            if(y < results.size()) temp = max(0, (results[y]+sizePattern-1-1-1) - suffix[i] + 1 - x);
            else temp = n-suffix[i] - x;
             ans += temp;
//            cout << temp << endl;
//            if(x < q) ans += max(0, ( min(q, n-suffix[i])-p+1 - max(0, x-p+1) ) );
        }
        printf("Case %d: %d\n", t, ans );
    }
}

