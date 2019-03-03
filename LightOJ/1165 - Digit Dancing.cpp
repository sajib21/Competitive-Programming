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

int idx, mxx = 0;
struct node {
    int val, nxt[10];
    node() {
        val = 0;
        for(int i=0; i<10; i++) nxt[i] = -1;
    }
} trie[400000];

int add(string s, int val=-1) {
    int cur = 0;
    for(int i=0; i<8; i++) {
        int d = s[i] - '0';
        if(trie[cur].nxt[d] == -1) trie[cur].nxt[d] = ++idx;
        cur = trie[cur].nxt[d];
    }
//    mxx = max(idx, mxx);
//    trie[cur].val = val;
    return cur;
}

int chk(string s) {
    int cur = 0;
    for(int i=0; i<8; i++) {
        int d = s[i] - '0';
        cur = trie[cur].nxt[d];
    }
    return cur;
}

int sign[10];
string vec, seqList[400000];
int dis[400000];

int bfs() {
    memset(dis, -1, sizeof(dis));
    int id = chk(vec);

    queue<int>q;
    q.push(id);
    dis[id] = 0;

//    cout << id << ' ' << vec << endl;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        string uvec = seqList[u];

//        cout << u << ' ' << uvec << endl; getchar();

        if(uvec == "12345678") return dis[u];

        for(int i=0; i<8; i++) {
            for(int j=i+1; j<8; j++) {
                if(sign[ uvec[i] - '0' ] * sign[ uvec[j] - '0' ] == 1) continue;
                int p = uvec[i]+uvec[j] - '0' - '0';
                if((p == 2 || p == 3 || p == 5 || p == 7 || p == 11 || p == 13)) {
                    string v;
                    char temp;

                    v = uvec;
                    temp = v[j];
                    v.erase(v.begin()+j);
                    v.insert(v.begin()+i, temp);
//                    for(int k=0; k<i; k++) v += uvec[k];
//                    v += uvec[j];
//                    v += uvec[i];
//                    for(int k=i+1; k<j; k++) v += uvec[k];
//                    for(int k=j+1; k<8; k++) v += uvec[k];
                    int vv = chk(v);
                    if(dis[vv] == -1) {
                        dis[vv] = dis[u] + 1;
                        q.push(vv);
                    }

                    v.clear();
                    v = uvec;
                    temp = v[j];
                    v.erase(v.begin()+j);
                    v.insert(v.begin()+i+1, temp);
//                    for(int k=0; k<i; k++) v += uvec[k];
//                     v += uvec[i];
//                     v += uvec[j];
//                    for(int k=i+1; k<j; k++) v += uvec[k];;
//                    for(int k=j+1; k<8; k++) v += uvec[k];;
                    vv = chk(v);
                    if(dis[vv] == -1) {
                        dis[vv] = dis[u] + 1;
                        q.push(vv);
                    }

                    v.clear();
                    v = uvec;
                    temp = v[i];
                    v.erase(v.begin()+i);
                    v.insert(v.begin()+j-1, temp);
//                    for(int k=0; k<i; k++)  v += uvec[k];
//                    for(int k=i+1; k<j; k++)  v += uvec[k];
//                     v += uvec[i];
//                     v += uvec[j];
//                    for(int k=j+1; k<8; k++) v += uvec[k];
                    vv = chk(v);
                    if(dis[vv] == -1) {
                        dis[vv] = dis[u] + 1;
                        q.push(vv);
                    }

                    v.clear();
                    v = uvec;
                    temp = v[i];
                    v.erase(v.begin()+i);
                    v.insert(v.begin()+j, temp);
//                    for(int k=0; k<i; k++) v += uvec[k];
//                    for(int k=i+1; k<j; k++) v += uvec[k];
//                     v += uvec[j];
//                     v += uvec[i];
//                    for(int k=j+1; k<8; k++) v += uvec[k];
                     vv = chk(v);
                    if(dis[vv] == -1) {
                        dis[vv] = dis[u] + 1;
                        q.push(vv);
                    }

                }
            }
        }
    }
    return -1;
}

int main() {

//    freopen("1165i.txt", "r", stdin);
//    freopen("1165o.txt", "w",stdout);

    idx = 0;
    string init;
    for(int i=1; i<=8; i++) init += i + '0';
    do {
        seqList[ add(init) ] = init;
    }while(next_permutation(init.begin(), init.end()));
//    cout << "BUG" << endl;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        vec.clear();
//        idx = 0;
//        memset(trie, -1, sizeof(trie));
        for(int i=0; i<8; i++) {
            int x;
            scanf("%d", &x);
            vec += ( abs(x) + '0');
            if(x > 0) sign[abs(x)] = 1;
            else sign[abs(x)] = -1;

        }
//        cout << vec << endl;
        printf("Case %d: %d\n", t, bfs());
//        cout << "BUG" << endl;
    }

    return 0;
}


