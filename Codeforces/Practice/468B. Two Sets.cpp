#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define LIM 200005

using namespace std;

int n,a,b, v[LIM];
map<int,int>ase;
int ok[LIM], ans[LIM];

int main() {
    scanf("%d %d %d", &n,&a,&b);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        ase[ v[i] ] = i;
    }

    for(int i=1; i<=n; i++) {
        if(ok[i]) continue;

        if(ase.find(a-v[i]) != ase.end() && ase.find(b-v[i]) != ase.end()) {
//            cout << i << " ONE " << endl;
            ///A te handanor try kori
            if(ase.find(a-b+v[i]) != ase.end()) {
                ans[i] = ans[ ase[ a-v[i] ] ] = ans[ ase[ b-v[i] ] ] = ans[ ase[ a-b+v[i] ] ] = 0;
                ok[i] = ok[ ase[ a-v[i] ] ] = ok[ ase[ b-v[i] ] ] = ok[ ase[ a-b+v[i] ] ] = 1;
            }
            else if(ase.find(b-a+v[i]) != ase.end()) {
                ans[i] = ans[ ase[ a-v[i] ] ] = ans[ ase[ b-v[i] ] ] = ans[ ase[ b-a+v[i] ] ] = 1;
                ok[i] = ok[ ase[ a-v[i] ] ] = ok[ ase[ b-v[i] ] ] = ok[ ase[ b-a+v[i] ] ] = 1;
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
        else if(ase.find(a-v[i]) != ase.end()) {
            ans[i] = ans[ ase[ a-v[i] ] ] = 0;
            ok[i] = ok[ ase[ a-v[i] ] ] = 1;
        }
        else if(ase.find(b-v[i]) != ase.end()) {
//            cout << i << " TWO" << endl;
            ans[i] = ans[ ase[ b-v[i] ] ] = 1;
            ok[i] = ok[ ase[ b-v[i] ] ] = 1;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for(int i=1; i<=n; i++) printf("%d ", ans[i]);

}
