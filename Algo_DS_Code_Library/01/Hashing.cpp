#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
#define MAX 30
#define MOD 1000000007

using namespace std;

#define p1 65537
#define p2 100003

string text, pattern;
int textSize, patternSize;
ll expo1[MAX+10], expo2[MAX+10];
void pre() {
    expo1[0] = expo2[0] = 1;
    for(int i=1; i<=MAX; i++) {
        expo1[i] = (expo1[i-1]*p1) % MOD;
        expo2[i] = (expo2[i-1]*p2) % MOD;
    }
}
ll hashVal1[MAX+10], hashVal2[MAX+10];
void gen() {
    hashVal1[1] = text[0] - 'a' + 1;
    hashVal2[1] = text[0] - 'a' + 1;

    for(int i=1; i<text.size(); i++) {
        hashVal1[i+1] = (hashVal1[i]*p1 + text[i]-'a'+1) % MOD;
        hashVal2[i+1] = (hashVal2[i]*p2 + text[i]-'a'+1) % MOD;
    }
}
pll getHash(int l, int r) {
    ll one, two;
    return pll( ((hashVal1[r+1]-hashVal1[l]*expo1[r-l+1])%MOD + MOD ) % MOD ,
                ((hashVal2[r+1]-hashVal2[l]*expo2[r-l+1])%MOD + MOD ) % MOD );
}

int main() {
    pre();
    text = "abcdabcd";
    textSize = text.size();

    gen();

    cout << getHash(0, 3).first << ' ' << getHash(4,7).first << endl;
    return 0;
}
