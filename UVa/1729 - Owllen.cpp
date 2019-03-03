#include<bits/stdc++.h>

using namespace std;

char str[100005];

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%s", str);
        int cnt[30] = {0};
        int sz = strlen(str);
        for(int i=0; i<sz; i++) {
            cnt[ str[i]-'a' ]++;
        }
        int ans = INT_MAX;
        for(int i=0; i<26; i++) ans = min(ans, cnt[i]);
        printf("Case %d: %d\n", t, ans);
    }
}
