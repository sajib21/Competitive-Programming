#include<bits/stdc++.h>

using namespace std;

string a,b;
vector<long long>x,y;

int main() {
    string a,b;
    cin >> a >> b;

//    x.push_back(0); x.push_back(0);
//    y.push_back(0); y.push_back(0);

    for(int i=0; i<a.size(); i++) x.push_back(a[i]-'0');
    for(int i=0; i<b.size(); i++) y.push_back(b[i]-'0');
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    while(x.size() < y.size()) x.push_back(0);
    while(y.size() < x.size()) y.push_back(0);

    for(int i=2; i<x.size(); i++) {
        int mn = min(x[i-2], x[i-1]);
        x[i-2] -= mn; x[i-1] -= mn;
        x[i] += mn;
    }
    for(int i=2; i<y.size(); i++) {
        int mn = min(y[i-2], y[i-1]);
        y[i-2] -= mn; y[i-1] -= mn;
        y[i] += mn;
    }

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    if(x < y) cout << "<" << endl;
    else if(x > y) cout << ">" << endl;
    else cout << "=" << endl;

}
