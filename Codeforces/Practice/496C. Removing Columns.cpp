#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, sz, cmp[303] = {0};
    string str[303];

    cin >> n >> sz;
//    cin >> str;
//    sz = str.size();

    for(int i=0; i<n; i++) cin >> str[i];

    int moves = 0;
    for(int i=0; i<sz; i++) {
        vector<int>temp;
        bool flag = false;
        for(int j=1; j<n; j++) {
            if(cmp[j] == 0) {
                if(str[j][i] > str[j-1][i]) temp.push_back(j);
                else if(str[j][i] < str[j-1][i]) {
                    moves++;
                    flag = true;
                    break;
                }
            }
        }
        if(flag==false) {
            int ssz = temp.size();
            for(int x=0; x<ssz; x++) cmp[ temp[x] ] = 1;
        }
    }

    cout << moves << endl;
}
