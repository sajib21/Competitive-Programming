#include<bits/stdc++.h>
#define LIM 1010

using namespace std;

int n, a[LIM], b[LIM];

int main() {
    while(scanf("%d", &n) && n) {
        while(scanf("%d", &a[0])) {
            if(!a[0]) {
                printf("\n");
                break;
            }
            for(int i=1; i<n; i++) scanf("%d", &a[i]);
//            for(int i=0; i<n; i++) printf("%d ", a[i]);

            stack<int>stk;

            for(int i=1, j=0; i<=n; i++) {
//                if(!stk.empty()) cout << "PUSHING " << i << " ON " << stk.top() << endl; getchar();
                stk.push(i);
                while(!stk.empty() && stk.top() == a[j]) {
                    stk.pop();
                    j++;
                }
            }
            if(stk.empty()) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
