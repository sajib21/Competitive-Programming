#include<bits/stdc++.h>

using namespace std;

int n, a[250005];
map<int,int>cnt;
vector<int>ans;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n*n; i++) {
        scanf("%d", &a[i]);
        cnt[ a[i] ]++;
    }
    sort(a, a+n*n);
//    for(int i=0; i<n*n; i++) cout << a[i] << ' '; cout << endl;

    for(int i=n*n-1; i>=0; i--) {
        if(cnt[ a[i] ]) {
            cnt[ a[i] ]--;
            for(int p : ans) cnt[ __gcd(a[i], p) ]-=2;
            ans.push_back(a[i]);
        }
    }

    for(int p : ans) cout << p << ' '; cout << endl;
}
