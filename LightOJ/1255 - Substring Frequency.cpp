#include<bits/stdc++.h>

using namespace std;

//string text, pattern;
char text[1000006], pattern[1000006];
int textSize, patternSize;
int prefix[4000006], ans;

void generatePrefix() {

    prefix[0] = -1;
    for(int a=-1, b=1; b<patternSize; b++) {

        while(a >= 0 && pattern[a+1] != pattern[b]) {
            if(a > prefix[a]) a = prefix[a];
            else a = -1;
        }
        if(pattern[a+1] == pattern[b]) a++;
        prefix[b] = a + 1;
    }
    prefix[0] = 0;

//    for(int i=0; i<patternSize; i++) cout << prefix[i] << ' ';
//    cout << endl;
}

int matchingChecker() {

    ans = 0;
    int i=0,j=0,k=0;

    while(i < textSize) {

        if(j <= -1) {
            k = ++i;
            j = 0;
        }
        while(text[i] == pattern[j]) i++, j++;
        if(j >= patternSize) ans++;
        if(j <= 0) {
            if(i != k) k = i ;
            else i++, k++;
            j = 0;
        }
        else if(prefix[j-1] != -1) {
            if(i - prefix[j-1] != k) k = i - prefix[j-1];
            else i++, k++;
            j = prefix[j-1];
        }
        else {
            j = 0;
            k = i;
        }
    }
//    cout << "ans = " << ans << endl;
    return ans;
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

//        cin >> text;
//        cin >> pattern;
        scanf("%s", text);
        scanf("%s", pattern);
        textSize = strlen(text);
        patternSize = strlen(pattern);

//        cout << textSize << ' ' << patternSize << endl;
//        printf("%s\n", text);

        generatePrefix();
        printf("Case %d: %d\n", t, matchingChecker());
    }
}
