#include<bits/stdc++.h>

using namespace std;

int main() {
    map<int,int>mp;

    mp[10] = 1001;
    mp[32] = 1e9;
    mp[100] = 10101010;
    mp[16] = 1;

    map<int,int>::iterator it = mp.end();
    it--;

    cout << it->first << ' ' << it->second << endl;

    mp[100] -= 10101010;

    mp.erase(100);

    it = mp.end(); it--;

//    mp.erase(100);


    cout << it->first << ' ' << it->second << endl;
//    cout << it->first << ' ' << it->second << endl;
//    cout << it->first << ' ' << it->second << endl;
}
