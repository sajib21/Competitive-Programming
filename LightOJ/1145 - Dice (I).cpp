#include<bits/stdc++.h>
#define LIM 1000
#define ll long long int
#define MOD 100000007

using namespace std;

int n,k,s;
int cnta[15*LIM + 10];
int cntb[15*LIM + 10];

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        scanf("%d %d %d", &n,&k,&s);

        if(s < n) {
            printf("Case %d: 0\n", t);
            continue;
        }



        for(int i=1; i<=k; i++) cnta[i] = 1;
        int temp1 = cntb[0], temp2;
        for(int i=1; i<=s; i++) {
            temp2 = cntb[i];
            cntb[i] = ( temp1 + cntb[i-1] + cnta[i] );
            temp1 = temp2;
//            cout << cntb[i] << ' ';
//            getchar();
        }
//        cout << endl;

//        for(int i=1; i<=10; i++) {
//            for(int j=1; j<=10; j++) {
//                cout << cntb[i][j] << ' ';
//            }
//            cout << endl;
//        }

        for(int i=2; i<=n; i++) {
            for(int j=i; j<=s; j++) {
                cnta[j] = ( cntb[j-1] - cntb[ max(0, j-1-k) ] + MOD ) % MOD ;
            }
            int temp1 = cntb[i-1] , temp2;
            cntb[i-1] = 0;
            for(int j=i; j<=s; j++) {
                temp2 = cntb[j];
                cntb[j] = (cntb[j-1] + cnta[j] ) % MOD;
                temp1 = temp2;
            }
        }
        printf("Case %d: %d\n", t, cnta[s]);

//        for(int i=1; i<=10; i++) {
//            for(int j=1; j<=10; j++) {
//                cout << cnta[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//        for(int i=1; i<=10; i++) {
//            for(int j=1; j<=10; j++) {
//                cout << cntb[i][j] << ' ';
//            }
//            cout << endl;
//        }

    }

    return 0;

}
