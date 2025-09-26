#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        return a.second <b.second;
    }
    
    int activitySelection(vector<int> &start, vector<int> &finish) {
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<start.size();i++){
            pair<int,int> p = make_pair(start[i],finish[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int cnt = 1;
        int ansEnd = v[0].second;
        
        for(int i=1;i<start.size();i++){
            if(v[i].first>ansEnd){
                cnt++;
                ansEnd = v[i].second;
            }
        }
        
        return cnt;
        
    }
};