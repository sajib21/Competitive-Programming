#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int>v;

    int n, k, ara[100005], flag[100005];
    memset(flag, 0, sizeof(flag));

    int t;

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        scanf("%d", &ara[i]);
    }

    int st = 0, ed=0, cnt = 1; flag[ ara[0] ] = 1;
    for(int i=1; i<n && cnt < k; i++) {

        if(!flag[ ara[i] ]) cnt++;
        flag[ ara[i] ]++;

        while(flag[ ara[st] ] > 1 && st != i) {
            flag[ ara[st] ]--;
            st++;
        }

        if(cnt == k) {
            ed = i; break;
        }

    }

    if(cnt == k) cout << st+1 << ' ' << ed+1 << endl;
    else cout << "-1 -1" << endl;

    return 0;

}
