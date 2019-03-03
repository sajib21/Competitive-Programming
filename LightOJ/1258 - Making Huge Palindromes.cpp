#include<bits/stdc++.h>

using namespace std;

char str[1000006], dup[2000006];
int strSize, dupSize;
int prefix[2000006], ans;

int genPrefix() {

    prefix[0] = -1;
    for(int i=-1, j=1; j<dupSize; j++) {
        while(i >= 0 && dup[i+1] != dup[j]) {
            if(i > prefix[i]) i = prefix[i];
            else i = -1;
        }
        if(dup[i+1] == dup[j]) i++;
        prefix[j] = i;
    }
//    prefix[0] = 0;
    for(int i=0; i<dupSize; i++) prefix[i]++;

//    for(int i=0; i<dupSize; i++) cout << prefix[i] << ' ';
//    cout << endl;

//    cout << prefix[dupSize-1] << endl;
    if(prefix[dupSize-1] > strSize) return prefix[dupSize-1] - strSize + 1;
    else return prefix[dupSize-1];
}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        scanf("%s", str);
        strSize = strlen(str);
        for(int i=0; i<strSize; i++) dup[strSize-i-1] = str[i];
        for(int i=0, j=strSize; i<strSize; i++, j++) dup[j] = str[i];
        dup[2*strSize] = 0;
        dupSize = 2*strSize;

//        printf("%s\n", dup);
//        cout << strSize << ' ' << dupSize << endl;

        int ans = genPrefix();
        printf("Case %d: %d\n", t, 2*strSize-ans);
    }
    return 0;
}
