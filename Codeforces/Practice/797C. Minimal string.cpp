#include<bits/stdc++.h>

using namespace std;

int main() {
    string a,b,c, mn;
    cin >> a;

    mn = a;
    for(int i=mn.size()-2; i>=0; i--) {
        mn[i] = min(mn[i], mn[i+1]);
    }

//    cout << mn << endl;

    for(int i=0; i<a.size(); i++) {
        b += a[i];

        while(!b.empty() && ( i+1 == mn.size() || b.back() <= mn[i+1]) ) {
//            cout << "QQ " << b.back() << ' ' << a[i+1] << endl;
            c += b.back();
            b.pop_back();
        }
    }

    cout << c << endl;
}
