#include<bits/stdc++.h>

using namespace std;

int n,k, taken[30];
vector<int>ans;

void permute(int in) {

    if(k <= 0) return;

    if(in == n) {
        for(int i=0; i<n; i++) printf("%c", ans[i] + 'A');
        printf("\n");
        k--;
        return;
    }

    for(int i=0; i<n && k>0 ; i++) {
        if(!taken[i]) {
            taken[i] = 1;
            ans.push_back(i);
            permute(in+1);
            ans.pop_back();
            taken[i] = 0;
        }
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t=1; t<=T; t++) {
        scanf("%d %d", &n,&k);
        printf("Case %d:\n", t);
        permute(0);
    }
    return 0;
}
