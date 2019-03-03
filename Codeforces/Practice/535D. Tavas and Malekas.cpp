#include<bits/stdc++.h>
#define LIM 1000006
#define MOD 1000000007

using namespace std;

string text, pattern;
int Z[LIM], z[LIM];

void genZ(string pattern) {
    int n = pattern.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R<n && pattern[R-L] == pattern[R]) R++;
            Z[i] = R-L;
            R--;
        }
        else {
            k = i-L;

            if (Z[k] < R-i+1) Z[i] = Z[k];

            else {
                L = i;
                while (R<n && pattern[R-L] == pattern[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int n,m, x;

int main() {
    memset(z, -1, sizeof z);

    scanf("%d %d", &n, &m);
    cin >> pattern;
    genZ(pattern);

    int last = 0;
    int cnt = 0;
    for(int i=0; i<m; i++) {
        scanf("%d", &x); x--;
//        cout << "LAST " << last << endl;
        if(x >= last) {
            cnt += x-last;
            for(int j=0, k=x; j<pattern.size(); j++, k++) {
                z[k] = Z[j];
            }
            last = x+pattern.size();
        }
        else {
            if(Z[pattern.size() - (last-x)] != last-x) {
                cout << 0 << endl;
                return 0;
            }
            else {
//                for(int j=pattern.size()-1; j>=z[x]; j--) {
//                    z[x+j] = Z[j];
//                }
                last = x+pattern.size();
            }
        }
//        for(int j=0; j<10; j++) cout << Z[j] << ' '; cout << endl;
    }

//    cout << last << endl;

    cnt += n-last;

    long long int ans = 1;
    for(int i=0; i<cnt; i++) {
        ans *= 26;
        ans %= MOD;
    }

    cout << ans << endl;

//    cout << "Z" << endl;
//    for(int i=0; i<pattern.size(); i++) cout << Z[i] << ' ';
//    cout << endl;

    return 0;
}
