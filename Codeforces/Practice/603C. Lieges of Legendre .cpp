#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int n,k,x;
ll xorSum = 0;

ll get(int n) {

    if(n == 0 || n == 2) return 0;
    else if( n == 1 || n == 3) return 1;
    else if(n%2) return 0;
    else if(n == 4) return 2;
    else if( get(n/2) != 1 ) return 1;
    else return 2;
}

int main() {

    scanf("%d %d", &n, &k);

    if(k%2==0) {
        while(n--) {
            int g = 0;
            scanf("%d", &x);
            if(x == 0) g = 0;
            else if(x == 1) g = 1;
            else if(x == 2) g = 2;
            else if(x % 2) g = 0;
            else g = 1;

            xorSum ^= g;
        }
    }

    else {
        while(n--) {
            ll g = 0;
            scanf("%d", &x);
            g = get(x);
            xorSum ^= g;
        }
    }

//    cout << xorSum << endl;

    if(xorSum) cout << "Kevin" << endl;
    else cout << "Nicky" << endl;

    return 0;
}
