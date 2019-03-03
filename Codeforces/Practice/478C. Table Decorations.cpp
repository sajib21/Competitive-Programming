#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ll col[4];
    cin >> col[0] >> col[1] >> col[2];

    sort(col, col+3);

    cout << min(col[0]+col[1], (col[0]+col[1]+col[2])/3) << endl;

//y = min( (b-g)/2, r-g );
    return 0;
}
