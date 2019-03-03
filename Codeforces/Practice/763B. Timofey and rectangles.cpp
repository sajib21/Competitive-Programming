#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    cout << "YES" << endl;

    while(n--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(abs(x1)%2==1 && abs(y1)%2==1) cout << 1 << endl;
        else if(abs(x1)%2==0 && abs(y1)%2==1) cout << 2 << endl;
        else if(abs(x1)%2==1 && abs(y1)%2==0) cout << 3 << endl;
        else cout << 4 << endl;
    }

    return 0;
}
