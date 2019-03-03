#include<bits/stdc++.h>
#define LIM 500005

using namespace std;

int n,m, p;
string seq, cmd;
int nxt[LIM], pre[LIM], op[LIM];

int main() {
    scanf("%d %d %d", &n,&m, &p);
    cin >> seq;
    cin >> cmd;

    seq = "0" + seq;

    stack<int>stk;

    for(int i=0; i<=n; i++) nxt[i] = i+1, pre[i] = i-1;

    for(int i=1; i<=n; i++) {
        if(seq[i] == '(') {
            stk.push(i);
        }
        else {
            int j = stk.top(); stk.pop();
            op[i] = j; op[j] = i;
        }
    }

    for(int i=0; i<m; i++) {
        if(cmd[i] == 'L') {
            p = pre[p];
        }
        else if(cmd[i] == 'R') {
            p = nxt[p];
        }
        else {
            int q = op[p];
//            cout << p << ' ' << pre[p] << ' ' << nxt[p] << ' ' << q << ' ' << pre[q] << ' ' << nxt[q] << endl;
            if(q < p) {
                pre[ nxt[p] ] = pre[q];
                nxt[ pre[q] ] = nxt[p];
                p = nxt[p];
            }
            else {
                pre[ nxt[q] ] = pre[p];
                nxt[ pre[p] ] = nxt[q];
                p = nxt[q];
            }


            if(p == n+1) p = pre[p];
        }
//        cout << i << ' ' << p << endl;
    }

//cout << "BIG" << endl;

    while(pre[p] != 0) p = pre[p];

    while(p != n+1) {
//        cout << p << ' ' ;
        printf("%c", seq[p]);
        p = nxt[p];
    }
}
