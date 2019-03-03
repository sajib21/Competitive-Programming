#include<bits/stdc++.h>

using namespace std;

int main() {

    int t,T;
    scanf("%d",&T);
    for(t=1; t<=T; t++) {

        int ara[105];
        int ara2[105];
        int swp = 0;
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            int x;
            scanf("%d",&x);
            ara[x] = i;
            ara2[i] = x;
        }

        for(int i=1; i<=n; i++) {
            if(i != ara2[i]) {
//                int temp1 = ara[i], temp2 = ara2[temp];
//                ara2[temp1] = ara2[i];
//                ara[i] = i;
//                ara2[ ara[temp2] ];
//                ara[]
                int temp = ara2[i];
                swap(ara2[i], ara2[ ara[i] ]);
                swap(ara[i], ara[ temp ]);
                swp++;
                //cout << ".";

//                for(int i=1; i<=n; i++) cout << ara2[i] << ' ';
//                cout << endl;
            }
        }

        printf("Case %d: %d\n",t,swp);
    }

    return 0;
}
