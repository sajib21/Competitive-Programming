#include<bits/stdc++.h>
#define LIM 100005
#define ll long long int

using namespace std;

bool cmp(string s, string t) {
    ll ss=0, sh=0, ts=0, th=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 's') ss++;
        else sh++;
    }
    for(int i=0; i<t.size(); i++) {
        if(t[i] == 's') ts++;
        else th++;
    }

    return ss*th > ts*sh;

}

int n;
char seq[LIM];
string str[LIM];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", seq);
        str[i] = seq;
    }

    sort(str, str+n, cmp);

    ll s=0, h=0, ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<str[i].size(); j++) {
            if(str[i][j] == 's') s++;
            else {
                h++;
                ans += s;
            }
        }
    }
    cout << ans << endl;

}
