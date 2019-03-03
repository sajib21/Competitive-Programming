#include<bits/stdc++.h>
#define pb push_back

using namespace std;

#define INF INT_MAX
#define EPS 1e-9
#define LIM 100

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int n, go[LIM+10];
vector< vector<double> > co;
vector<double>temp(LIM+1);
vector<double>ans;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
//        memset(go, 0, sizeof(go));
        co.clear();
        ans.clear();
        scanf("%d", &n);
        for(int i=0; i<LIM; i++) go[i] = i;
        for(int i=0; i<n; i++) {
            int u,v;
            scanf("%d %d", &u,&v);
            u--; v--;
            go[u] = v;
        }

        for(int tm=0; tm<LIM-1; tm++) {
            for(int i=0; i<=LIM; i++) temp[i] = 0;
            if(go[tm] != tm) {
//                temp[tm] = 1;
                co.pb(temp);
                continue;
            }
            temp[tm] = 6;
            for(int i=1; i<=6; i++) {
                int nw = tm+i;
                if(nw >= LIM) nw = tm;
                temp[ go[nw] ]--;
            }
            temp[LIM] = 6;
            co.pb(temp);
//            for(int i=0; i<temp.size(); i++) cout << temp[i] << ' '; cout << endl;
        }
        for(int i=0; i<=LIM; i++) temp[i] = 0;
        temp[LIM-1] = 1;
        co.pb(temp);

//        cout << "FINALLY" << endl;
//        for(int i=0; i<co.size(); i++) {
////            vector<double> tt = co[i];
//            for(int j=0; j<co[i].size(); j++) cout << co[i][j] << ' ';
//            cout << endl;
//        }

        gauss(co, ans);
//        for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ' ; cout << endl;
        printf("Case %d: %.10lf\n", t, ans[0]);
    }
    return 0;
}
