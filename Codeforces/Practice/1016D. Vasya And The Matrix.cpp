#include<bits/stdc++.h>
#define vi vector<int>
#define pb(x) push_back(x)

using namespace std;

int n,m, a[110], b[110], id[110][110];
vector< vi > co;

vi gauss() {
    vi ff,ss;
    int row = co.size(), col = co[0].size();
    int r,c;
    for(r=0, c=0; c<col-1 && r<row; c++) {
        int cur = r;
        for(int i=r; i<row; i++) if(co[i][c] > co[cur][c]) {
            cur = i;
        }
        if(!co[cur][c]) continue;
        if(cur != r) {
            swap(co[cur], co[r]);
            ff.pb(cur); ss.pb(r);
        }

        for(int i=0; i<row; i++) if(i != r && co[i][c]) {
            for(int j=c; j<col-1; j++) co[i][j] ^= co[r][j];
        }
        r++;
    }
    vi ans;
    for(int i=0; i<min(r,c); i++) ans.pb(co[i].back());

//    for(int i=ff.size()-1; i>=0; i--) {
//        swap(ans[ ff[i] ], ans[ ss[i] ]);
//    }

    while(ans.size() < n*m) ans.pb(0);

    return ans;
}

int main() {
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);

    vi temp;
    for(int j=0; j<=n*m; j++) temp.pb(0);
    for(int i=0; i<n+m; i++) {
        co.pb(temp);
    }

    int in=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            id[i][j] = in++;
        }
    }

//    cout << co.size() << ' ' << co[0].size() << ' ' << in << endl;
//
//    assert(co.size() == n+m);
//    assert(co[0].size() == n*m+1);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) co[i][ id[i][j] ] = 1;
        co[i][n*m] = a[i];
    } //cout << "BUG";
    for(int j=0; j<m; j++) {
//        cout << "BUG " << j << ' ' << id[i]
        for(int i=0; i<n; i++) {
//            cout << "BUG " << j << ' ' << i << ' ' << id[i][j] << endl;
            co[n+j][ id[i][j] ] = 1;
        }
        co[n+j][n*m] = b[j];

    }

    cout << "MAT" << endl;
    for(int i=0; i<co.size(); i++) {
        for(int j=0; j<co[0].size(); j++) cout << co[i][j] << ' ';
        cout << endl;
    }

    vi sol = gauss();

    cout << "MAT" << endl;
    for(int i=0; i<co.size(); i++) {
        for(int j=0; j<co[0].size(); j++) cout << co[i][j] << ' ';
        cout << endl;
    }


    for(int i=0; i<sol.size(); i++) {
        if(i && i%m==0) printf("\n");
        printf("%d ", sol[i]);
    }


    return 0;
}

/*
0010
0011
0101
*/
