#include<bits/stdc++.h>
#define LIM 70000

using namespace std;

int n, a[LIM];
map<int,int>koyta[12];

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);

        int d = 1, x;
        for(int sz=1; sz<=9; sz++) {
            d *= 10; x = a[i];
            set<int>ase;
            for(int j=0; j<=9-sz; j++) {
//                cout << "INS " << sz << ' ' << x%d << endl;
                ase.insert(x%d);
                x /= 10;
            }
            for(auto p : ase) koyta[sz][p]++;
        }
    }

//    for(int sz=1; sz<=9; sz++) {
//        cout << sz << " : " << endl;
//        for(auto it : koyta[sz]) cout << it.first << ' ' << it.second << endl;
//        cout << endl;
//    }

    for(int i=0; i<n; i++) {
//        cout << "TEST : " << i << ' ' << a[i] << endl;
        int d = 1, x = a[i];
        bool f = true;
        for(int sz=1; f && sz<=9; sz++) {
            d *= 10; x = a[i];
            for(int j=0; f && j<=9-sz; j++) {
//                cout << sz << ' ' << x%d << ' ' << koyta[sz][x%d] << endl;
//                getchar();
                if(koyta[sz][ x%d ] == 1) {
                    int ans = x%d;
                    stack<int>stk;
                    while(ans) {
                        stk.push(ans%10);
                        ans /= 10;
                    }
                    while(stk.size() < sz) stk.push(0);
                    while(!stk.empty()) {
                        printf("%d", stk.top());
                        stk.pop();
                    }
                    printf("\n");
                    f = false;
                }
                x /= 10;
            }
        }
    }

}
