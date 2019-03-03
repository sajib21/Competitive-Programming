/*
Suffix array implementation using bucket sorting + lcp.
Complexity O(n log n), str[] is the target string,
n is its length and suffix[i] contains i'th sorted suffix position.
*/

#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

string text, pattern;
int sizeText, sizePattern;
int prefix[50005];
vector<int>results, suf;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

vi matchingCheck() {
    vi results;
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
    return results;
}


const int MAXN = 1 << 18;
const int MAXL = 18;

int n, stp, mv, suffix[MAXN], tmp[MAXN];
int sum[MAXN], cnt[MAXN], ranky[MAXL][MAXN];
char str[MAXN], str2[MAXN], str3[MAXN];
bool mark[MAXN];

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


int main() {
//    int T;
//    scanf("%d", &T);
//    for(int t=1; t<=T; t++) {
        results.clear();
        scanf("%s", str);
        scanf("%s", str2);
        scanf("%s", str3);

        text = str;
        text = "#" + text;
        sizeText = text.size();

        pattern = str2;
        pattern = "#" + pattern;
        sizePattern = pattern.size();
        generatePrefix();
        results = matchingCheck();

        pattern = str3;
        pattern = "#" + pattern;
        sizePattern = pattern.size();
        generatePrefix();
        suf = matchingCheck();

        if(results.empty() || suf.empty()) {
            printf("0\n");
            return 0;
        }


        for(int i=0; i<results.size(); i++) results[i]--;
        for(int i=0; i<suf.size(); i++) suf[i]--;

        for(int i=0; i<results.size(); i++) mark[ results[i] ]++;
//        for(int i=0; i<suf.size(); i++) cout << suf[i] << ' ' ; cout << endl;

//        strcat()
        n = strlen(str);
        int p,q;

        SortSuffix();
//        printSuffix();

        int ans = 0;
        for(int i=0; i<n; i++) {
//                cout << i << ' ' << suffix[i] << ' ' << ( suf[ suf.size()-1 ] ) << endl;
            if(!mark[ suffix[i] ] || suffix[i] > suf.back()) continue;
            int x = 0;
//            cout << "BUG" << endl;
            if(i) x = lcp(suffix[i], suffix[i-1]);

//        cout << "BUG" << endl;
            int y;
            if(!x) y = lower_bound(suf.begin(), suf.end(), suffix[i]) - suf.begin();
            else y = lower_bound(suf.begin(), suf.end(), suffix[i]+x-strlen(str3)+1) - suf.begin();
            ans += suf.size() - y;

//            cout << i << ' ' << suffix[i] << ' ' << x << ' ' << y << ' ' <<ans << endl;

//            int temp = 0;
//            if(y < suf.size()) temp = max(0, (suf[y]+sizePattern-1-1-1) - suffix[i] + 1 - x);
//            else temp = n-suffix[i] - x;
//             ans += temp;
        }
        printf("%d\n",ans );
//    }
//    main();
}

