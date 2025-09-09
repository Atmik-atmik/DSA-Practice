#include <bits/stdc++.h>
using namespace std;

// Example: Find maximum element in an array
int findMax(vector<int>& arr) {
    int maxi = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

