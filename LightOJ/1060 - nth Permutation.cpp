#include<bits/stdc++.h>
#define ll long long int

using namespace std;

string seq, ans;
ll n, sz, alpha[30];
ll fact[22];

int main() {

    fact[0] = 1;
    for(int i=1; i<=20; i++) fact[i] = i * fact[i-1];

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        memset(alpha, 0, sizeof(alpha));

        ans = "";
        cin >> seq;
        scanf("%d", &n);

        sz = seq.size();
        for(int i=0; i<sz; i++) alpha[ seq[i] - 'a' ]++;

        printf("Case %d: ", t);
        for(int i=0; i<sz; i++) {
            for(int j=0; j<26; j++) {
                if(alpha[j]) {

                    ll temp = fact[sz-i-1];
//                    cout << temp << endl;
                    for(int k=0; k<26; k++) {
                        if(alpha[k]) {
                            if(j == k) {
                                temp /= fact[ alpha[k] - 1 ];
                            }
                            else {
                                temp /= fact[ alpha[k] ];
                            }
//                            cout << "AFTER DIV " << k << ' ' << j << ' ' << temp << endl;
                        }
                    }

//                    cout << temp << endl;

                    if(temp < n) {
                        n -= temp;
                    }
                    else {
//                        printf("%c", 'a'+j);
                        ans += 'a' + j;
                        alpha[j]--;
                        break;
                    }
                }
            }
            if(ans.size() <= i) break;
        }
        if(ans.size() < sz) printf("Impossible\n");
        else cout << ans << endl;
    }
    return 0;

}
