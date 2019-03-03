#include<bits/stdc++.h>
#define LIM 1000006

using namespace std;

string s1, s2;
int nxt[LIM][30], cur[30];

set<int>a,b;

int main() {
    cin >> s1 >> s2;

    for(int i=0; i<s1.size(); i++) a.insert(s1[i]);
    for(int i=0; i<s2.size(); i++) b.insert(s2[i]);

    for(auto it : b) {
        if(a.find(it) == a.end()) {
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=s1.size()-1; i>=0; i--) {
        for(int j=0; j<26; j++) {
            nxt[i][j] = cur[j];
        }
        cur[ s1[i]-'a' ] = i;
    }

    int ans = 1;

    int i=0, j=0;

    while(j < s2.size()) {
        if(s1[i] == s2[j]) {
            j++;
            i++;
        }
        else {
            int k = nxt[i][ s2[j]-'a' ];
            if(i >= k) ans++;
            i = k;
        }
    }
    cout << ans << endl;
}
