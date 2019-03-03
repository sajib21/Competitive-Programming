#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; } int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }

void printBin(int n) { if(!n) {cout << 0 ; return; } printBin(n>>1); cout << n%2; }

int n,m;
char seq[130][15];
int dp[1 << 11][1 << 11];

int f(int takenMask, int ansMask) {
    if(dp[takenMask][ansMask] != -1) return dp[takenMask][ansMask];

    vii taken, id;
    for(int i=0; i<m; i++) if(chkBit(takenMask, i)) taken.pb(i);

    if(!taken.size()) for(int i=0; i<n; i++) id.pb(i);
    else {
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<taken.size() && flag; j++) {
                if( (chkBit(ansMask, taken[j] ) && seq[i][ taken[j] ] == '1') || (!chkBit(ansMask, taken[j] ) && seq[i][ taken[j] ] == '0') ) flag = true;
                else flag = false;
            }
            if(flag) id.pb(i);
        }
    }
    if(id.size() == 1) return dp[takenMask][ansMask] = 0; /// BASE CASE

    int ans = m;
    for(int i=0; i<m; i++) if(!chkBit(takenMask, i)) {
        bool flag = true;
        for(int j=1; j<id.size() && flag; j++) if(seq[ id[j] ][i] != seq[ id[j-1] ][i]) flag = false;
        if(flag) ans = min(ans, f(setBit(takenMask, i), seq[ id[0] ][i] == '1' ? setBit(ansMask, i) : ansMask ) );
        else ans = min(ans, 1 + max( f(setBit(takenMask, i), ansMask ) , f(setBit(takenMask, i), setBit(ansMask, i) ) ) ) ;
    }
    return dp[takenMask][ansMask] = ans;
}

int main() {
    while(scanf("%d %d", &m,&n)) {
        if(!n && !m) return 0;

        for(int i=0; i<n; i++) scanf("%s", seq[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", f(0, 0));
    }
}
