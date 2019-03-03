#include<bits/stdc++.h>

using namespace std;

int main() {
    freopen("1327i.txt", "w", stdout);

    int T = 10;
    cout << T << endl << endl;
    for(int t=1; t<=T; t++) {
        int n = rand() % 15 + 1;
        cout << n << endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << rand() % 3 << ' ' ;
            }
            cout << endl;
        }
        cout << endl;
    }


}
