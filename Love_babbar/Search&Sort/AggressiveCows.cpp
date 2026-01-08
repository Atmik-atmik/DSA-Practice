#include <bits/stdc++.h>
using namespace std;

// https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM

bool ispossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastpos = stalls[0];

    for(int i=0; i<stalls.size(); i++){
        if(stalls[i]- lastpos >=mid){       
            cowCount ++;

            if (cowCount == k) {  // there is no need to put lastpos for k, without it still task is completed
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{   
    sort(stalls.begin(),stalls.end());

    int s= 0;
    int maxi = -1;
    for(int i=0;i<stalls.size(); i++){
        maxi= max(maxi,stalls[i]);
    }
    int e= maxi;
    int ans =-1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(ispossible(stalls,k, mid)){
            ans = mid;
            s= mid+1;
        }
        else{
            e = mid-1;
        }    
    }
    return ans; 
}   