#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define vsi vector<string>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

int dirR[] = {-1,  -3, +1,  +3};

struct info{
    string seq;
    int r;
    info() {}
    info(string ss, int rr) {
        seq = ss;
        r = rr;
    }
};

char grid[3][3];

map< string , int > mp;

void bfs() {

    queue<info>q;
    string st = "123456780";
    q.push(info( st , 8));
    mp[st] = 1;

    while(!q.empty()) {
        info nd = q.front();
        q.pop();
        string u = nd.seq;
        int r = nd.r;

        for(int i=0; i<4; i++) {
            int rr = r + dirR[i];
            if( (abs(r-rr) == 1 && (r+rr)%3==2) || rr < 0 || rr > 8) continue;
            string v = u;
            swap(v[r] , v[rr]);
            if(!mp[ v ]){
                mp[ v ] = mp[ u ] + 1;
                q.push(info(v, rr));
            }
        }
    }
}

string seq;
int x;

int main() {

    bfs();

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        seq = "";
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                scanf("%d", &x);
                seq += (x + '0');
            }
        }

        if(mp[ seq ]) printf("Case %d: %d\n", t, mp[ seq ]-1);
        else printf("Case %d: impossible\n", t);
    }
    return 0;
}
