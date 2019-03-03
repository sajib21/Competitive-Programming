#include<bits/stdc++.h>
#define LIM 50000

using namespace std;

struct node {
    int cnt;
    bool endPoint;
    node *next[5];

    node() {
        cnt = 0;
        endPoint = false;
        for(int i=0; i<5; i++) next[i] = NULL;
    }
};

int n;
string dna[LIM+10];
node *root;

int addString(string str) {
    int sz = str.size();
    int ans = 0;
    node *temp = root;
    for(int i=0; i<sz; i++) {
        int go;
        if(str[i] == 'A') go = 0; else if(str[i] == 'C') go = 1; else if(str[i] == 'G') go = 2; else go = 3;
        if(temp->next[go] == NULL) temp->next[go] = new node();
        temp->next[go]->cnt++;
        ans = max(ans, temp->next[go]->cnt * (i+1));

        temp = temp->next[go];
    }
    temp->endPoint = true;
    return ans;
}

void deleteTrie(node *trie) {
    for(int i=0; i<5; i++) if(trie->next[i]) deleteTrie(trie->next[i]);
    delete(trie);
}

int main() {

    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {

        root = new node();
        scanf("%d", &n);
        for(int i=0; i<n; i++) cin >> dna[i];
        sort(dna, dna+n);

        int ans = 0;
        for(int i=0; i<n; i++) ans = max(ans, addString(dna[i]));
        printf("Case %d: %d\n", t, ans);

        deleteTrie(root);
    }

    return 0;

}
