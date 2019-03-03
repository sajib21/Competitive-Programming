#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        int r,c, grid, xorSum = 0;
        scanf("%d %d", &r,&c);
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                scanf("%d", &grid);
                int d = r - i + c - j - 2;
                if(grid && (d%2 == 1) ) xorSum ^= grid; ///ZERO HOILE TO CHAL DWAR KICHU NAI TAI AGE MAKE SURE KORTE HOIBO NONZERO HOWAR.
            }
        }

        if(xorSum) printf("Case %d: win\n", t);
        else printf("Case %d: lose\n", t);
    }

    return 0;
}
