#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int sz;
char seq[10004];
int tim, tim1, sub1[5002], sub2[5002];

int in;
int dfs1(int sub[]) {
    int u = tim1;
    int cnt = 1;
    while(in < sz) {
        if(seq[in] == '1') {
            tim1++; in++;
            cnt += dfs1(sub);
        }
        else {
            in++;
            break;
        }
    }
    return sub[u] = cnt;
}

int main() {

//    freopen("i.txt", "r", stdin);
//    freopen("o.txt", "w",stdout);

    int T;
    scanf("%d", &T); getchar();
    for(int t=1; t<=T; t++) {

        gets(seq);
        sz = strlen(seq);
        tim1 = 0; in = 0;
        dfs1(sub1);
        sort(sub1, sub1+tim1+1);
        tim = tim1;

        gets(seq);
        sz = strlen(seq);
        tim1 = 0; in = 0;
        dfs1(sub2);
        sort(sub2, sub2+tim1+1);

        bool flag = true;
        for(int i=0; i<=max(tim, tim1); i++) if(sub1[i] != sub2[i]) {
            flag = false;
            break;
        }
        if(flag) printf("Case %d: Same\n", t);
        else printf("Case %d: Different\n", t);
    }

    return 0;
}
