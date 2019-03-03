#include<bits/stdc++.h>

using namespace std;

///A is 1 based
string intToExcel(int A) {
    string ans;

    while(true) {
        A--;
        ans += (A%26) + 'A';
        A /= 26;
        if(!A) break;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int a;
    while(cin >> a) {
        cout << intToExcel(a) << endl;
    }
}
