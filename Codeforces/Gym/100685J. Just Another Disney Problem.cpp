#include<bits/stdc++.h>
#define LIM 1000
#define vii vector<int>
#define pb push_back

using namespace std;

int n, ara[LIM+10];
char ans[20];

void f(int st, int ed) {
    if(st == ed) return;
    int md = (st+ed) / 2;
    f(st, md);
    f(md+1, ed);

    vii temp;

    int i=st, j=md+1;
    while(i <= md && j <= ed) {
        printf("1 %d %d\n", ara[i], ara[j]);
        fflush(stdout);

        scanf("%s", ans);
        if(ans[0] == 'Y') temp.pb(ara[i++]);
        else temp.pb(ara[j++]);
    }
    while(i <= md) temp.pb(ara[i++]);
    while(j <= ed) temp.pb(ara[j++]);

    for(i=st,j=0; j<temp.size(); i++,j++) ara[i] = temp[j];
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) ara[i] = i;

    f(1, n);

    printf("0");
    for(int i=1; i<=n; i++) printf(" %d", ara[i]);
    fflush(stdout);

    return 0;
}
