#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define pb(x) push_back(x)

using namespace std;

int n;
ll ara[110];
vector< vii > co;

void printMat() {
    cout << "MAT " << endl;
    for(int i=0; i<co.size(); i++) {
        for(int j=0; j<co[0].size(); j++) {
            printf("%5d ", co[i][j]);
        }
        cout << endl;
    }
}

ll gauss() {
    int row = co.size(), col = co[0].size();
    int r,c;
    for(r=0, c=0; c<col-1 && r<row; c++) {
        int cur = r;
        for(int i=r; i<row; i++) if(co[i][c] > co[cur][c]) {
            cur = i;
        }
        if(!co[cur][c]) continue;
        if(cur != r) swap(co[cur], co[r]);

        for(int i=0; i<row; i++) if(i != r && co[i][c]) {
            for(int j=c; j<col-1; j++) co[i][j] ^= co[r][j];
        }
        r++;

        cout << "AFTER " << r-1 << endl;
        printMat(); getchar();
    }
    printMat();

    bool ff = false;
    for(int i=0; i<r; i++) {
        if(ff) printf(" ");
        ff = true;
        printf("%d", co[i].back());
    }

}

int main() {
    scanf("%d", &n);



    for(int i=0; i<n; i++) {
        vii temp;
        for(int j=0; j<n; j++) temp.pb(0);
        int x;
        while(scanf("%d", &x) && x != -1) {
            x--;
            temp[x] = 1;
        }
        temp.pb(i);
        co.pb(temp);
    }

    printMat();
    gauss();
//    gauss();
}
