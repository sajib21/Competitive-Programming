#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, w[102];
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &w[i]);
    sort(w, w+n);

    int vis[102] = {0};
    queue<int>q;
    q.push(0);

    int ans = 0;
    for(int x=0; x<n; x++) {

        if(!vis[x]) {
            int uW = 1;
            for(int i=x+1; i<n; i++) {
                if(w[i] >= uW && !vis[i]) {
                    uW++;
                    vis[i] = 1;
                }
            }
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
