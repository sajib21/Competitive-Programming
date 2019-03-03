#include<bits/stdc++.h>

using namespace std;

int main() {
    map<int,int>mp;

    mp[10] = 11;
    mp[20] = 21;
    mp[30] = 31;
    mp[10]++;
    mp[20] = 0;
    mp.erase(20);

    cout << mp.size() << endl;

    map<int,int>:: iterator it = mp.lower_bound(21);

    cout << it->first << ' ' << it->second << endl;

}
