#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll

using namespace std;

int setBit(int mask, int pos) { return mask | (1 << pos) ; } int togBit(int mask, int pos) { return mask ^ (1 << pos) ; }
int chkBit(int mask, int pos) { return mask & (1 << pos) ; }
void printBin(int n) { if(!n) { cout << 0 ; return; } printBin(n>>1); cout << n%2; }

int n;
ull num;
char str[20];
string a,b;
ll dp[20][1 << 10][1 << 10][3];
bool go[20][1 << 10][1 << 10][3];

bool chk(int mask, int taken) {
    for(int i=0; i<=9; i+=2) if(chkBit(taken, i) && !chkBit(mask, i)) return false;
    for(int i=1; i<=9; i+=2) if(chkBit(taken, i) &&  chkBit(mask, i)) return false;
    return true;
}

ll f(int in, int mask, int taken, int con) { /// 0 starting; 1,2 choto; 3 soman
    if(in == n) return chk(mask, taken);
    if(go[in][mask][taken][con]) return dp[in][mask][taken][con];

    int lim = 9; if(con == 3 || con == 0) lim = a[in] - '0';
    int ans = 0;

    for(int i=0; i <= lim ; i++) {
        if(con == 0) {
            if(i == 0) ans += f(in+1, mask, taken, 1);
            else if(i < a[in]-'0') ans += f(in+1, togBit(mask, i), setBit(taken, i), 2);
            else ans += f(in+1, togBit(mask, i), setBit(taken, i), 3);
        }
        else if(con == 1) {
            if(i == 0) ans += f(in+1, mask, taken, 1);
            else ans += f(in+1, togBit(mask, i), setBit(taken, i), 2);
        }
        else if(con == 2) {
            ans += f(in+1, togBit(mask, i), setBit(taken, i), 2);
        }
        else {
            if(i < a[in]-'0') ans += f(in+1, togBit(mask, i), setBit(taken, i), 2);
            else ans += f(in+1, togBit(mask, i), setBit(taken, i), 3);
        }
    }

    go[in][mask][taken][con] = 1;
    return dp[in][mask][taken][con] = ans;
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%llu", &num); num--;
        stringstream ss;
        ss << num;
        a = ss.str();
        n = a.size();

        memset(go, 0, sizeof go);
        ll lft = f(0, 0, 0, 0);

        scanf("%s", str); a = str;
        n = a.size();
        memset(go, 0, sizeof go);
        ll rgt = f(0,0,0,0);

        printf("%lld\n", rgt-lft);
    }
    return 0;
}
