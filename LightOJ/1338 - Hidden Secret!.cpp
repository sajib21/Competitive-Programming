#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T); getchar();
    for(int t=1; t<=T; t++) {

        string one,two;
        int cnt1[30], cnt2[30], sz1,sz2;
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        getline(cin, one);
        getline(cin, two);
        sz1 = one.size();
        sz2 = two.size();
        for(int i=0; i<sz1; i++) {
            char c = tolower(one[i]);
            if(c >= 'a' && c <= 'z') cnt1[c-'a']++;
        }
        for(int i=0; i<sz2; i++) {
            char c = tolower(two[i]);
            if(c >= 'a' && c <= 'z') cnt2[c-'a']++;
        }
        bool res = true;
        for(int i=0; i<26; i++) {
            if(cnt1[i] != cnt2[i]) {
                res = false;
                break;
            }
        }
        if(res) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);
    }
    return 0;
}
