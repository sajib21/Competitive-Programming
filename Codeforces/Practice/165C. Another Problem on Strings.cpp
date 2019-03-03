#include<bits/stdc++.h>
#define LIM 2000006
#define ll long long int

using namespace std;

int k,n, cnt[LIM];
char str[LIM];
string seq;

int main() {
    scanf("%d", &k);
    cin >> seq;

    seq = "0" + seq;

    for(int i=1; i<seq.size(); i++) {
        cnt[i] = cnt[i-1] + (seq[i] == '1');
    }

    n = seq.size();
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ans += upper_bound(cnt+i+1, cnt+n, k+cnt[i]) - lower_bound(cnt+i+1, cnt+n, k+cnt[i]);
    }

    cout << ans << endl;
}
