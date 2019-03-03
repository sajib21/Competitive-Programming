#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 100000
#define MOD 1000000007
#define MAX 1000003
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define EPS 1e-9
#define sqr(x) ((x)*(x))

using namespace std;

int sz, m, x;
string cmd;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        deque<int>dq;
        scanf("%d %d", &sz, &m);
        printf("Case %d:\n", t);
        while(m--) {
            cin >> cmd;
            if(cmd == "pushLeft") {
                scanf("%d", &x);
                if(sz == dq.size()) printf("The queue is full\n");
                else {
                    dq.push_front(x);
                    printf("Pushed in left: %d\n", x);
                }
            }
            else if(cmd == "pushRight") {
                scanf("%d", &x);
                if(sz == dq.size()) printf("The queue is full\n");
                else {
                    dq.push_back(x);
                    printf("Pushed in right: %d\n", x);
                }
            }
            else if(cmd == "popLeft") {
                if(dq.size() == 0) printf("The queue is empty\n");
                else {
                    printf("Popped from left: %d\n", dq.front());
                    dq.pop_front();
                }
            }
            else {
                if(dq.size() == 0) printf("The queue is empty\n");
                else {
                    printf("Popped from right: %d\n", dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    return 0;
}
