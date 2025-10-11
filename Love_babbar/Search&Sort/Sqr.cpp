#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sqrtx/

class Solution {
public:

//The integer square root is the largest number whose square does not exceed x.
    int mySqrt(int x) {
        if (x == 0) return 0; // edge case

        int s = 1, e = x;
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (mid == x / mid) // exact square root
                return mid;
            else if (mid > x / mid) // mid*mid > x
                e = mid - 1;
            else {
                ans = mid; // mid*mid < x
                s = mid + 1;
            }
        }

        return ans; 
    }
};
