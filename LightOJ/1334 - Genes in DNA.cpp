#include    <bits/stdc++.h>
#define     ll      long long int
#define     ull     unsigned ll
#define     vii     vector<int>
#define     vll     vector<ll>
#define     pb      push_back
#define     LIM     50000
#define     MOD     1000000007
#define     MAX     10000000
#define     pi      acos(-1)
#define     segVar  int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define     pii     pair<int,int>
#define     mpr     make_pair
#define     EPS     1e-9
#define     sqr(x)  ((x)*(x))
#define     gamma   0.5772156649
#define     harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

///STARS AND BARS : (n+k-1)C(k-1)

using namespace std;

string text, pattern, revText, revPattern;
int sizeText, sizePattern, sizeRevText, sizeRevPattern;
int prefix[LIM+100], suffix[LIM+100], prefixCount[LIM+100], suffixCount[LIM+100];
vii results;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

int dpPrefix[LIM+10];
int get(int n) {
    if(!n) return 0;
    if(dpPrefix[n] != -1) return dpPrefix[n];
    return dpPrefix[n] = 1 + get(prefix[n]);
}
void matchingCheck() {
    int i=1, j=1, k=1;
    while(i < sizeText) {
        while(j < sizePattern && text[i] == pattern[j]) {
            prefixCount[i] = get(j) ;
//            if(j != sizePattern-1)
//                prefixCount[i]++;
            i++ , j++;
        }
        if(j == sizePattern) prefixCount[i-1]--;
//        if(j == sizePattern) results.push_back(k);
        if(prefix[j-1] > 0) k = i - prefix[j-1];
        else {
            if(i == k) i++;
            k = i;
        }
        if(j > 1) j = prefix[j-1] + 1;
    }
}

void generateSuffix() {
    suffix[0] = 0;
    for(int i = 0, j = 2; j<sizeRevPattern; j++) {
        while(i > 0 && revPattern[i+1] != revPattern[j]) i = suffix[i];
        if(revPattern[i+1] == revPattern[j]) i = i+1;
        suffix[j] = i;
    }
}
int dpSuffix[LIM+10];
int get2(int n) {
    if(!n) return 0;
    if(dpSuffix[n] != -1) return dpSuffix[n];
    return dpSuffix[n] = 1 + get2(suffix[n]);
}
void matchingCheck2() {
    int i=1, j=1, k=1;
    while(i < sizeRevText) {
        while(j < sizeRevPattern && revText[i] == revPattern[j]) {
            suffixCount[i] = get2(j);
//            if(j != sizeRevPattern-1)
//                suffixCount[i]++;
            i++ , j++;
        }
        if(j == sizePattern) suffixCount[i-1]--;
//        if(j == sizePattern) results.push_back(k);
        if(suffix[j-1] > 0) k = i - suffix[j-1];
        else {
            if(i == k) i++;
            k = i;
        }
        if(j > 1) j = suffix[j-1] + 1;
    }
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(prefix, 0 ,sizeof prefix);
        memset(suffix, 0 ,sizeof suffix);
        memset(prefixCount, 0, sizeof prefixCount);
        memset(suffixCount, 0, sizeof suffixCount);
        memset(dpPrefix, -1, sizeof dpPrefix);
        memset(dpSuffix, -1, sizeof dpSuffix);
        cin >> text >> pattern;
        revText = text;
        revPattern = pattern;
        reverse(revText.begin(), revText.end());
        reverse(revPattern.begin(), revPattern.end());

        text = "0" + text; pattern = "0" + pattern;
        revText = "0" + revText; revPattern = "0" + revPattern;

        sizeText = text.size(); sizePattern = pattern.size();
        sizeRevText = revText.size(); sizeRevPattern = revPattern.size();

        generatePrefix();
        matchingCheck();
        generateSuffix();
        matchingCheck2();

        reverse(suffixCount+1, suffixCount+sizeText );

        ll ans = 0;
        for(int i=2; i<sizeText; i++) ans += prefixCount[i-1]*suffixCount[i];
        printf("Case %d: %lld\n", t, ans);

    }

    return 0;
}

