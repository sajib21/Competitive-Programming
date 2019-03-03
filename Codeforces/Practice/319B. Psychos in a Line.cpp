#include<bits/stdc++.h>

using namespace std;

int n, a[100005], nxt[100005], pre[100005];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    a[n] = INT_MAX;
    for(int i=0; i<n; i++) nxt[i] = i+1;
    for(int i=1; i<=n; i++) pre[i] = i-1;

    queue<int>q; q.push(-1);
    for(int i=n-1; i>0; i--) if(a[i] < a[ pre[i] ]) q.push(i);

    int ans = 0;
    while(!q.empty()) {
        int in = q.front();
        q.pop();

        if(in == -1) {
            if(q.empty()) break;
            q.push(-1);
            ans++;
            continue;
        }

        nxt[ pre[in] ] = nxt[in];
        pre[ nxt[in] ] = pre[in];
        if(a[ pre[in] ] > a[ nxt[in] ]) q.push(nxt[in]);
    }
    cout << ans << endl;

}
