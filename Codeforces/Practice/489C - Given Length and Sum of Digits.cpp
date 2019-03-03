#include<bits/stdc++.h>

using namespace std;

int main() {

    int m,s;
    vector<char> num, num2;
    scanf("%d %d", &m, &s);

    if(!s && m==1) {
        printf("0 0\n");
        return 0;
    }


    if(!s || s > m*9) {
        printf("-1 -1\n");
        return 0;
    }

    int nines = s/9;
    for(int i=0; i<nines; i++) num.push_back('9'), m--;
    int ex = s%9;
    if(ex) num.push_back(ex+'0'), m--;
    for(int i=0; i<m; i++) num.push_back('0');

    num2 = num;
    int sz = num.size();

    reverse(num2.begin(), num2.end());
    if(num2[0] == '0') {
        int k;
        for(k=0; k<sz && num2[k] == '0'; k++);
        num2[k]--;
        num2[0]++;
    }
    for(int i=0; i<sz; i++) printf("%c", num2[i]);
    printf(" ");


    for(int i=0; i<sz; i++) printf("%c", num[i]);
    printf("\n");

    return 0;
}
