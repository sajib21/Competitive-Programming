#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k, cnta[5][30] = {0}, cntb[5][30] = {0};
        char str[10];

        scanf("%d", &k); k--;
        for(int i=0; i<6; i++) {
            scanf("%s", str);
            for(int j=0; j<5; j++) cnta[j][ str[j]-'A' ]++;
        }
        for(int i=0; i<6; i++) {
            scanf("%s", str);
            for(int j=0; j<5; j++) cntb[j][ str[j]-'A' ]++;
        }

        vector<char>col[5];
        for(int i=0; i<5; i++) {
            for(int j=0; j<26; j++) if(cnta[i][j] && cntb[i][j]) col[i].pb('A'+j);
        }

        int mul[10];
        mul[5] = 1;
        for(int i=4; i>=0; i--) mul[i] = mul[i+1]*col[i].size();
//        for(int i=0; i<5; i++) cout << col[i].size() << ' ' ; cout << endl;
//        for(int i=0; i<5; i++) cout << mul[i] << ' ' ; cout << endl;

        string ans = "";
        bool f = false;
        for(int i=0; i<5; i++) {
            f = false;
            for(int j=0; !f && j<col[i].size(); j++) {
                if(k < mul[i+1]) {
                    ans += col[i][j];
                    f = true;
                    break;
                }
                else {
                    k -= mul[i+1];
                }
            }
            if(!f) break;
        }
//        cout << k << endl;
        if(!f) printf("NO\n");
        else cout << ans << endl;
    }
    return 0;
}
