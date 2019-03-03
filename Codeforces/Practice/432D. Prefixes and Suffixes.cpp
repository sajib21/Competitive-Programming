/// if you use kmp on non-string problem, make sure data is not kept in
/// string, strings can only hold char which has max value of 255

#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

string text, pattern;
int Z[LIM];
int ans[LIM], ok[LIM];

void genZ() {
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

int main() {
    cin >> pattern;

    genZ();

//    cout << "Z" << endl;
//    for(int i=0; i<pattern.size(); i++) cout << Z[i] << ' '; cout << endl;

    int n = pattern.size();

    ans[1]++; ans[n+1]--;
    ok[n] = 1;

    for(int i=1; i<pattern.size(); i++) {
        ans[1]++;
        ans[ Z[i]+1 ]--;

        if(Z[i] == n-i) ok[ Z[i] ] = 1;
//        cout << Z[i] << endl;
    }
//    ans[n]++;

    for(int i=1; i<=n; i++) {
        ans[i] += ans[i-1];
    }

//    for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;



//    for(int i=0; i<pattern.size(); i++) {
//        if(!Z[i]) continue;
////        cout << i << ' ' << Z[i] << ' ' << Z[ n-Z[i] ] << endl;
//        if(Z[ n-Z[i] ] == Z[i]) ans[ Z[i] ]++;
//    }
//    for(int i=n; i>=0; i--) ans[i] += ans[i+1];

    int p = 0;
    for(int i=1; i<=n; i++) if(ans[i] && ok[i]) p++;
//    ans[1]++;
    cout << p << endl;
    for(int i=1; i<=n; i++) if(ans[i] && ok[i]) printf("%d %d\n", i, ans[i]);
//    cout << n << ' ' << 1 << endl;

    return 0;
}
