#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main() {
    vi v = {10, 9, 6, 4, 2, 1, 0, -2, -3};
    int x = 6;
    int r = lower_bound(v.begin(), v.end(), x, greater<int>()) - v.begin();
    int s = upper_bound(v.begin(), v.end(), x, greater<int>()) - v.begin();

    cout << r << ' ' << s << endl;
}
