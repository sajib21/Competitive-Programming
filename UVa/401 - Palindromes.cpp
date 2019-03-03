#include<bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;

    while(cin >> s2) {

        bool pal = false, mir = false, f=false;
        //string s1, s2;
        //cin >> s2;
        s1 = s2;
        reverse(s2.begin(), s2.end());

        if( !s1.compare(s2) ) {
            pal = true;
        }

        int sz = s2.size();
        for(int i=0; i<sz; i++) {
            if(s2[i] == 'E') s2[i] = '3';
            else if(s2[i] == 'J') s2[i] = 'L';
            else if(s2[i] == 'L') s2[i] = 'J';
            else if(s2[i] == 'S') s2[i] = '2';
            else if(s2[i] == 'Z') s2[i] = '5';
            else if(s2[i] == '2') s2[i] = 'S';
            else if(s2[i] == '3') s2[i] = 'E';
            else if(s2[i] == '5') s2[i] = 'Z';
            else if(s2[i] == 'B' || s2[i] == 'C' || s2[i] == 'D' || s2[i] == 'F' || s2[i] == 'G' || s2[i] == 'K' || s2[i] == 'N' || s2[i] == 'P' ||
                    s2[i] == 'Q' || s2[i] == 'R' || s2[i] == '4' || s2[i] == '6' || s2[i] == '7' || s2[i] == '9' ) {
                        mir = false;
                        f = true;
                        break;
                    }
        }
        if(!f) {
            if(s1.compare(s2) == 0) {
                mir = true;
            }
        }

        if(pal && mir) {
            printf("%s -- is a mirrored palindrome.\n", s1.c_str() );
        }
        else if(pal) {
            printf("%s -- is a regular palindrome.\n", s1.c_str());
        }
        else if(mir) {
            printf("%s -- is a mirrored string.\n", s1.c_str());
        }
        else {
            printf("%s -- is not a palindrome.\n", s1.c_str());
        }

        printf("\n");

    }

    return 0;
}
