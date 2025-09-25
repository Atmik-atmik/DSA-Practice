#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[mat[0][i]] = 1;
    }

    //search for element which is present in all previously visited rows

    for(int i=1;i<m;i++){
        unordered_set<int>seen;

        for(int j=0;j<n;j++){
            int val = mat[i][j];
            if(mp[val] == i && mp.find(val) != mp.end()){
                mp[val]= i+1;
                seen.insert(val);
            }
        }
    }

    vector<int> result;
    //take all element from map whose value is = to m

    for(auto &p:mp){
        if(p.second == m) result.push_back(p.first);
    }

    return result;
}
