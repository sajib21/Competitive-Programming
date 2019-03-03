#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        string num, kp;
        cin >> num;
        kp = num;
        reverse(kp.begin(), kp.end());

        int sz = num.size();
        int md = (sz)/2;

        int a = 0, it = 0;
        while(it<sz) {
            if(num[it] == '9') a++;
            it++;
        }
        if(a == sz) {
            num = "1";
            while(a-- > 1) num += '0';
            num += '1';
//            printf("Case %d: ",t);
            cout << num << endl;
            continue;
        }

        else if(kp == num) {
            int m1 = (sz-1)/2 , m2 = (sz)/2;
            while(m2 < sz) {
                if(num[m1] < '9') {
                    num[m1]++;
                    if(m1 != m2) num[m2]++;
                    break;
                }
                else {
                    num[m1] = '0';
                    num[m2] = '0';
                    m1--; m2++;
                }
            }
//            printf("Case %d: ", t);
            cout << num << endl;
            continue;
        }
        int i=0, j = num.size() - 1;
        bool big = false;
        sz = num.size();
        while(i < sz) {
            if(big) {
                if(num[j] < '9') {
                    num[j]++;
                    big = false;
                }
                else num[j] = '0';
            }
            if(i < j) {
                if(num[i] < num[j]) big = true;
                else if(num[i] > num[j]) {
                    char tmp = max(num[i], num[j]);
                    num[i] = num[j] = tmp;
                }
            }
            else num[i] = num[j];
            i++; j--;
        }
//        printf("Case %d: ", t);
        cout << num << endl;
    }
    return 0;

}
