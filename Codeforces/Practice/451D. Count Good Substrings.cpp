#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt[3][3] = {0};
    long long int ans[3] = {0};
    for(int i=0; i<str.size(); i++) {
        int j = i%2, c = str[i]-'a';
        cnt[j][ c ]++;
        ans[0] += cnt[!j][ c ];
        ans[1] += cnt[ j][ c ];
    }
    cout << ans[0] << ' ' << ans[1] << endl;

//    main();
}
