#include<bits/stdc++.h>

using namespace std;

int n,q, num,sz;
char str[10];

int main() {
    while(scanf("%s %d", &str,&q) ) {
        if(!strcmp(str, "0") && !q) return 0;
        num = 0; sz = strlen(str);

        if(str[0] == '0') {
            if(str[1] == 'x') {
                for(int i=2; i<sz; i++) {
                    if(str[i] >= '0' && str[i] <= '9') num = num*16 + str[i]-'0';
                    else num = num*16 + str[i]-'A'+10;
                }
            }
            else for(int i=1; i<sz; i++) num = num*8 + str[i]-'0';
        }
        else for(int i=0; i<sz; i++) num = num*10 + str[i]-'0';

        int ans = 0;
        while(q--) {
            scanf("%s %d", &str, &n);
            if(!strcmp(str, "i++")) {
                if(n == num) ans++;
                else num = n;
                num++;
            }
            else if(!strcmp(str, "++i")) {
                num++;
                if(n == num) ans++;
                else num = n;
            }
            else if(!strcmp(str, "i--")) {
                if(n == num) ans++;
                else num = n;
                num--;
            }
            else if(!strcmp(str, "--i")) {
                num--;
                if(n == num) ans++;
                else num = n;
            }
            else {
                if(n == num) ans++;
                else num = n;
            }
        }
        printf("%d\n", ans);
    }
}
