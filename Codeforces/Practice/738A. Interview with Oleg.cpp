#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    char ans[105];
    cin >> n;
    cin >> s;
    int j=0;
    for(int i=0; i<n; ) {
        if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o') {
            ans[j++] = '*';
            ans[j++] = '*';
            ans[j++] = '*';
            i += 3;
            while(s[i] == 'g' && s[i+1] == 'o') {
                i += 2;
            }
        }
        else {
            ans[j++] = s[i++];
        }
    }

    ans[j] = 0;

    printf("%s\n", ans);
//    cout << ans << endl;

    return 0;
}
