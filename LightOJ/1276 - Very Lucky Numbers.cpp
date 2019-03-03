#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define LIM 1000000000000LL
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define vll vector<ll>

using namespace std;

vll lucky, veryLucky;
int sz, sz2;

void genLucky(ll lk) {
    if(lk > LIM) return;
    if(lk) lucky.pb(lk);
    genLucky(lk*10 + 4);
    genLucky(lk*10 + 7);
}

int tim = 1;
void genVeryLucky(ll lk, int in) {
    if(lk > LIM) return;
//    cout << lk << endl; getchar();
    if(in == sz) {
        if(lk > 1) veryLucky.pb(lk);
        return;
    }

    genVeryLucky(lk*lucky[in], in);
    genVeryLucky(lk*lucky[in], in+1);
//    genVeryLucky(lk, in+1);
//    for(int i=0; i<sz; i++){
//        if(lk * lucky[i] > LIM) return;
//        genVeryLucky(lk*lucky[i]);
//    }
}

int main() {

    genLucky(0);
    sz = lucky.size();
    sort(lucky.begin(), lucky.end());
    cout << sz << endl;
    genVeryLucky(1, 0);
    sort(veryLucky.begin(), veryLucky.end());
    sz2 = veryLucky.size();
    cout << sz2 << endl;
    cout << tim << endl;
    for(int i=0; i<10; i++) cout << veryLucky[i] << ' ' ; cout << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

    }

}
