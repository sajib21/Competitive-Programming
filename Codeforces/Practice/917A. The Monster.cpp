#include<bits/stdc++.h>

using namespace std;

int n, f[5050][5050], g[5050][5050];
char seq[5050];

int main() {
    scanf("%s", seq);
    n = strlen(seq);

    for(int i=0; i<n; i++) {
        int c = 0;
        for(int j=i; j<n; j++) {
            if(seq[j] == ')') c--;
            else c++;

            if(c < 0) break;

            f[i][j] = 1;
        }
    }

    for(int j=0; j<n; j++) {
        int c = 0;
        for(int i=j; i>=0; i--) {
            if(seq[j] == '(') c--;
            else c++;

            if(c < 0) break;

            g[i][j] = 1;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(f[i][j] && g[i][j] && (j-i+1)%2==0) ans++;
        }
    }

    cout << ans << endl;
}
