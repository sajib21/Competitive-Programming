#include<bits/stdc++.h>

using namespace std;

int main() {

    string seq;
    cin >> seq;

    int sz = seq.size();

    list<int>lst;
    //lst.push_back(1);
    lst.insert(lst.begin(), 1);

    std::list<int>::iterator it;
    it = lst.begin();

    int szz = sz-1;
    for(int i=0, p = 2; i<szz; i++, p++ ) {
        if(seq[i] == 'l') {
            lst.insert(it, p);
            --it;
        }
        else {
            it++;
            lst.insert(it, p);
            it--;
        }
//        for (it=lst.begin(); it!=lst.end(); ++it) cout << ' ' << *it ;
//        cout << endl;
    }


    //std::cout << "mylist contains:";
    for (it=lst.begin(); it!=lst.end(); ++it) cout << *it << endl;
    //std::cout << '\n';

    //for(int i=0; i<sz; i++) cout << lst[i] << endl;

    return 0;
}
