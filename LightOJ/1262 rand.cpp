#include<bits/stdc++.h>
#define MXV 5
#define MXX 100
using namespace std;

int main() {
    srand(time(NULL));
    freopen("1262i.txt", "w", stdout);

    int T = 20;
    cout << T << endl << endl;
    while(T--) {
        int n = rand()%MXV+1, m = rand()%MXV+1;
        int grid[MXV][MXV];
        cout << n << ' ' << m << endl;
        for(int i=0; i<n+m-1; i++) cout << rand()%MXX + 1 << ' '; cout << endl;
        for(int i=0; i<n+m-1; i++) cout << rand()%MXX + 1 << ' '; cout << endl;
        cout << endl;
    }

}
