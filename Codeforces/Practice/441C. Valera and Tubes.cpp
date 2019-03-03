#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    int div = n*m/k, mod = (n*m)%k;

    int dir = -1, rem = div, c=1;
    //cout << rem;
    printf("%d", rem);
    for(int r=1, t=1; r<=n; r++) {

        dir *= -1;
        for(; c<=m && c>0; c += dir) {
            if(rem) {
                //cout << ' ' << r << ' ' << c;
                printf(" %d %d", r,c);
                rem--;
            }
            else {
                t++;
                //cout << endl;
                printf("\n");
                //cout << div;
                if(t == k) rem = div + mod;
                else rem = div;
                //cout << rem;
                printf("%d", rem);
                //cout << ' ' << r << ' ' << c;
                printf(" %d %d", r,c);
                rem--;
            }
        }
        c -= dir;

    }
    //cout << endl;
    printf("\n");
    return 0;
}
