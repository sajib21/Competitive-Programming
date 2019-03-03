#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

char str[LIM];
string seq;
int type[LIM], first[LIM], last[LIM];

bool open(char c) {
    return c == '(' || c == '{' || c == '[' || c == '<';
}
bool match(int a, int b) {
    a = seq[a]; b = seq[b];
    return (a == '(' && b == ')') || (a == '{' && b == '}') ||
    (a == '[' && b == ']') || (a == '<' && b == '>');
}

int main() {
//    freopen("13272o.txt", "w", stdout);

    int T;
    scanf("%d", &T); getchar();

    for(int t=1; t<=T; t++) {
//        scanf("%s", str);
        gets(str);
        seq = str;

        memset(type, 0, sizeof type);
//        memset(first, 0, sizeof)

        stack<int>stk;

        for(int i=0; i<seq.size(); i++) {
            if(open(seq[i])) {
                stk.push(i);

            }
            else {
                if(stk.empty()) {
                    type[i] = 3;
                    continue;
                }

                int j = stk.top(); stk.pop();
                if(match(j, i)) {
                    last[j] = i; first[i] = j;
                    type[j] = 1; type[i] = 2;
                }
                else {
                    type[i] = 3; type[j] = 3;
                    while(!stk.empty()) {
                        j = stk.top(); stk.pop();
                        type[j] = 3;
                    }
                }
            }
        }

        while(!stk.empty()) {
            int i = stk.top(); stk.pop();
            type[i] = 3;
        }

        for(int i=seq.size()-2; i>=0; i--) {
            if(type[i] == 2 && type[i+1] == 1) {
                last[ first[i] ] = last[i+1];
            }
        }

        printf("Case %d:\n", t);
        for(int i=0; i<seq.size(); i++) {
            if(type[i] == 1) printf("%d\n", last[i]-i+1);
            else printf("0\n");
        }
    }

    return 0;
}
