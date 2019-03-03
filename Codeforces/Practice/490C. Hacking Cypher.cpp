#include<bits/stdc++.h>
#define ll long long int
using namespace std;

string num;
ll a,b, ans = -1;
int taken[1000006];

int main() {

    cin >> num;
    int sz = num.size() - 1;
    for(int i=0; i<=sz; i++) num[i] -= '0';
    //cin >> a >> b;
    scanf("%I64d %I64d", &a,&b);

    int lft = 0, rgt = num.size() - 1;
    ll lftMod = 0, rgtMod = 0, rgtPow = 1;

    while(lft < sz && 0 < rgt) {

        lftMod = (lftMod*10 + num[lft]) % a;
        if(!lftMod) taken[lft]++;//, cout << lft << " a " << taken[lft] << endl;
        rgtMod = ( rgtMod + num[rgt] * rgtPow) % b;
        if(!rgtMod) taken[ rgt-1 ]++;//, cout << rgt << " b " << taken[rgt-1] << endl;
        rgtPow = (10*rgtPow);
        if(taken[lft] == 2 && num[lft+1] != 0) {
            ans = lft+1;
            break;
        }
        if(taken[rgt-1] == 2 && num[rgt] != 0 ) {
            ans = rgt;
            break;
        }


        lft++; rgt--;
    }

    //for(int i=0; i<=sz; i++) printf("taken %d %d\n", num[i], taken[i]);

    if(ans != -1) {
        printf("YES\n");
        for(int i=0; i<ans; i++) printf("%d", num[i]); printf("\n");
        for(int i=ans; i<=sz; i++) printf("%d", num[i]); printf("\n");
    }
    else printf("NO\n");

    return 0;
}
