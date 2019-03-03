#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007

using namespace std;

struct info{
    int x,y,z;
    info();
    info(int xx, int yy, int zz) { x = xx; y = yy; z = zz; }
};

int n, a,b,x, k, vis[52][52][2];
ll comb[52][52], cnt[52][52][2];

int main() {
    comb[0][0] = 1;
    for(int i=1; i<=50; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j=1; j<i; j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
    }

    scanf("%d %d", &n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(x == 50) a++;
        else b++;
    }
    memset(vis, -1, sizeof vis);

    queue<info>q;
    q.push(info(a,b,0));
    vis[a][b][0] = 0; cnt[a][b][0] = 1;

    while(!q.empty()) {
        info cur = q.front();
        q.pop();
        int ua = cur.x, ub = cur.y, uc = cur.z;
        int ra = a-ua,  rb = b-ub;
//
//        cout << "OUT " << ua << ' ' << ub << ' ' << uc << ' ' << vis[ua][ub][uc] << ' ' << cnt[ua][ub][uc] << endl;
//        cout << ra << ' ' << rb << endl;
//        getchar();

        if(ua == a && ub == b && uc == 1) break;

//        if(uc == 1) {
//            if(ua)
//
//            continue;
//        }

        for(int i=0; i<=ua && 50*i<=k; i++) {
            for(int j=0; j<=ub && 50*i+100*j<=k; j++) {
                if(i+j == 0) continue;
                int va = i, vb = j, vc = !uc;
                if(vis[ra+va][rb+vb][vc] == -1) {
                    vis[ra+va][rb+vb][vc] = vis[ua][ub][uc] + 1;
                    cnt[ra+va][rb+vb][vc] = (cnt[ua][ub][uc] * (comb[ua][va]*comb[ub][vb])%MOD) % MOD;
                    q.push(info(ra+va,rb+vb,vc));
                }
                else if(vis[ra+va][rb+vb][vc] == vis[ua][ub][uc]+1) {
                    cnt[ra+va][rb+vb][vc] = (cnt[ra+va][rb+vb][vc] + cnt[ua][ub][uc] * (comb[ua][va]*comb[ub][vb])%MOD) % MOD;
                }
            }
        }
    }
    printf("%d\n%I64d\n", vis[a][b][1], cnt[a][b][1]);
}
