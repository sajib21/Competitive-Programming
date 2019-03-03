#include<bits/stdc++.h>
//#include<sstream>

#define ll long long int
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000

using namespace std;
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n, q;
map<string, int> mp;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        mp.clear();
        scanf("%d", &n);
        for(int p=0; p<n; p++) {
            string str;
            char strr[110];
            scanf("%s", strr);
            str = strr;
//            cin >> str;
            if(str.size() > 2) sort(str.begin()+1, str.end()-1);
//            cout << str << endl;
            mp[str]++;
        }
        scanf("%d", &q);
        getchar();
        printf("Case %d:\n", t);

        while(q--) {

//            string str;
//            getline(cin, str);
            char strr[1010];
            gets(strr);
            string str = strr;
//            cout << str << endl;

            stringstream ss(str);
            int ans = 1;
            while (ss >> str) {
                if(str.size() > 2) sort(str.begin()+1, str.end()-1);
                ans *= mp[str];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

