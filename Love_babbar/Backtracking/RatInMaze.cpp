#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  //Formal way:
// “One word comes before another in lexicographic order if, at the first position where they differ, the letter (or number) in the first word is smaller than the one in the second word.”

// Simple way (like dictionary):
// “A word comes before another if it would appear earlier in a dictionary. That means we compare them letter by letter until we find a difference; the one with the smaller letter at that position comes first.”
  
    bool isSafe(int x, int y,vector<vector<int>>&visited,vector<vector<int>>& maze,int n){
        return ((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] ==-1)&& (maze[x][y] == 1));
    }
    
    void solve(int x,int y, vector<vector<int>>&visited,vector<vector<int>>& maze,
    vector<string>&result,string path,int &n){
        if(x == n-1 && y== n-1){
            result.push_back(path);
            return;
        }
        
        visited[x][y] = 2;
        
        //up
        int new_x = x-1, new_y= y;
        if(isSafe(new_x,new_y,visited,maze,n)){
            solve(new_x,new_y,visited,maze,result,path+'U',n);
        }
        
        //down
        new_x = x+1, new_y= y;
        if(isSafe(new_x,new_y,visited,maze,n)){
            solve(new_x,new_y,visited,maze,result,path+'D',n);
        }
        //left
        new_x = x, new_y= y-1;
        if(isSafe(new_x,new_y,visited,maze,n)){
            solve(new_x,new_y,visited,maze,result,path+'L',n);
        }
        
        //right
        new_x = x, new_y= y+1;
        if(isSafe(new_x,new_y,visited,maze,n)){
            solve(new_x,new_y,visited,maze,result,path+'R',n);
        }
        
        visited[x][y] =-1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>result;
        if(maze[0][0] == 0) return result;
        int n= maze.size();
        vector<vector<int>>visited(n,vector<int>(n,-1));
        
        string path ="";
        
        solve(0,0,visited,maze ,result,path,n);
        
        sort(result.begin(),result.end());
        return result;
        
    }
};