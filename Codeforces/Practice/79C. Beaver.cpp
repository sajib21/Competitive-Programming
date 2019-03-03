#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n,m, win[LIM];
char seq[LIM], pat[12][12];


int main() {
    scanf("%s", seq);
    m = strlen(seq);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", pat[i]);

    memset(win, -1, sizeof win);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int sz = strlen(pat[j]);
            bool ff = true;
            for(int k=0; ff && k<sz; k++) {
                if(pat[j][k] != seq[i+k]) ff = false;
            }
            if(ff) {
                if(win[i+sz-1] == -1) win[i+sz-1] = sz;
                else win[i+sz-1] = min(win[i+sz-1], sz);
            }
        }
    }

    int i=0, j=0,ans=0, id=0;

    while(j < m) {
        if(win[j] != -1 && i <= j-win[j]+1) i = j-win[j]+2;
        if(ans < j-i+1) {
            ans = j-i+1;
            id = i;
        }
//        ans = max(ans, j-i+1);
        j++;
    }

    cout << ans << ' ' << id << endl;
}
