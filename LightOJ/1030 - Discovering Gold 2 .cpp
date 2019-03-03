#include<bits/stdc++.h>

using namespace std;

int gold[111];
int n;
double expct[111];

int main() {

    int t, T;
    cin >> T;
    for(t=1; t<=T; t++) {

        //memset(expc, 0, sizeof(expc));
        memset(gold, 0, sizeof(gold));


        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> gold[i];
        }

        expct[n] = gold[n];

        for(int i=n-1; i>0; i--) {

            double ex = 0;
            int j = i+1;
            for(j=i+1; j<=n && j<=i+6; j++) {
                ex += expct[j];
            }
            //ex /= j-i-1;
            //cout << "ager gula " << ex << endl;
            expct[i] = gold[i] + 1.0 * ex/(j-i-1);
            //cout << expct[i] << endl;
        }

        printf("Case %d: %.10lf\n", t, expct[1] );
    }

    return 0;
}

