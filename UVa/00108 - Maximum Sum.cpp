#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;

    while(scanf("%d", &n) != EOF) {

        int matrix[110][110] = {0};
        int sum[110][110] = {0};

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=1; k<=i; k++) {
                    for(int l=1; l<=j; l++) {
                        sum[i][j] += matrix[k][l];
                    }
                }
            }
        }

        int sz = INT_MIN ;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                for(int k=0; k<=i; k++) {
                    for(int l=0; l<=j; l++) {
                        sz = max(sz, sum[i][j] - sum[k][j] - sum[i][l] + sum[k][l] );
                    }
                }
            }
        }

        cout << sz << endl;
    }

    return 0;

}
