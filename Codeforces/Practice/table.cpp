#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back

using namespace std;
vii mul;

int main() {
    int n,m,q = 10;
    n = 10; m = 10;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            printf("%4d", i*j);
            mul.pb(i*j);
        }
        cout << endl;
    }
    sort(mul.begin(), mul.end());

    while(true) {
        int k;
        scanf("%d", &k);
        if(!k) return 0;
        cout << mul[k-1] << endl;
    }
}
