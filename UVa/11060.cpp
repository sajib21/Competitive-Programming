#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    int n;

    while(scanf("%d", &n) != EOF)
    {
        //getchar();
        //cout << "dhukse" << endl;
        if(t > 1) cout << endl;

        int m;
        string s[110], s1,s2;
        map<string,int> mp;
        vector<int>graph[110];
        vector<int>ans(110);
        queue<int>emptyNode;
        int degree[110]= {0};

        //cin >> n;
        for(int i=1; i<=n; i++)
        {
            cin >> s[i];
            mp[s[i]] = i;
        }
        //cout << "no bug" << endl;
        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> s1 >> s2;
            graph[mp[s1]].push_back(mp[s2]);
            degree[mp[s2]]++;
        }

        cout << "Case #" << t++ << ": Dilbert should drink beverages in this order:";

        ans.push_back(0);
        for(int i=1; i<=n; i++)
        {
            if(!degree[i]) {

                emptyNode.push(i);

            }


            while(!emptyNode.empty())
            {
                int top = emptyNode.front();
                emptyNode.pop();

                cout << ' ' << s[top];
                //if(!degree[top]) ans.insert(ans.begin()+top, top);
                //else ans.push_back(top);


                for(int i=0; i<graph[top].size(); i++)
                {
                    degree[ graph[top][i] ]--;
                    //if(!degree[ graph[top][i] ]) emptyNode.push(graph[top][i]);
                }
            }
        }

        //for(int i=1; i<ans.size(); i++) cout << ' ' << s[ans[i]];

        cout << '.' << endl;

    }

    return 0;
}
