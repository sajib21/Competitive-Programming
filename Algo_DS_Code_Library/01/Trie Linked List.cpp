#include<bits/stdc++.h>

using namespace std;

struct node {
    bool endPoint;
    node *next[30];

    node() {
        endPoint = false;
        for(int i=0; i<30; i++) next[i] = NULL;
    }


};
node *root;

void insertObject(string str) {
    int sz = str.size();
    node *cur = root;

    for(int i=0; i<sz; i++) {
        int c = str[i] - 'a' + 1;
        if(cur->next[c] == NULL) cur->next[c] = new node();
        cur = cur->next[c];
    }

    cur->endPoint = true;
}

bool searchObject(string str) {
    int sz = str.size();
    node *cur = root;

    for(int i=0; i<sz; i++) {
        int c = str[i] - 'a' + 1;
        if(cur->next[c] == NULL) return false;
        cur = cur->next[c];
    }
    return cur->endPoint;
}

void deleteObject(node *cur) {

    for(int i=0; i<30; i++) {
        if(cur->next[i]) {
            deleteObject(cur->next[i]);
        }
    }
    delete(cur);
}

int main() {

    node *root = new node();

}
