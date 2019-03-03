#include<bits/stdc++.h>

using namespace std;

int main() {

    int n,k;
    string line;
    cin >> n >> k;
    cin >> line;

    int s,d;

    for(int i=0; i<n; i++) {
        if(line[i] == 'G') s = i;
        if(line[i] == 'T') d = i;
    }

    bool f = false;
    for(int i=s; i<n; i+=k) {
        if(line[i] == 'T') {
            cout << "YES" << endl;
            return 0;
        }
        if(line[i] == '#') break;
    }
    for(int i=s; i>=0; i-=k) {
        if(line[i] == 'T') {
            cout << "YES" << endl;
            return 0;
        }
        if(line[i] == '#') break;
    }


    cout << "NO" << endl;

    return 0;
}
