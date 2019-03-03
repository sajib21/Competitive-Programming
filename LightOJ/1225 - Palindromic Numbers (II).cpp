
#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
//        string a,b;
//        cin >> a;
        bool flag = true;
        char a[15];
        scanf("%s", a);
        int sz = strlen(a);
        for(int i=0; i<sz; i++) {
            if(a[i] != a[sz-i-1]) {
                flag = false;
                break;
            }
        }

        if(flag) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);
    }
    return 0;
}
