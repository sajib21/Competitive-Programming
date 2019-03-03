#include<bits/stdc++.h>

using namespace std;

int n; char str1[120], str2[120];
int con[500];
vector<char> res;;
string a,b;

int main() {
    for(int t=1; ; t++) {
        scanf("%d", &n);
        if(!n) return 0;

        memset(con, -1, sizeof con);

        bool f = true;
        while(n--) {
            scanf("%s %s", str1, str2);
//            getline(str2);
            a = str1; b = str2;
//            getline(cin, b);


            if(a.size() < b.size()) f = false;
            if(!f) continue;

            int i = 1, j = 1;
            while(f && i<a.size()-1 && i<b.size()-1) {
                if(a[i] != b[i]) {
                    f = false;
                    break;
                }
                if(con[ a[i] ] == 0) {
                    f = false;
                    break;
                }
                con[ a[i] ] = 1;
                i++;
            }
            if(!f) continue;

            if(i < a.size()) {
                if(con[ a[i] ] == 1) {
                    f = false;
                    break;
                }
                con[ a[i] ] = 0;
            }
        }
        if(!f) printf("Case %d: I_AM_UNDONE\n", t);
        else {

            res.clear();
            for(int i='0'; i<='9'; i++) if(con[ i ] != 0) res.push_back(i);
            for(int i='A'; i<='Z'; i++) if(con[ i ] != 0) res.push_back(i);
            for(int i='a'; i<='z'; i++) if(con[ i ] != 0) res.push_back(i);
            while(res.size() > 1 && con[ res.back() ] == -1 ) res.pop_back();

            if(res.empty()) {
                printf("Case %d: I_AM_UNDONE\n", t);
                continue;
            }
            printf("Case %d: [", t);
            for(int i=0; i<res.size(); i++) printf("%c", res[i]);
            printf("]\n");
        }
    }
}
