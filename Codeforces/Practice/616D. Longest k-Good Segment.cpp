#include<bits/stdc++.h>
#define MAX 1000006

using namespace std;

int n,k, a[MAX], cnt[MAX];

int main() {
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);

    int i=1, j=1;
    int cur = 0;
    int sz=-1, b,c;

    while(j <= n) {
        if(!cnt[ a[j] ]) cur++;
        cnt[ a[j] ]++;

        while(cur > k) {
            if(cnt[ a[i] ] == 1) cur--;
            cnt[ a[i] ]--;
            i++;
        }

        if(j-i+1 > sz) {
            sz = j-i+1;
            b = i; c = j;
        }

        j++;
    }

    cout << b << ' ' << c << endl;
}
