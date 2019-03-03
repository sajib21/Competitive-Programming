#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, m, task[100005];
    cin >> n >> m;
    for(int i=1; i<=m; i++) scanf("%d", &task[i]);
    task[0] = 1;

    long long int ans = 0;
    for(int i=1; i<=m; i++) ans += (task[i] - task[i-1] + n) % n;
    cout << ans << endl;

    return 0;
}
