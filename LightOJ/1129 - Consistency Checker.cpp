#include<bits/stdc++.h>

using namespace std;

struct node {
    bool endPoint;
    node *next[11];
    node() {
        endPoint = false;
        for(int i=0; i<=9; i++) next[i] = NULL;
    }
};

node *root;

bool insNum(string str) {
    int sz = str.size();
    node *cur = root;
    for(int i=0; i<sz; i++) {
        int c = str[i] - '0';
        if(cur->next[c] == NULL) cur->next[c] = new node();
        else if(cur->next[c]->endPoint) return false;
        cur = cur->next[c];
    }
    cur->endPoint = true;

    return true;
}

void deleteTrie(node *cur) {

    for(int i=0; i<10; i++) {
        if(cur->next[i] != NULL) {
            deleteTrie(cur->next[i]);
        }
    }
    delete(cur);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        root = new node();

        int n;
        string str[10004];
        bool flag = true;
        cin >> n;
        for(int i=0; i<n; i++) cin >> str[i];
        sort(str, str+n);


        for(int i=0; i<n; i++) {
//            string str;
//            cin >> str;
            if(insNum(str[i]) == false) {
//                cout << "NO" << endl;
                flag = false;
//                break;
            }
        }
        if(flag) cout << "Case " << t << ": YES" << endl;
        else cout << "Case " << t << ": NO" << endl;
        deleteTrie(root);
    }

    return 0;
}
